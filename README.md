# SIMD NEON Example

This project demonstrates the use of SIMD (Single Instruction, Multiple Data) instructions using NEON on ARM-based CPUs.

The example shows the performance difference between scalar and SIMD vector addition.

## Prerequisites

- A C++ compiler (like g++ or clang++)
- An ARM-based CPU with NEON support (like Apple Silicon)

## How to Build and Run

You can use the provided `Makefile` to build and run the example, or you can compile and run the code manually.

### Using Make (Recommended)

1. **Build the executable:**
   ```bash
   make
   ```

2. **Run the example:**
   ```bash
   make run
   ```

### Manual Compilation and Execution

1. **Compile the code:**
   ```bash
   g++ -std=c++11 -O3 -o simd_example main.cpp
   ```

2. **Run the executable:**
   ```bash
   ./simd_example
   ```

## Expected Output

You should see output similar to this, showing that the NEON SIMD version is significantly faster than the scalar version:

```
Scalar addition time: 0.002s
NEON addition time:   0.0005s
Speedup: 4x
```

(Note: The exact times and speedup may vary depending on your machine.)
