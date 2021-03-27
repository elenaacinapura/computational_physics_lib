add_library(compphy-lib STATIC
                        integration/param_notypesafe/integrate.c
                        integration/param_typesafe/integrate.c
                        inv_sqrt/inv_sqrt.c
                        sqrt/sqrt_babylon.c
                        zeros_newton/zeros_newton.c)

target_include_directories(compphy-lib PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_options(compphy-lib PRIVATE -Wall -O3 -march=native -ffast-math)
target_link_libraries(compphy-lib m)

# Collect header files in include dir for installation
#file(GLOB_RECURSE INCLUDE_FILES "${PROJECT_SOURCE_DIR}/include/*.h")
#set_target_properties(compphy-lib PROPERTIES PUBLIC_HEADER "${INCLUDE_FILES}")

#include(GNUInstallDirs)
set(CMAKE_INSTALL_LIBDIR $ENV{HOME}/.local)
install( 
    TARGETS compphy-lib
    EXPORT CompPhyTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}/lib
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_LIBDIR}/include
)

install(
    DIRECTORY ${PROJECT_SOURCE_DIR}/include
    DESTINATION ${CMAKE_INSTALL_LIBDIR}
    FILES_MATCHING PATTERN "*.h"
)

install(
    EXPORT CompPhyTargets
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CompPhy
)

include(CMakePackageConfigHelpers)
configure_package_config_file( 
    "Config.cmake.in" 
    "CompPhyConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/CompPhy
    PATH_VARS
    CMAKE_INSTALL_LIBDIR
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/CompPhyConfigVersion.cmake
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

### Install Config and ConfigVersion files
install(
    FILES "${CMAKE_CURRENT_BINARY_DIR}/CompPhyConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/CompPhyConfigVersion.cmake"
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/CompPhy"
)