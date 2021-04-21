add_library(compphy-lib STATIC
                        gnuplot_i/gnuplot_i.c
                        differential_eq/numerov.c
                        differential_eq/verlet.c
                        linear_algebra/array_routines.c
                        linear_algebra/blas_wrappers.c
                        linear_algebra/lapack_wrappers.c
                        numerical_methods/integrate_notypesafe.c
                        numerical_methods/integrate_typesafe.c
                        numerical_methods/inv_sqrt.c
                        numerical_methods/minimum.c
                        numerical_methods/sqrt_babylon.c
                        numerical_methods/zero_bisection.c
                        numerical_methods/zero_newton.c
                        physics/polar.c
                        physics/lennard_jones.c
                        print_routines/print_routines.c
)

target_include_directories(compphy-lib PUBLIC
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)
target_compile_options(compphy-lib PRIVATE -Wall -O3 -march=native -ffast-math -std=c11)
target_link_libraries(compphy-lib m openblas lapack)

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