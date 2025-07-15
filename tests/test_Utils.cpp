#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include <NeuralEngineLib/utils/utils.h>

TEST ( Utils_Test, CompareLogWhenEnabled ) {
    std::ostringstream captured_output;
    std::streambuf* old_buf = std::cout.rdbuf( captured_output.rdbuf() );

    log_message( "Testing Neural Engine Log:" );

    std::cout.rdbuf( old_buf );

    EXPECT_EQ ( captured_output.str(), "[NeuralEngine Log]: Testing Neural Engine Log:\n" );
}