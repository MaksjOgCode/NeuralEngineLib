#include <gtest/gtest.h>
#include <NeuralEngineLib/backend/backend.h>

TEST ( Backend_Test, ReturnCPU ) {
    EXPECT_EQ ( get_backend_type(), "CPU" );
}