# 🧠 NeuralEngineLib — Header-only C++ Library

> ⚙️ Version: **v3.0.0**  
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

## ✅ **Full support for `find_package(...)` with versioning**
### ✅ `NeuralEngineLibConfigVersion.cmake` now included
✅ Support for version-aware installation and client usage:
```cmake
  find_package(NeuralEngineLib 3.0.0 REQUIRED COMPONENTS Core Backend Utils)
```

---

## ⚙️ Build Options:
**[Option]** NEURAL_ENGINE_USE_GPU **[DEFAULT=OFF]**: Enables GPU-related code paths (affects Backend)
**[Option]** NEURAL_ENGINE_ENABLE_LOGGING **[DEFAULT=OFF]**: Enables internal logging features (affects Utils)

### Enable options via CLI:
```bash
cmake -B build -DNEURAL_ENGINE_USE_GPU=ON -DNEURAL_ENGINE_ENABLE_LOGGING=ON
```

### 📦 Installation & Usage (CMake + find_package):
#### 🔧 Install the library locally
```bash
cmake -B build -DCMAKE_INSTALL_PREFIX=./install
cmake --build build
cmake --install build --prefix ./install
```

### 🔌 Link with find_package:
In your client project:
```cmake
set(CMAKE_PREFIX_PATH "/full/path/to/install")
find_package(NeuralEngineLib REQUIRED COMPONENTS Core Backend Utils)

target_link_libraries(application PRIVATE
    NeuralEngineLib::Core
    NeuralEngineLib::Backend
    NeuralEngineLib::Utils 
)
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