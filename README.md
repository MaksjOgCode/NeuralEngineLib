# 🧠 NeuralEngineLib — Header-only C++ Library

> ⚙️ Version: **v1.0.0**  
> 📦 Type: **header-only**, component-based  
> 🧩 Options: `NEURAL_ENGINE_USE_GPU`, `NEURAL_ENGINE_ENABLE_LOGGING`

---

## 🚀 Overview

**NeuralEngineLib** is a lightweight, modular, header-only C++ library designed for:

- 📊 Core mathematical computations (`Backend`)
- 🔧 Utility functions (`Utils`)
- 🧠 Core logic processing (`Core`)

Built for flexibility and minimal integration overhead. Use individual components or the whole library as needed.

---

## 🛠️ Integration

### Manual Integration (add_subdirectory):

```cmake
add_subdirectory(NeuralEngineLib)

target_link_libraries(YourApp PRIVATE
    NeuralEngineLib::Backend
    NeuralEngineLib::Core
    NeuralEngineLib::Utils
)
```
### Full Package:

```cmake
target_link_libraries(YourApp PRIVATE NeuralEngineLib::NeuralEngineLib)
```

---

## ⚙️ Build Options:
**[Option]** NEURAL_ENGINE_USE_GPU **[DEFAULT=OFF]**: Enables GPU-related code paths (affects Backend)
**[Option]** NEURAL_ENGINE_ENABLE_LOGGING **[DEFAULT=OFF]**: Enables internal logging features (affects Utils)

### Enable options via CLI:
```bash
cmake -B build -DNEURAL_ENGINE_USE_GPU=ON -DNEURAL_ENGINE_ENABLE_LOGGING=ON
```

---

## 🔧 Requirements:
CMake 3.28+
C++17 or newer
Works with Ninja, GCC

---

## 📄 License:
MIT — free to use, modify, distribute. Keep the credits 

---

## 👤 Author:
GitHub: MaksjOgCode [https://github.com/MaksjOgCode]
