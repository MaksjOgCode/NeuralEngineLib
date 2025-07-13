cmake_minimum_required ( VERSION 3.28 )

project (
    NeuralEngineLib
    VERSION 1.0.0
    DESCRIPTION "A library for performing basic mathematical operations. The component responsible for performing calculations (with the possibility of enabling GPU support). Utilities such as logging, diagnostics, and auxiliary functions (with the option to enable logging)."
    HOMEPAGE_URL "NO-LOAD"
    LANGUAGES CXX
)

# NEURAL ENGINE LIB ENVIRONMENT:
set ( NEL_PATH_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include" )
set ( NEL_ULTIMATE_PATH_INCLUDE "" )
list (
    APPEND NEL_ULTIMATE_PATH_INCLUDE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_backend"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_core"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/include_utils"
)

# CONFIGURATION <[FULL] library (headder-only)>
add_library ( NeuralEngineLib INTERFACE )
foreach ( component IN LISTS NEL_ULTIMATE_PATH_INCLUDE )
    target_include_directories (
    NeuralEngineLib INTERFACE
    $<BUILD_INTERFACE:${component}>
    $<INSTALL_INTERFACE:${component}>
)
endforeach ()
add_library ( NeuralEngineLib::NeuralEngineLib ALIAS NeuralEngineLib )

# CONFIGURATION <Component [::backend] library (headder-only)>
add_library ( NeuralEngineLib_Backend INTERFACE )
target_include_directories (
    NeuralEngineLib_Backend INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_backend>
    $<INSTALL_INTERFACE:${NEL_PATH_INCLUDE}/include_backend>
)
add_library ( NeuralEngineLib::Backend ALIAS NeuralEngineLib_Backend )

# CONFIGURATION <Component [::core] library (headder-only)>
add_library ( NeuralEngineLib_Core INTERFACE )
target_include_directories (
    NeuralEngineLib_Core INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_core>
    $<INSTALL_INTERFACE:${NEL_PATH_INCLUDE}/include_core>
)
add_library ( NeuralEngineLib::Core ALIAS NeuralEngineLib_Core )

# CONFIGURATION <Component [::utils] library (headder-only)>
add_library ( NeuralEngineLib_Utils INTERFACE )
target_include_directories (
    NeuralEngineLib_Utils INTERFACE
    $<BUILD_INTERFACE:${NEL_PATH_INCLUDE}/include_utils>
    $<INSTALL_INTERFACE:${NEL_PATH_INCLUDE}/include_utils>
)
add_library ( NeuralEngineLib::Utils ALIAS NeuralEngineLib_Utils )



# OPTIONS:
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



# CONFIGURATION <example>
add_subdirectory ( ${CMAKE_CURRENT_SOURCE_DIR}/example )