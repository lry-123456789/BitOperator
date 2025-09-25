#ifndef PERFORMANCE_BENCHMARK_H
#define PERFORMANCE_BENCHMARK_H
#include "PureBitOpsPerfect.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

class PerformanceBenchmark {
private:
    static const int ITERATIONS = 100000;
    static const int WARMUP_ITERATIONS = 1000;

    // 随机数生成器
    std::mt19937 rng;
    std::uniform_int_distribution<int32_t> int_dist;
    std::uniform_real_distribution<float> float_dist;

public:
    PerformanceBenchmark() : rng(12345), int_dist(-10000, 10000), float_dist(-100.0f, 100.0f) {}

    // 整数运算性能测试
    void benchmarkInt32Operations() {
        std::cout << "\n[NUM] Int32 运算性能对比:" << std::endl;
        std::cout << "==============================" << std::endl;

        // 生成测试数据
        std::vector<int32_t> data_a(ITERATIONS), data_b(ITERATIONS);
        for (int i = 0; i < ITERATIONS; i++) {
            data_a[i] = int_dist(rng);
            data_b[i] = int_dist(rng);
            if (data_b[i] == 0) data_b[i] = 1; // 避免除零
        }

        // 预热
        warmupInt32(data_a, data_b);

        // 加法测试
        benchmarkAddition(data_a, data_b);

        // 减法测试
        benchmarkSubtraction(data_a, data_b);

        // 乘法测试
        benchmarkMultiplication(data_a, data_b);

        // 除法测试
        benchmarkDivision(data_a, data_b);

        // 模运算测试
        benchmarkModulo(data_a, data_b);
    }

    // 浮点运算性能测试
    void benchmarkFloatOperations() {
        std::cout << "\n[NUM] Float 运算性能对比:" << std::endl;
        std::cout << "==============================" << std::endl;

        // 生成测试数据
        std::vector<float> data_a(ITERATIONS), data_b(ITERATIONS);
        for (int i = 0; i < ITERATIONS; i++) {
            data_a[i] = float_dist(rng);
            data_b[i] = float_dist(rng);
            if (std::abs(data_b[i]) < 0.001f) data_b[i] = 1.0f; // 避免除零
        }

        // 预热
        warmupFloat(data_a, data_b);

        // 浮点运算测试
        benchmarkFloatAddition(data_a, data_b);
        benchmarkFloatSubtraction(data_a, data_b);
        benchmarkFloatMultiplication(data_a, data_b);
        benchmarkFloatDivision(data_a, data_b);
    }

private:
    void warmupInt32(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            // 原生运算预热
            volatile int32_t native_result = a[i] + b[i];

            // 纯位运算预热
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t bit_result = (int32_t)(bit_a + bit_b);
        }
    }

    void warmupFloat(const std::vector<float>& a, const std::vector<float>& b) {
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            // 原生运算预热
            volatile float native_result = a[i] + b[i];

            // 纯位运算预热
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float bit_result = (float)(bit_a + bit_b);
        }
    }

    void benchmarkAddition(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // 原生加法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] + b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算加法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a + bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("加法 (+)", native_time, bit_time);
    }

    void benchmarkSubtraction(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // 原生减法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] - b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算减法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a - bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("减法 (-)", native_time, bit_time);
    }

    void benchmarkMultiplication(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // 原生乘法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算乘法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a * bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("乘法 (*)", native_time, bit_time);
    }

    void benchmarkDivision(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // 原生除法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] / b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算除法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a / bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("除法 (/)", native_time, bit_time);
    }

    void benchmarkModulo(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // 原生模运算
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] % b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算模运算
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a % bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("模运算 (%)", native_time, bit_time);
    }

    void benchmarkFloatAddition(const std::vector<float>& a, const std::vector<float>& b) {
        // 原生浮点加法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] + b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算浮点加法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a + bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("浮点加法 (+)", native_time, bit_time);
    }

    void benchmarkFloatSubtraction(const std::vector<float>& a, const std::vector<float>& b) {
        // 原生浮点减法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] - b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算浮点减法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a - bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("浮点减法 (-)", native_time, bit_time);
    }

    void benchmarkFloatMultiplication(const std::vector<float>& a, const std::vector<float>& b) {
        // 原生浮点乘法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算浮点乘法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a * bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("浮点乘法 (*)", native_time, bit_time);
    }

    void benchmarkFloatDivision(const std::vector<float>& a, const std::vector<float>& b) {
        // 原生浮点除法
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] / b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算浮点除法
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a / bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("浮点除法 (/)", native_time, bit_time);
    }

    void printComparison(const std::string& operation, long native_time, long bit_time) {
        double ratio = (double)bit_time / native_time;
        std::cout << std::left << std::setw(12) << operation
            << " | 原生: " << std::setw(8) << native_time << "μs"
            << " | 纯位: " << std::setw(8) << bit_time << "μs"
            << " | 倍率: " << std::fixed << std::setprecision(2) << ratio << "x";

        if (ratio < 1.5) {
            std::cout << " [FAST] 优秀";
        }
        else if (ratio < 3.0) {
            std::cout << " [GOOD] 良好";
        }
        else if (ratio < 10.0) {
            std::cout << " [OK] 一般";
        }
        else {
            std::cout << " [SLOW] 较慢";
        }
        std::cout << std::endl;
    }

public:
    void runAllBenchmarks() {
        std::cout << "[START] 纯位运算计算器性能基准测试" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "测试迭代次数: " << ITERATIONS << std::endl;
        std::cout << "预热迭代次数: " << WARMUP_ITERATIONS << std::endl;
        std::cout << "========================================" << std::endl;

        benchmarkInt32Operations();
        benchmarkFloatOperations();

        std::cout << "\n[REPORT] 性能测试总结:" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "[FAST] 优秀: 性能差距在1.5倍以内" << std::endl;
        std::cout << "[GOOD] 良好: 性能差距在1.5-3倍之间" << std::endl;
        std::cout << "[OK] 一般: 性能差距在3-10倍之间" << std::endl;
        std::cout << "[SLOW] 较慢: 性能差距超过10倍" << std::endl;
        std::cout << "\n[INFO] 纯位运算实现了完整的算术运算逻辑，" << std::endl;
        std::cout << "   在教学和特殊应用场景下具有重要价值！" << std::endl;
    }
};

#endif // PERFORMANCE_BENCHMARK_H