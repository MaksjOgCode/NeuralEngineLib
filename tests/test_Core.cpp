#include <gtest/gtest.h>
#include <NeuralEngineLib/core/core.h>

TEST ( Core_Test, ReturnRELU ) {
    EXPECT_EQ ( compute_relu( 12.43 ), 12.43 );
}
