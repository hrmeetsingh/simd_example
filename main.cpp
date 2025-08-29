#include <iostream>
#include <vector>
#include <chrono>
#include <arm_neon.h>

// Scalar vector addition
void scalar_add(std::vector<float>& a, std::vector<float>& b, std::vector<float>& result) {
    for (size_t i = 0; i < a.size(); ++i) {
        result[i] = a[i] + b[i];
    }
}

// SIMD vector addition using NEON
void neon_add(std::vector<float>& a, std::vector<float>& b, std::vector<float>& result) {
    size_t size = a.size();
    for (size_t i = 0; i < size; i += 4) {
        float32x4_t a_vec = vld1q_f32(&a[i]);
        float32x4_t b_vec = vld1q_f32(&b[i]);
        float32x4_t result_vec = vaddq_f32(a_vec, b_vec);
        vst1q_f32(&result[i], result_vec);
    }
}

int main() {
    size_t size = 100000000;
    std::vector<float> a(size, 1.0f);
    std::vector<float> b(size, 2.0f);
    std::vector<float> result_scalar(size);
    std::vector<float> result_neon(size);

    // Time scalar addition
    auto start_scalar = std::chrono::high_resolution_clock::now();
    scalar_add(a, b, result_scalar);
    auto end_scalar = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> scalar_time = end_scalar - start_scalar;

    // Time NEON addition
    auto start_neon = std::chrono::high_resolution_clock::now();
    neon_add(a, b, result_neon);
    auto end_neon = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> neon_time = end_neon - start_neon;

    // Verify results
    for (size_t i = 0; i < size; ++i) {
        if (result_scalar[i] != result_neon[i]) {
            std::cerr << "Error: Results do not match!" << std::endl;
            return 1;
        }
    }

    std::cout << "Scalar addition time: " << scalar_time.count() << "s" << std::endl;
    std::cout << "NEON addition time:   " << neon_time.count() << "s" << std::endl;
    std::cout << "Speedup: " << scalar_time.count() / neon_time.count() << "x" << std::endl;

    return 0;
}
