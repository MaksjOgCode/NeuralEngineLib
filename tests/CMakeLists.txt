cmake_minimum_required ( VERSION 3.28 )

project (
    NeuralEngineLib_tests
    LANGUAGES CXX
)

include ( FetchContent )
FetchContent_Declare (
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)
FetchContent_MakeAvailable ( googletest )

include ( ${CMAKE_SOURCE_DIR}/cmake/NeuralEngineLibTests.cmake )

init_core_test ( core_test 5 ${CMAKE_CURRENT_SOURCE_DIR}/test_Core.cpp )
init_backend_test ( backend_test 5 ${CMAKE_CURRENT_SOURCE_DIR}/test_Backend.cpp )
init_utils_test ( utils_test 5 ${CMAKE_CURRENT_SOURCE_DIR}/test_Utils.cpp )