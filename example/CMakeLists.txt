cmake_minimum_required ( VERSION 3.28 )

project (
    NeuralEngineLib_examples
    LANGUAGES CXX
)

set (CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../install")
find_package ( NeuralEngineLib 3.0.0 REQUIRED COMPONENTS Core Backend Utils )

add_executable ( example example.cpp )
target_link_libraries ( example PRIVATE NeuralEngineLib::Core NeuralEngineLib::Backend NeuralEngineLib::Utils )