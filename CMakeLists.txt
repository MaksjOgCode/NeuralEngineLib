cmake_minimum_required ( VERSION 3.28 )

project (
    NeuralEngineLib
    VERSION 4.0.0
    DESCRIPTION "A library for performing basic mathematical operations. The component responsible for performing calculations (with the possibility of enabling GPU support). Utilities such as logging, diagnostics, and auxiliary functions (with the option to enable logging)."
    HOMEPAGE_URL "https://github.com/MaksjOgCode/NeuralEngineLib"
    LANGUAGES CXX
)

include ( GNUInstallDirs )

# NEURAL ENGINE LIB ENVIRONMENT:
set ( NEL_PATH_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include" )
set ( NEL_ULTIMATE_PATH_INCLUDE "" )
list (
    APPEND NEL_ULTIMATE_PATH_INCLUDE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_backend"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_core"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_utils"
)

# ----- COMPONENT: Full Library -----
add_library ( NeuralEngineLib INTERFACE )
foreach ( component IN LISTS NEL_ULTIMATE_PATH_INCLUDE )
    target_include_directories (
    NeuralEngineLib INTERFACE
    $<BUILD_INTERFACE:${component}>
    $<INSTALL_INTERFACE:${component}>
)
endforeach ()
add_library ( NeuralEngineLib::NeuralEngineLib ALIAS NeuralEngineLib )

# ----- COMPONENT: Backend -----
add_library ( NeuralEngineLib_Backend INTERFACE )
target_include_directories (
    NeuralEngineLib_Backend INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_backend>
    $<INSTALL_INTERFACE:include/include_backend>
)
add_library ( NeuralEngineLib::Backend ALIAS NeuralEngineLib_Backend )

# ----- COMPONENT: Core -----
add_library ( NeuralEngineLib_Core INTERFACE )
target_include_directories (
    NeuralEngineLib_Core INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_core>
    $<INSTALL_INTERFACE:include/include_core>
)
add_library ( NeuralEngineLib::Core ALIAS NeuralEngineLib_Core )

# ----- COMPONENT: Utils -----
add_library ( NeuralEngineLib_Utils INTERFACE )
target_include_directories (
    NeuralEngineLib_Utils INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_utils>
    $<INSTALL_INTERFACE:include/include_utils>
)
add_library ( NeuralEngineLib::Utils ALIAS NeuralEngineLib_Utils )



# OPTIONS LIBRARY:
option ( NEURAL_ENGINE_ENABLE_LOGGING "The option to enable logging" OFF )
option ( NEURAL_ENGINE_USE_GPU "Option to enable GPU support" OFF )

# -DNEURAL_ENGINE_ENABLE_LOGGING
if ( NEURAL_ENGINE_ENABLE_LOGGING )
    target_compile_definitions ( NeuralEngineLib INTERFACE NEURAL_ENGINE_LOGGING=1 )
    target_compile_definitions ( NeuralEngineLib_Utils INTERFACE NEURAL_ENGINE_LOGGING=1 )
endif ()

# -DNEURAL_ENGINE_USE_GPU
target_compile_options (
    NeuralEngineLib_Backend INTERFACE
    $<$<CONFIG:Release>:$<$<NOT:$<BOOL:${NEURAL_ENGINE_USE_GPU}>>:-O3>>
)



# INSTALLING CONFIG PACKAGE:
set_target_properties(NeuralEngineLib_Core     PROPERTIES EXPORT_NAME Core)
set_target_properties(NeuralEngineLib_Backend  PROPERTIES EXPORT_NAME Backend)
set_target_properties(NeuralEngineLib_Utils    PROPERTIES EXPORT_NAME Utils)

install (
    TARGETS
        NeuralEngineLib_Backend
        NeuralEngineLib_Core
        NeuralEngineLib_Utils
    EXPORT NeuralEngineLibTargets
)

install (
    EXPORT      NeuralEngineLibTargets
    NAMESPACE   NeuralEngineLib::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralEngineLib
)

include ( CMakePackageConfigHelpers )

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/NeuralEngineLibConfigVersion.cmake"
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

configure_package_config_file (
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/NeuralEngineLibConfig.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/NeuralEngineLibConfig.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralEngineLib
)

install (
    FILES
        "${CMAKE_CURRENT_BINARY_DIR}/NeuralEngineLibConfig.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/NeuralEngineLibConfigVersion.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/NeuralEngineLib
)

install (
    DIRECTORY   ${CMAKE_CURRENT_SOURCE_DIR}/include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)



# CTEST:
option ( BUILD_TESTS "Enable build unit test" OFF )
if ( BUILD_TESTS )
    enable_testing()
    add_subdirectory ( tests )
endif ()
