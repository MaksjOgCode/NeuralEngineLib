#include <NeuralEngineLib/backend/backend.h>
#include <NeuralEngineLib/core/core.h>
#include <NeuralEngineLib/utils/utils.h>

int main() {
    std::cout << "[Example] get_backend_type() -> " << get_backend_type() << "\n";

    std::cout << "[Example] compute_relu() -> " << compute_relu(24.234) << "\n";
    
#ifdef NEURAL_ENGINE_LOGGING
    log_message("[Example] Hello from <utils>!\n");
#endif

    return 0;
}
