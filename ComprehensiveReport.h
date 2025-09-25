#ifndef COMPREHENSIVE_REPORT_H
#define COMPREHENSIVE_REPORT_H
#include "PureBitOpsPerfect.h"
#include "PureBitCalculatorTest.h"
#include <chrono>
#include <iostream>
#include <iomanip>
#include <vector>
#include <random>

class ComprehensiveReport {
private:
    static const int PERFORMANCE_ITERATIONS = 100000;
    static const int WARMUP_ITERATIONS = 1000;

    std::mt19937 rng;
    std::uniform_int_distribution<int32_t> int_dist;
    std::uniform_real_distribution<float> float_dist;

public:
    ComprehensiveReport() : rng(12345), int_dist(-10000, 10000), float_dist(-100.0f, 100.0f) {}

    void generateFullReport() {
        printHeader();
        runFunctionalityTests();
        runPerformanceBenchmarks();
        printSummary();
    }

private:
    void printHeader() {
        std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
        std::cout << "                        PureBitCalculator 完整评测报告                           " << std::endl;
        std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
        std::cout << "[MENU] 项目概述: 纯位运算计算器 - 使用位操作实现所有算术运算" << std::endl;
        std::cout << "[DATE] 测试时间: " << getCurrentTime() << std::endl;
        std::cout << "[TEST] 测试范围: 功能性测试 + 性能基准测试" << std::endl;
        std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
    }

    void runFunctionalityTests() {
        std::cout << "\n[REPORT] 第一部分: 功能性测试报告" << std::endl;
        std::cout << "──────────────────────────────────────────────────────────────────────────────" << std::endl;

        PureBitCalculatorTest tester;
        auto start = std::chrono::high_resolution_clock::now();
        tester.runAllTests();
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

        std::cout << "\n[REPORT] 功能性测试统计:" << std::endl;
        std::cout << "┌─────────────────────────────────────────┬─────────────────┐" << std::endl;
        std::cout << "│ 测试项目                                │ 数值            │" << std::endl;
        std::cout << "├─────────────────────────────────────────┼─────────────────┤" << std::endl;
        std::cout << "│ 总测试用例数                            │ " << std::setw(15) << tester.getTotalTests() << " │" << std::endl;
        std::cout << "│ 通过测试数                              │ " << std::setw(15) << tester.getPassedTests() << " │" << std::endl;
        std::cout << "│ 失败测试数                              │ " << std::setw(15) << tester.getFailedTests() << " │" << std::endl;
        std::cout << "│ 成功率                                  │ " << std::setw(13) << std::fixed << std::setprecision(1) << tester.getSuccessRate() << "% │" << std::endl;
        std::cout << "│ 测试执行时间                            │ " << std::setw(13) << duration << "ms │" << std::endl;
        std::cout << "└─────────────────────────────────────────┴─────────────────┘" << std::endl;

        if (tester.getFailedTests() == 0) {
            std::cout << "[SUCCESS] 功能性测试结论: 所有测试通过，实现完全正确！" << std::endl;
        }
        else if (tester.getSuccessRate() >= 99.0) {
            std::cout << "[OK] 功能性测试结论: 几乎所有测试通过，实现高度可靠！" << std::endl;
        }
        else {
            std::cout << "[WARNING] 功能性测试结论: 存在部分失败案例，需要进一步优化。" << std::endl;
        }

        std::cout << "\n[FOCUS] 测试覆盖范围:" << std::endl;
        std::cout << "• 基础运算: +, -, *, /, % (所有整数和浮点类型)" << std::endl;
        std::cout << "• 比较运算: ==, !=, <, >, <=, >=" << std::endl;
        std::cout << "• 位运算: &, |, ^, ~, <<, >>" << std::endl;
        std::cout << "• 自增自减: ++, --" << std::endl;
        std::cout << "• 边界条件: 溢出、除零、特殊值" << std::endl;
        std::cout << "• 压力测试: 大量随机数据、数学定律验证" << std::endl;
        std::cout << "• 支持类型: int8_t, uint8_t, int16_t, uint16_t, int32_t, uint32_t, int64_t, uint64_t, float, double" << std::endl;
    }

    void runPerformanceBenchmarks() {
        std::cout << "\n[PERF] 第二部分: 性能基准测试报告" << std::endl;
        std::cout << "──────────────────────────────────────────────────────────────────────────────" << std::endl;
        std::cout << "测试配置: " << PERFORMANCE_ITERATIONS << " 次运算迭代，" << WARMUP_ITERATIONS << " 次预热" << std::endl;

        // 生成测试数据
        std::vector<int32_t> int_a(PERFORMANCE_ITERATIONS), int_b(PERFORMANCE_ITERATIONS);
        std::vector<float> float_a(PERFORMANCE_ITERATIONS), float_b(PERFORMANCE_ITERATIONS);

        for (int i = 0; i < PERFORMANCE_ITERATIONS; i++) {
            int_a[i] = int_dist(rng);
            int_b[i] = int_dist(rng);
            if (int_b[i] == 0) int_b[i] = 1;

            float_a[i] = float_dist(rng);
            float_b[i] = float_dist(rng);
            if (std::abs(float_b[i]) < 0.001f) float_b[i] = 1.0f;
        }

        // 预热
        warmup(int_a, int_b, float_a, float_b);

        std::cout << "\n[NUM] Int32 运算性能对比:" << std::endl;
        std::cout << "┌─────────────────┬─────────────┬─────────────┬─────────────┬─────────────────┐" << std::endl;
        std::cout << "│ 运算类型        │ 原生运算(μs)│ 纯位运算(μs)│ 性能倍率    │ 评级            │" << std::endl;
        std::cout << "├─────────────────┼─────────────┼─────────────┼─────────────┼─────────────────┤" << std::endl;

        benchmarkOperation("加法 (+)", int_a, int_b, [](int32_t a, int32_t b) { return a + b; },
            [](int32_t a, int32_t b) { Bit_int32 ba(a), bb(b); return (int32_t)(ba + bb); });
        benchmarkOperation("减法 (-)", int_a, int_b, [](int32_t a, int32_t b) { return a - b; },
            [](int32_t a, int32_t b) { Bit_int32 ba(a), bb(b); return (int32_t)(ba - bb); });
        benchmarkOperation("乘法 (*)", int_a, int_b, [](int32_t a, int32_t b) { return a * b; },
            [](int32_t a, int32_t b) { Bit_int32 ba(a), bb(b); return (int32_t)(ba * bb); });
        benchmarkOperation("除法 (/)", int_a, int_b, [](int32_t a, int32_t b) { return a / b; },
            [](int32_t a, int32_t b) { Bit_int32 ba(a), bb(b); return (int32_t)(ba / bb); });
        benchmarkOperation("模运算 (%)", int_a, int_b, [](int32_t a, int32_t b) { return a % b; },
            [](int32_t a, int32_t b) { Bit_int32 ba(a), bb(b); return (int32_t)(ba % bb); });

        std::cout << "└─────────────────┴─────────────┴─────────────┴─────────────┴─────────────────┘" << std::endl;

        std::cout << "\n[NUM] Float 运算性能对比:" << std::endl;
        std::cout << "┌─────────────────┬─────────────┬─────────────┬─────────────┬─────────────────┐" << std::endl;
        std::cout << "│ 运算类型        │ 原生运算(μs)│ 纯位运算(μs)│ 性能倍率    │ 评级            │" << std::endl;
        std::cout << "├─────────────────┼─────────────┼─────────────┼─────────────┼─────────────────┤" << std::endl;

        benchmarkFloatOperation("浮点加法 (+)", float_a, float_b, [](float a, float b) { return a + b; },
            [](float a, float b) { Bit_float ba(a), bb(b); return (float)(ba + bb); });
        benchmarkFloatOperation("浮点减法 (-)", float_a, float_b, [](float a, float b) { return a - b; },
            [](float a, float b) { Bit_float ba(a), bb(b); return (float)(ba - bb); });
        benchmarkFloatOperation("浮点乘法 (*)", float_a, float_b, [](float a, float b) { return a * b; },
            [](float a, float b) { Bit_float ba(a), bb(b); return (float)(ba * bb); });
        benchmarkFloatOperation("浮点除法 (/)", float_a, float_b, [](float a, float b) { return a / b; },
            [](float a, float b) { Bit_float ba(a), bb(b); return (float)(ba / bb); });

        std::cout << "└─────────────────┴─────────────┴─────────────┴─────────────┴─────────────────┘" << std::endl;
    }

    void warmup(const std::vector<int32_t>& int_a, const std::vector<int32_t>& int_b,
        const std::vector<float>& float_a, const std::vector<float>& float_b) {
        // 整数预热
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            volatile int32_t result1 = int_a[i] + int_b[i];
            Bit_int32 ba(int_a[i]), bb(int_b[i]);
            volatile int32_t result2 = (int32_t)(ba + bb);
        }

        // 浮点预热
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            volatile float result1 = float_a[i] + float_b[i];
            Bit_float ba(float_a[i]), bb(float_b[i]);
            volatile float result2 = (float)(ba + bb);
        }
    }

    template<typename NativeOp, typename BitOp>
    void benchmarkOperation(const std::string& name, const std::vector<int32_t>& a, const std::vector<int32_t>& b,
        NativeOp native_op, BitOp bit_op) {
        // 原生运算
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < PERFORMANCE_ITERATIONS; i++) {
            volatile int32_t result = native_op(a[i], b[i]);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < PERFORMANCE_ITERATIONS; i++) {
            volatile int32_t result = bit_op(a[i], b[i]);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printPerformanceRow(name, native_time, bit_time);
    }

    template<typename NativeOp, typename BitOp>
    void benchmarkFloatOperation(const std::string& name, const std::vector<float>& a, const std::vector<float>& b,
        NativeOp native_op, BitOp bit_op) {
        // 原生运算
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < PERFORMANCE_ITERATIONS; i++) {
            volatile float result = native_op(a[i], b[i]);
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // 纯位运算
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < PERFORMANCE_ITERATIONS; i++) {
            volatile float result = bit_op(a[i], b[i]);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printPerformanceRow(name, native_time, bit_time);
    }

    void printPerformanceRow(const std::string& name, long native_time, long bit_time) {
        double ratio = (double)bit_time / native_time;
        std::string rating;

        if (ratio < 1.5) {
            rating = "[FAST] 优秀";
        }
        else if (ratio < 3.0) {
            rating = "[GOOD] 良好";
        }
        else if (ratio < 10.0) {
            rating = "[OK] 一般";
        }
        else if (ratio < 50.0) {
            rating = "[SLOW] 较慢";
        }
        else {
            rating = "[SLOW] 很慢";
        }

        std::cout << "│ " << std::left << std::setw(15) << name
            << " │ " << std::right << std::setw(11) << native_time
            << " │ " << std::right << std::setw(11) << bit_time
            << " │ " << std::right << std::setw(9) << std::fixed << std::setprecision(1) << ratio << "x"
            << " │ " << std::left << std::setw(15) << rating << " │" << std::endl;
    }

    void printSummary() {

        std::cout << "\n════════════════════════════════════════════════════════════════════════════════" << std::endl;
        std::cout << "                                报告结束                                       " << std::endl;
        std::cout << "════════════════════════════════════════════════════════════════════════════════" << std::endl;
    }

    std::string getCurrentTime() {
        auto now = std::chrono::system_clock::now();
        auto time_t = std::chrono::system_clock::to_time_t(now);
        auto tm = *std::localtime(&time_t);

        std::stringstream ss;
        ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

#endif // COMPREHENSIVE_REPORT_H