if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_TESTMULT testmult)

FIND_PATH(
    TESTMULT_INCLUDE_DIRS
    NAMES testmult/api.h
    HINTS $ENV{TESTMULT_DIR}/include
        ${PC_TESTMULT_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    TESTMULT_LIBRARIES
    NAMES gnuradio-testmult
    HINTS $ENV{TESTMULT_DIR}/lib
        ${PC_TESTMULT_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/testmultTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(TESTMULT DEFAULT_MSG TESTMULT_LIBRARIES TESTMULT_INCLUDE_DIRS)
MARK_AS_ADVANCED(TESTMULT_LIBRARIES TESTMULT_INCLUDE_DIRS)
