cmake_minimum_required ( VERSION 3.28 )

project (
    NeuralEngineLib_examples
    LANGUAGES CXX
)

add_executable ( example example.cpp )
target_link_libraries(example PRIVATE NeuralEngineLib::NeuralEngineLib)