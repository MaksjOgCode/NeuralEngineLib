# NeuralEngineLib::Core
macro ( init_core_test target_name timeout )
    add_executable ( ${target_name} ${ARGN} )
    target_link_libraries ( ${target_name} PRIVATE GTest::gtest_main NeuralEngineLib::Core )
    add_test ( NAME ${target_name} COMMAND ${target_name} TIMEOUT ${timeout} )
endmacro ()

# NeuralEngineLib::Backend
macro ( init_backend_test target_name timeout )
    add_executable ( ${target_name} ${ARGN} )
    target_link_libraries ( ${target_name} PRIVATE GTest::gtest_main NeuralEngineLib::Backend )
    add_test ( NAME ${target_name} COMMAND ${target_name} TIMEOUT ${timeout} )
endmacro ()

# NeuralEngineLib::Utils
macro ( init_utils_test target_name timeout )
    add_executable ( ${target_name} ${ARGN} )
    target_link_libraries ( ${target_name} PRIVATE GTest::gtest_main NeuralEngineLib::Utils )
    target_compile_definitions ( ${target_name} PRIVATE NEURAL_ENGINE_LOGGING=1 )
    add_test ( NAME ${target_name} COMMAND ${target_name} TIMEOUT ${timeout} )
endmacro ()