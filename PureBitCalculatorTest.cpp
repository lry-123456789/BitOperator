#include "PureBitCalculatorTest.h"
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

// ==================== 构造函数和辅助方法 ====================

PureBitCalculatorTest::PureBitCalculatorTest()
    : totalTests(0), passedTests(0), failedTests(0) {
}

void PureBitCalculatorTest::recordTest(const std::string& testName, bool passed, const std::string& errorMsg) {
    totalTests++;
    if (passed) {
        passedTests++;
    }
    else {
        failedTests++;
    }
    results.emplace_back(testName, passed, errorMsg);
}

template<typename T>
bool PureBitCalculatorTest::assertEqual(const T& expected, const T& actual, const std::string& testName) {
    bool passed = (expected == actual);
    if (!passed) {
        recordTest(testName, false, "Expected: " + std::to_string(expected) + ", Got: " + std::to_string(actual));
    }
    else {
        recordTest(testName, true);
    }
    return passed;
}

template<typename T>
bool PureBitCalculatorTest::assertNotEqual(const T& expected, const T& actual, const std::string& testName) {
    bool passed = (expected != actual);
    if (!passed) {
        recordTest(testName, false, "Expected NOT: " + std::to_string(expected) + ", Got: " + std::to_string(actual));
    }
    else {
        recordTest(testName, true);
    }
    return passed;
}

bool PureBitCalculatorTest::assertTrue(bool condition, const std::string& testName) {
    recordTest(testName, condition, condition ? "" : "Expected true, got false");
    return condition;
}

bool PureBitCalculatorTest::assertFalse(bool condition, const std::string& testName) {
    bool passed = !condition;
    recordTest(testName, passed, passed ? "" : "Expected false, got true");
    return passed;
}

// ==================== Int32 基础运算测试 ====================

void PureBitCalculatorTest::testInt32BasicOperations() {
    Bit_int32 a = 42, b = 17;

    assertEqual(59, (int32_t)(a + b), "Int32 Addition: 42 + 17");
    assertEqual(25, (int32_t)(a - b), "Int32 Subtraction: 42 - 17");
    assertEqual(714, (int32_t)(a * b), "Int32 Multiplication: 42 * 17");
    assertEqual(2, (int32_t)(a / b), "Int32 Division: 42 / 17");
    assertEqual(8, (int32_t)(a % b), "Int32 Modulo: 42 % 17");

    // 负数测试
    Bit_int32 neg_a = -42, neg_b = -17;
    assertEqual(-59, (int32_t)(neg_a + neg_b), "Int32 Negative Addition: -42 + (-17)");
    assertEqual(-25, (int32_t)(neg_a - neg_b), "Int32 Negative Subtraction: -42 - (-17)");
    assertEqual(714, (int32_t)(neg_a * neg_b), "Int32 Negative Multiplication: -42 * -17");

    // 混合符号测试
    assertEqual(25, (int32_t)(a + neg_b), "Int32 Mixed Addition: 42 + (-17)");
    assertEqual(-714, (int32_t)(a * neg_b), "Int32 Mixed Multiplication: 42 * (-17)");
}

// ==================== UInt32 基础运算测试 ====================

void PureBitCalculatorTest::testUInt32BasicOperations() {
    Bit_uint32 a = 42U, b = 17U;

    assertEqual(59U, (uint32_t)(a + b), "UInt32 Addition: 42 + 17");
    assertEqual(25U, (uint32_t)(a - b), "UInt32 Subtraction: 42 - 17");
    assertEqual(714U, (uint32_t)(a * b), "UInt32 Multiplication: 42 * 17");
    assertEqual(2U, (uint32_t)(a / b), "UInt32 Division: 42 / 17");
    assertEqual(8U, (uint32_t)(a % b), "UInt32 Modulo: 42 % 17");

    // 大数测试
    Bit_uint32 big1 = 4000000000U, big2 = 1000000000U;
    assertEqual(1000000000U, (uint32_t)(big1 - big2 - big2 - big2), "UInt32 Large Number Subtraction");
}

// ==================== Int64 基础运算测试 ====================

void PureBitCalculatorTest::testInt64BasicOperations() {
    Bit_int64 a = 42000000000LL, b = 17000000000LL;

    assertEqual(59000000000LL, (int64_t)(a + b), "Int64 Addition: Large numbers");
    assertEqual(25000000000LL, (int64_t)(a - b), "Int64 Subtraction: Large numbers");
    assertEqual(2LL, (int64_t)(a / b), "Int64 Division: Large numbers");
    assertEqual(8000000000LL, (int64_t)(a % b), "Int64 Modulo: Large numbers");
}

// ==================== UInt64 基础运算测试 ====================

void PureBitCalculatorTest::testUInt64BasicOperations() {
    Bit_uint64 a = 42000000000ULL, b = 17000000000ULL;

    assertEqual(59000000000ULL, (uint64_t)(a + b), "UInt64 Addition: Large numbers");
    assertEqual(25000000000ULL, (uint64_t)(a - b), "UInt64 Subtraction: Large numbers");
    assertEqual(2ULL, (uint64_t)(a / b), "UInt64 Division: Large numbers");
    assertEqual(8000000000ULL, (uint64_t)(a % b), "UInt64 Modulo: Large numbers");
}

// ==================== Float 基础运算测试 ====================

void PureBitCalculatorTest::testFloatBasicOperations() {
    Bit_float a = 3.14159f, b = 2.71828f;

    float sum = (float)(a + b);
    float diff = (float)(a - b);
    float prod = (float)(a * b);
    float quot = (float)(a / b);

    assertTrue(std::abs(sum - 5.8599f) < 0.001f, "Float Addition: 3.14159 + 2.71828");
    assertTrue(std::abs(diff - 0.4233f) < 0.001f, "Float Subtraction: 3.14159 - 2.71828");
    assertTrue(std::abs(prod - 8.5397f) < 0.001f, "Float Multiplication: 3.14159 * 2.71828");
    assertTrue(std::abs(quot - 1.1557f) < 0.001f, "Float Division: 3.14159 / 2.71828");
}

// ==================== Double 基础运算测试 ====================

void PureBitCalculatorTest::testDoubleBasicOperations() {
    Bit_double a = 3.141592653589793, b = 2.718281828459045;

    double sum = (double)(a + b);
    double diff = (double)(a - b);
    double prod = (double)(a * b);
    double quot = (double)(a / b);

    assertTrue(std::abs(sum - 5.859874482048838) < 0.000001, "Double Addition: π + e");
    assertTrue(std::abs(diff - 0.423310825130748) < 0.000001, "Double Subtraction: π - e");
    assertTrue(std::abs(quot - 1.155727349790922) < 0.000001, "Double Division: π / e");
}

// ==================== Int32 比较运算测试 ====================

void PureBitCalculatorTest::testInt32Comparisons() {
    Bit_int32 a = 10, b = 20, c = 10;

    assertTrue(a == c, "Int32 Equality: 10 == 10");
    assertFalse(a == b, "Int32 Inequality: 10 != 20");
    assertTrue(a < b, "Int32 Less Than: 10 < 20");
    assertFalse(b < a, "Int32 Not Less Than: 20 !< 10");
    assertTrue(b > a, "Int32 Greater Than: 20 > 10");
    assertTrue(a <= c, "Int32 Less Equal: 10 <= 10");
    assertTrue(a >= c, "Int32 Greater Equal: 10 >= 10");

    // 负数比较
    Bit_int32 neg = -5;
    assertTrue(neg < a, "Int32 Negative Comparison: -5 < 10");
    assertFalse(neg > a, "Int32 Negative Comparison: -5 !> 10");
}

// ==================== UInt32 比较运算测试 ====================

void PureBitCalculatorTest::testUInt32Comparisons() {
    Bit_uint32 a = 10U, b = 20U, c = 10U;

    assertTrue(a == c, "UInt32 Equality: 10 == 10");
    assertFalse(a == b, "UInt32 Inequality: 10 != 20");
    assertTrue(a < b, "UInt32 Less Than: 10 < 20");
    assertTrue(b > a, "UInt32 Greater Than: 20 > 10");
}

// ==================== 其他类型比较运算测试 ====================

void PureBitCalculatorTest::testInt64Comparisons() {
    Bit_int64 a = 1000000000LL, b = 2000000000LL;
    assertTrue(a < b, "Int64 Comparison: 1B < 2B");
    assertFalse(a > b, "Int64 Comparison: 1B !> 2B");
}

void PureBitCalculatorTest::testUInt64Comparisons() {
    Bit_uint64 a = 1000000000ULL, b = 2000000000ULL;
    assertTrue(a < b, "UInt64 Comparison: 1B < 2B");
    assertTrue(b > a, "UInt64 Comparison: 2B > 1B");
}

void PureBitCalculatorTest::testFloatComparisons() {
    Bit_float a = 3.14f, b = 2.71f;
    assertTrue(a > b, "Float Comparison: 3.14 > 2.71");
    assertFalse(a < b, "Float Comparison: 3.14 !< 2.71");
    assertTrue(a != b, "Float Inequality: 3.14 != 2.71");
}

void PureBitCalculatorTest::testDoubleComparisons() {
    Bit_double a = 3.141592653589793, b = 2.718281828459045;
    assertTrue(a > b, "Double Comparison: π > e");
    assertFalse(a < b, "Double Comparison: π !< e");
}

// ==================== 位运算测试 ====================

void PureBitCalculatorTest::testInt32BitOperations() {
    Bit_int32 a = 0b1100, b = 0b1010;

    assertEqual(8, (int32_t)(a & b), "Int32 AND: 1100 & 1010");
    assertEqual(14, (int32_t)(a | b), "Int32 OR: 1100 | 1010");
    assertEqual(6, (int32_t)(a ^ b), "Int32 XOR: 1100 ^ 1010");
    assertEqual(24, (int32_t)(a << Bit_int32(1)), "Int32 Left Shift: 1100 << 1");
    assertEqual(6, (int32_t)(a >> Bit_int32(1)), "Int32 Right Shift: 1100 >> 1");
}

void PureBitCalculatorTest::testUInt32BitOperations() {
    Bit_uint32 a = 0b1100U, b = 0b1010U;

    assertEqual(8U, (uint32_t)(a & b), "UInt32 AND: 1100 & 1010");
    assertEqual(14U, (uint32_t)(a | b), "UInt32 OR: 1100 | 1010");
    assertEqual(6U, (uint32_t)(a ^ b), "UInt32 XOR: 1100 ^ 1010");
}

void PureBitCalculatorTest::testInt64BitOperations() {
    Bit_int64 a = 0b1100LL, b = 0b1010LL;

    assertEqual(8LL, (int64_t)(a & b), "Int64 AND: 1100 & 1010");
    assertEqual(14LL, (int64_t)(a | b), "Int64 OR: 1100 | 1010");
    assertEqual(6LL, (int64_t)(a ^ b), "Int64 XOR: 1100 ^ 1010");
}

void PureBitCalculatorTest::testUInt64BitOperations() {
    Bit_uint64 a = 0b1100ULL, b = 0b1010ULL;

    assertEqual(8ULL, (uint64_t)(a & b), "UInt64 AND: 1100 & 1010");
    assertEqual(14ULL, (uint64_t)(a | b), "UInt64 OR: 1100 | 1010");
    assertEqual(6ULL, (uint64_t)(a ^ b), "UInt64 XOR: 1100 ^ 1010");
}

void PureBitCalculatorTest::testFloatBitOperations() {
    Bit_float a = 3.14f, b = 2.71f;

    // 浮点位运算主要测试不会崩溃
    Bit_float result1 = a & b;
    Bit_float result2 = a | b;
    Bit_float result3 = a ^ b;

    assertTrue(true, "Float Bit Operations: AND/OR/XOR do not crash");
}

void PureBitCalculatorTest::testDoubleBitOperations() {
    Bit_double a = 3.141592653589793, b = 2.718281828459045;

    // 双精度位运算主要测试不会崩溃
    Bit_double result1 = a & b;
    Bit_double result2 = a | b;
    Bit_double result3 = a ^ b;

    assertTrue(true, "Double Bit Operations: AND/OR/XOR do not crash");
}

// ==================== 自增自减测试 ====================

void PureBitCalculatorTest::testIncrementDecrementOperations() {
    Bit_int32 counter = 5;

    assertEqual(5, (int32_t)counter, "Initial counter value");
    assertEqual(6, (int32_t)(++counter), "Pre-increment: ++counter");
    assertEqual(6, (int32_t)counter, "Counter after pre-increment");
    assertEqual(6, (int32_t)(counter++), "Post-increment: counter++");
    assertEqual(7, (int32_t)counter, "Counter after post-increment");
    assertEqual(6, (int32_t)(--counter), "Pre-decrement: --counter");
    assertEqual(6, (int32_t)counter, "Counter after pre-decrement");
    assertEqual(6, (int32_t)(counter--), "Post-decrement: counter--");
    assertEqual(5, (int32_t)counter, "Counter after post-decrement");
}

// ==================== 边界条件测试 ====================

void PureBitCalculatorTest::testBoundaryConditions() {
    // Int32 最大最小值
    Bit_int32 maxInt = 2147483647; // INT32_MAX
    Bit_int32 minInt = (-2147483647 - 1); // INT32_MIN

    assertEqual(2147483647, (int32_t)maxInt, "Int32 MAX value");
    assertEqual((-2147483647 - 1), (int32_t)minInt, "Int32 MIN value");

    // UInt32 最大值
    Bit_uint32 maxUInt = 4294967295U; // UINT32_MAX
    assertEqual(4294967295U, (uint32_t)maxUInt, "UInt32 MAX value");
}

void PureBitCalculatorTest::testOverflowHandling() {
    // 溢出测试
    Bit_int32 maxInt = 2147483647;
    Bit_int32 overflowResult = maxInt + Bit_int32(1);
    assertEqual((-2147483647 - 1), (int32_t)overflowResult, "Int32 Overflow: MAX + 1 = MIN");

    Bit_int32 minInt = (-2147483647 - 1);
    Bit_int32 underflowResult = minInt - Bit_int32(1);
    assertEqual(2147483647, (int32_t)underflowResult, "Int32 Underflow: MIN - 1 = MAX");
}

void PureBitCalculatorTest::testDivisionByZero() {
    Bit_int32 a = 10, zero = 0;
    Bit_int32 result = a / zero;
    assertEqual(0, (int32_t)result, "Division by zero returns 0");

    Bit_int32 modResult = a % zero;
    assertEqual(0, (int32_t)modResult, "Modulo by zero returns 0");
}

// ==================== 特殊值测试 ====================

void PureBitCalculatorTest::testSpecialValues() {
    // 零值测试
    Bit_int32 zero = 0;
    Bit_int32 five = 5;

    assertEqual(5, (int32_t)(zero + five), "Zero addition");
    assertEqual(-5, (int32_t)(zero - five), "Zero subtraction");
    assertEqual(0, (int32_t)(zero * five), "Zero multiplication");
    assertEqual(0, (int32_t)(zero / five), "Zero division");
    assertEqual(0, (int32_t)(zero % five), "Zero modulo");
}

void PureBitCalculatorTest::testFloatSpecialValues() {
    Bit_float zero = 0.0f;
    Bit_float one = 1.0f;
    Bit_float negOne = -1.0f;

    assertEqual(0.0f, (float)(zero * one), "Float: 0 * 1 = 0");
    assertEqual(-1.0f, (float)(one * negOne), "Float: 1 * -1 = -1");
}

void PureBitCalculatorTest::testDoubleSpecialValues() {
    Bit_double zero = 0.0;
    Bit_double one = 1.0;
    Bit_double negOne = -1.0;

    assertEqual(0.0, (double)(zero * one), "Double: 0 * 1 = 0");
    assertEqual(-1.0, (double)(one * negOne), "Double: 1 * -1 = -1");
}

// ==================== 类型转换测试 ====================

void PureBitCalculatorTest::testTypeConversions() {
    Bit_int32 intVal = 42;
    int32_t convertedInt = (int32_t)intVal;
    assertEqual(42, convertedInt, "Int32 type conversion");

    Bit_float floatVal = 3.14f;
    float convertedFloat = (float)floatVal;
    assertTrue(std::abs(convertedFloat - 3.14f) < 0.001f, "Float type conversion");
}

void PureBitCalculatorTest::testImplicitConversions() {
    // 测试隐式转换（通过赋值）
    Bit_int32 a = 42;     // int -> Bit_int32
    Bit_float b = 3.14f;  // float -> Bit_float

    assertEqual(42, (int32_t)a, "Implicit conversion: int -> Bit_int32");
    assertTrue(std::abs((float)b - 3.14f) < 0.001f, "Implicit conversion: float -> Bit_float");
}

// ==================== 复杂表达式测试 ====================

void PureBitCalculatorTest::testComplexExpressions() {
    Bit_int32 a = 10, b = 20, c = 5;

    // 复合运算
    Bit_int32 result1 = (a + b) * c;
    assertEqual(150, (int32_t)result1, "Complex expression: (10 + 20) * 5");

    Bit_int32 result2 = a * b + c;
    assertEqual(205, (int32_t)result2, "Complex expression: 10 * 20 + 5");

    // 带比较的复合运算
    bool comparison = (a + b) < (c * Bit_int32(10)); // 30 < 50 = true
    assertTrue(comparison, "Complex comparison: (10 + 20) < (5 * 10)");
}

void PureBitCalculatorTest::testChainedOperations() {
    Bit_int32 a = 2;

    // 连续运算
    Bit_int32 result = a + a + a + a + a; // 2*5 = 10
    assertEqual(10, (int32_t)result, "Chained addition: 2+2+2+2+2");

    Bit_int32 result2 = a * a * a; // 2^3 = 8
    assertEqual(8, (int32_t)result2, "Chained multiplication: 2*2*2");
}

// ==================== 新语法测试 ====================

void PureBitCalculatorTest::testNewSyntax() {
    // 测试新的简洁语法
    Bit_int32 ten = 10;
    Bit_uint32 twenty = 20U;
    Bit_int64 billion = 1000000000LL;
    Bit_float pi = 3.14159f;
    Bit_double e = 2.718281828459045;

    assertEqual(10, (int32_t)ten, "New syntax: Bit_int32 ten = 10");
    assertEqual(20U, (uint32_t)twenty, "New syntax: Bit_uint32 twenty = 20U");
    assertEqual(1000000000LL, (int64_t)billion, "New syntax: Bit_int64 billion = 1000000000LL");
    assertTrue(std::abs((float)pi - 3.14159f) < 0.001f, "New syntax: Bit_float pi = 3.14159f");
    assertTrue(std::abs((double)e - 2.718281828459045) < 0.000001, "New syntax: Bit_double e = 2.718...");
}

void PureBitCalculatorTest::testDirectAssignment() {
    // 测试直接赋值
    Bit_int32 a = 0;
    a = 42;
    assertEqual(42, (int32_t)a, "Direct assignment: a = 42");

    Bit_float b = 0.0f;
    b = 3.14f;
    assertTrue(std::abs((float)b - 3.14f) < 0.001f, "Direct assignment: b = 3.14f");
}

// ==================== 性能相关测试 ====================

void PureBitCalculatorTest::testLargeNumbers() {
    // 64位大数测试
    Bit_int64 large1 = 9223372036854775807LL; // INT64_MAX
    Bit_int64 large2 = (-9223372036854775807LL - 1LL); // INT64_MIN

    assertEqual(9223372036854775807LL, (int64_t)large1, "Large number: INT64_MAX");
    assertEqual((-9223372036854775807LL - 1LL), (int64_t)large2, "Large number: INT64_MIN");

    // 大数运算
    Bit_int64 billion = 1000000000LL;
    Bit_int64 trillion = billion * Bit_int64(1000);
    assertEqual(1000000000000LL, (int64_t)trillion, "Large number multiplication: 1B * 1000");
}

void PureBitCalculatorTest::testPrecisionTests() {
    // 浮点精度测试
    Bit_float f1 = 0.1f, f2 = 0.2f;
    Bit_float sum = f1 + f2;
    assertTrue(std::abs((float)sum - 0.3f) < 0.001f, "Float precision: 0.1 + 0.2 ≈ 0.3");

    // 双精度测试
    Bit_double d1 = 0.1, d2 = 0.2;
    Bit_double dsum = d1 + d2;
    assertTrue(std::abs((double)dsum - 0.3) < 0.000001, "Double precision: 0.1 + 0.2 ≈ 0.3");
}

// ==================== 测试运行方法 ====================

void PureBitCalculatorTest::runAllTests() {
    std::cout << "[TEST] 运行所有纯位运算计算器测试..." << std::endl;
    std::cout << "======================================\n" << std::endl;

    runBasicTests();
    runAdvancedTests();
    runBoundaryTests();
    runSpecialTests();
    runExtensiveTests();

    std::cout << "\n======================================" << std::endl;
    std::cout << "[REPORT] 测试完成！" << std::endl;
    printSummary();
}

void PureBitCalculatorTest::runBasicTests() {
    runTestGroup("基础运算测试", [this]() {
        testInt32BasicOperations();
        testUInt32BasicOperations();
        testInt64BasicOperations();
        testUInt64BasicOperations();
        testInt16BasicOperations();
        testUInt16BasicOperations();
        testInt8BasicOperations();
        testUInt8BasicOperations();
        testFloatBasicOperations();
        testDoubleBasicOperations();
        });
}

void PureBitCalculatorTest::runAdvancedTests() {
    runTestGroup("高级功能测试", [this]() {
        testInt32Comparisons();
        testUInt32Comparisons();
        testInt64Comparisons();
        testUInt64Comparisons();
        testInt16Comparisons();
        testUInt16Comparisons();
        testInt8Comparisons();
        testUInt8Comparisons();
        testFloatComparisons();
        testDoubleComparisons();
        testIncrementDecrementOperations();
        testComplexExpressions();
        testChainedOperations();
        });
}

void PureBitCalculatorTest::runBoundaryTests() {
    runTestGroup("边界条件测试", [this]() {
        testBoundaryConditions();
        testOverflowHandling();
        testDivisionByZero();
        testLargeNumbers();
        testPrecisionTests();
        });
}

void PureBitCalculatorTest::runSpecialTests() {
    runTestGroup("特殊功能测试", [this]() {
        testSpecialValues();
        testFloatSpecialValues();
        testDoubleSpecialValues();
        testTypeConversions();
        testImplicitConversions();
        testNewSyntax();
        testDirectAssignment();
        testInt32BitOperations();
        testUInt32BitOperations();
        testInt64BitOperations();
        testUInt64BitOperations();
        testInt16BitOperations();
        testUInt16BitOperations();
        testInt8BitOperations();
        testUInt8BitOperations();
        testFloatBitOperations();
        testDoubleBitOperations();
        });
}

void PureBitCalculatorTest::runTestGroup(const std::string& groupName, std::function<void()> testFunction) {
    std::cout << "[FOCUS] " << groupName << ":" << std::endl;
    int beforeTests = totalTests;
    testFunction();
    int groupTests = totalTests - beforeTests;
    std::cout << "   [OK] 完成 " << groupTests << " 个测试\n" << std::endl;
}

// ==================== 结果报告方法 ====================

void PureBitCalculatorTest::printTestResults() const {
    std::cout << "\n[REPORT] 详细测试结果:" << std::endl;
    std::cout << "=================" << std::endl;

    for (const auto& result : results) {
        std::cout << (result.passed ? "[PASS] " : "[FAIL] ")
            << result.testName;
        if (!result.passed && !result.errorMessage.empty()) {
            std::cout << " - " << result.errorMessage;
        }
        std::cout << std::endl;
    }
}

void PureBitCalculatorTest::printSummary() const {
    std::cout << "\n📈 测试汇总:" << std::endl;
    std::cout << "============" << std::endl;
    std::cout << "总测试数: " << totalTests << std::endl;
    std::cout << "通过测试: " << passedTests << " [PASS]" << std::endl;
    std::cout << "失败测试: " << failedTests << " [FAIL]" << std::endl;
    std::cout << "成功率: " << std::fixed << std::setprecision(3)
        << getSuccessRate() << "%" << std::endl;

    if (failedTests == 0) {
        std::cout << "\n[SUCCESS] 所有测试通过" << std::endl;
    }
    else {
        std::cout << "\n[WARNING] 存在 " << failedTests << " 个失败的测试，请检查详细报告。" << std::endl;
    }
}

void PureBitCalculatorTest::printDetailedReport() const {
    printTestResults();
    printSummary();
}

void PureBitCalculatorTest::printFailedTests() const {
    if (failedTests == 0) {
        std::cout << "[SUCCESS] 没有失败的测试" << std::endl;
        return;
    }

    std::cout << "\n[FAIL] 失败的测试:" << std::endl;
    std::cout << "===============" << std::endl;

    for (const auto& result : results) {
        if (!result.passed) {
            std::cout << "[FAIL] " << result.testName;
            if (!result.errorMessage.empty()) {
                std::cout << " - " << result.errorMessage;
            }
            std::cout << std::endl;
        }
    }
}

// ==================== 获取统计信息方法 ====================

int PureBitCalculatorTest::getTotalTests() const {
    return totalTests;
}

int PureBitCalculatorTest::getPassedTests() const {
    return passedTests;
}

int PureBitCalculatorTest::getFailedTests() const {
    return failedTests;
}

double PureBitCalculatorTest::getSuccessRate() const {
    if (totalTests == 0) return 0.0;
    return (static_cast<double>(passedTests) / totalTests) * 100.0;
}

void PureBitCalculatorTest::reset() {
    results.clear();
    totalTests = 0;
    passedTests = 0;
    failedTests = 0;
}

// 显式实例化模板
template bool PureBitCalculatorTest::assertEqual<int32_t>(const int32_t&, const int32_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<uint32_t>(const uint32_t&, const uint32_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<int64_t>(const int64_t&, const int64_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<uint64_t>(const uint64_t&, const uint64_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<int16_t>(const int16_t&, const int16_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<uint16_t>(const uint16_t&, const uint16_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<int8_t>(const int8_t&, const int8_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<uint8_t>(const uint8_t&, const uint8_t&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<float>(const float&, const float&, const std::string&);
template bool PureBitCalculatorTest::assertEqual<double>(const double&, const double&, const std::string&);

// ==================== Int16/UInt16/Int8/UInt8 基础运算测试 ====================

void PureBitCalculatorTest::testInt16BasicOperations() {
    Bit_int16 a = 100, b = 30;

    assertEqual((int16_t)130, (int16_t)(a + b), "Int16 Addition: 100 + 30");
    assertEqual((int16_t)70, (int16_t)(a - b), "Int16 Subtraction: 100 - 30");
    assertEqual((int16_t)3000, (int16_t)(a * b), "Int16 Multiplication: 100 * 30");
    assertEqual((int16_t)3, (int16_t)(a / b), "Int16 Division: 100 / 30");
    assertEqual((int16_t)10, (int16_t)(a % b), "Int16 Modulo: 100 % 30");

    // 负数测试
    Bit_int16 neg_a = -100, neg_b = -30;
    assertEqual((int16_t)-130, (int16_t)(neg_a + neg_b), "Int16 Negative Addition: -100 + (-30)");
    assertEqual((int16_t)-70, (int16_t)(neg_a - neg_b), "Int16 Negative Subtraction: -100 - (-30)");
    assertEqual((int16_t)3000, (int16_t)(neg_a * neg_b), "Int16 Negative Multiplication: -100 * -30");
}

void PureBitCalculatorTest::testUInt16BasicOperations() {
    Bit_uint16 a = 1000U, b = 300U;

    assertEqual((uint16_t)1300U, (uint16_t)(a + b), "UInt16 Addition: 1000 + 300");
    assertEqual((uint16_t)700U, (uint16_t)(a - b), "UInt16 Subtraction: 1000 - 300");
    assertEqual((uint16_t)37856U, (uint16_t)(a * b), "UInt16 Multiplication: 1000 * 300"); // 溢出结果
    assertEqual((uint16_t)3U, (uint16_t)(a / b), "UInt16 Division: 1000 / 300");
    assertEqual((uint16_t)100U, (uint16_t)(a % b), "UInt16 Modulo: 1000 % 300");
}

void PureBitCalculatorTest::testInt8BasicOperations() {
    Bit_int8 a = 50, b = 7;

    assertEqual((int8_t)57, (int8_t)(a + b), "Int8 Addition: 50 + 7");
    assertEqual((int8_t)43, (int8_t)(a - b), "Int8 Subtraction: 50 - 7");
    assertEqual((int8_t)94, (int8_t)(a * b), "Int8 Multiplication: 50 * 7"); // 350 溢出为 94
    assertEqual((int8_t)7, (int8_t)(a / b), "Int8 Division: 50 / 7");
    assertEqual((int8_t)1, (int8_t)(a % b), "Int8 Modulo: 50 % 7");

    // 负数测试
    Bit_int8 neg_a = -50, neg_b = -7;
    assertEqual((int8_t)-57, (int8_t)(neg_a + neg_b), "Int8 Negative Addition: -50 + (-7)");
}

void PureBitCalculatorTest::testUInt8BasicOperations() {
    Bit_uint8 a = 200U, b = 15U;

    assertEqual((uint8_t)215U, (uint8_t)(a + b), "UInt8 Addition: 200 + 15");
    assertEqual((uint8_t)185U, (uint8_t)(a - b), "UInt8 Subtraction: 200 - 15");
    assertEqual((uint8_t)184U, (uint8_t)(a * b), "UInt8 Multiplication: 200 * 15"); // 3000 溢出为 184
    assertEqual((uint8_t)13U, (uint8_t)(a / b), "UInt8 Division: 200 / 15");
    assertEqual((uint8_t)5U, (uint8_t)(a % b), "UInt8 Modulo: 200 % 15");
}

// ==================== Int16/UInt16/Int8/UInt8 比较运算测试 ====================

void PureBitCalculatorTest::testInt16Comparisons() {
    Bit_int16 a = 100, b = 200, c = 100;

    assertTrue(a == c, "Int16 Equality: 100 == 100");
    assertFalse(a == b, "Int16 Inequality: 100 != 200");
    assertTrue(a < b, "Int16 Less Than: 100 < 200");
    assertFalse(b < a, "Int16 Not Less Than: 200 !< 100");
    assertTrue(b > a, "Int16 Greater Than: 200 > 100");

    // 负数比较
    Bit_int16 neg = -50;
    assertTrue(neg < a, "Int16 Negative Comparison: -50 < 100");
}

void PureBitCalculatorTest::testUInt16Comparisons() {
    Bit_uint16 a = 1000U, b = 2000U, c = 1000U;

    assertTrue(a == c, "UInt16 Equality: 1000 == 1000");
    assertFalse(a == b, "UInt16 Inequality: 1000 != 2000");
    assertTrue(a < b, "UInt16 Less Than: 1000 < 2000");
    assertTrue(b > a, "UInt16 Greater Than: 2000 > 1000");
}

void PureBitCalculatorTest::testInt8Comparisons() {
    Bit_int8 a = 50, b = 100, c = 50;

    assertTrue(a == c, "Int8 Equality: 50 == 50");
    assertFalse(a == b, "Int8 Inequality: 50 != 100");
    assertTrue(a < b, "Int8 Less Than: 50 < 100");
    assertTrue(b > a, "Int8 Greater Than: 100 > 50");

    // 负数比较
    Bit_int8 neg = -25;
    assertTrue(neg < a, "Int8 Negative Comparison: -25 < 50");
}

void PureBitCalculatorTest::testUInt8Comparisons() {
    Bit_uint8 a = 100U, b = 200U, c = 100U;

    assertTrue(a == c, "UInt8 Equality: 100 == 100");
    assertFalse(a == b, "UInt8 Inequality: 100 != 200");
    assertTrue(a < b, "UInt8 Less Than: 100 < 200");
    assertTrue(b > a, "UInt8 Greater Than: 200 > 100");
}

// ==================== Int16/UInt16/Int8/UInt8 位运算测试 ====================

void PureBitCalculatorTest::testInt16BitOperations() {
    Bit_int16 a = 0xF0, b = 0xCC;

    assertEqual((int16_t)0xC0, (int16_t)(a & b), "Int16 AND: 0xF0 & 0xCC");
    assertEqual((int16_t)0xFC, (int16_t)(a | b), "Int16 OR: 0xF0 | 0xCC");
    assertEqual((int16_t)0x3C, (int16_t)(a ^ b), "Int16 XOR: 0xF0 ^ 0xCC");
    assertEqual((int16_t)0x1E0, (int16_t)(a << Bit_int16(1)), "Int16 Left Shift: 0xF0 << 1");
    assertEqual((int16_t)0x78, (int16_t)(a >> Bit_int16(1)), "Int16 Right Shift: 0xF0 >> 1");
}

void PureBitCalculatorTest::testUInt16BitOperations() {
    Bit_uint16 a = 0xF0U, b = 0xCCU;

    assertEqual((uint16_t)0xC0U, (uint16_t)(a & b), "UInt16 AND: 0xF0 & 0xCC");
    assertEqual((uint16_t)0xFCU, (uint16_t)(a | b), "UInt16 OR: 0xF0 | 0xCC");
    assertEqual((uint16_t)0x3CU, (uint16_t)(a ^ b), "UInt16 XOR: 0xF0 ^ 0xCC");
}

void PureBitCalculatorTest::testInt8BitOperations() {
    Bit_int8 a = 0xF0, b = 0xCC;

    assertEqual((int8_t)0xC0, (int8_t)(a & b), "Int8 AND: 0xF0 & 0xCC");
    assertEqual((int8_t)0xFC, (int8_t)(a | b), "Int8 OR: 0xF0 | 0xCC");
    assertEqual((int8_t)0x3C, (int8_t)(a ^ b), "Int8 XOR: 0xF0 ^ 0xCC");
}

void PureBitCalculatorTest::testUInt8BitOperations() {
    Bit_uint8 a = 0xF0U, b = 0xCCU;

    assertEqual((uint8_t)0xC0U, (uint8_t)(a & b), "UInt8 AND: 0xF0 & 0xCC");
    assertEqual((uint8_t)0xFCU, (uint8_t)(a | b), "UInt8 OR: 0xF0 | 0xCC");
    assertEqual((uint8_t)0x3CU, (uint8_t)(a ^ b), "UInt8 XOR: 0xF0 ^ 0xCC");
}

// ==================== 压力测试和扩展测试 ====================

void PureBitCalculatorTest::testStressIntegerOperations() {
    // 大量Int32运算测试
    for (int i = 0; i < 100; i++) {
        Bit_int32 a = i * 123, b = i * 456;

        Bit_int32 sum = a + b;
        assertEqual((int32_t)(i * (123 + 456)), (int32_t)sum,
            "Int32 Stress Addition " + std::to_string(i));

        Bit_int32 diff = a - b;
        assertEqual((int32_t)(i * (123 - 456)), (int32_t)diff,
            "Int32 Stress Subtraction " + std::to_string(i));

        if (b != Bit_int32(0)) {
            Bit_int32 quot = a / b;
            assertEqual((int32_t)(123 / 456), (int32_t)quot,
                "Int32 Stress Division " + std::to_string(i));
        }
    }

    // 大量Int16运算测试
    for (int i = 1; i < 100; i++) {
        Bit_int16 a = i * 100, b = i * 7;

        Bit_int16 prod = a * b;
        assertEqual((int16_t)((i * 100 * i * 7) & 0xFFFF), (int16_t)prod,
            "Int16 Stress Multiplication " + std::to_string(i));
    }

    // 大量Int8运算测试
    for (int i = 1; i < 50; i++) {
        Bit_int8 a = i * 2, b = i;

        Bit_int8 mod = a % b;
        assertEqual((int8_t)0, (int8_t)mod,
            "Int8 Stress Modulo " + std::to_string(i));
    }
}

void PureBitCalculatorTest::testStressFloatingPointOperations() {
    // 大量Float运算测试
    for (int i = 1; i < 100; i++) {
        float f_a = i * 0.1f, f_b = i * 0.2f;
        Bit_float a = f_a, b = f_b;

        Bit_float sum = a + b;
        float expected = f_a + f_b;
        assertTrue(std::abs((float)sum - expected) < 0.001f,
            "Float Stress Addition " + std::to_string(i));

        Bit_float prod = a * b;
        expected = f_a * f_b;
        assertTrue(std::abs((float)prod - expected) < 0.001f,
            "Float Stress Multiplication " + std::to_string(i));
    }

    // 大量Double运算测试
    for (int i = 1; i < 50; i++) {
        double d_a = i * 0.123456789, d_b = i * 0.987654321;
        Bit_double a = d_a, b = d_b;

        Bit_double sum = a + b;
        double expected = d_a + d_b;
        assertTrue(std::abs((double)sum - expected) < 0.000001,
            "Double Stress Addition " + std::to_string(i));
    }
}

void PureBitCalculatorTest::testRandomizedOperations() {
    // 伪随机数生成（简单的线性同余生成器）
    uint32_t seed = 12345;

    for (int i = 0; i < 200; i++) {
        // 生成伪随机数
        seed = seed * 1103515245 + 12345;
        uint32_t rand_a = (seed >> 16) & 0x7FFF;
        seed = seed * 1103515245 + 12345;
        uint32_t rand_b = (seed >> 16) & 0x7FFF;

        if (rand_b == 0) rand_b = 1;  // 避免除零

        Bit_uint32 a = rand_a, b = rand_b;

        // 测试加法交换律
        Bit_uint32 sum1 = a + b;
        Bit_uint32 sum2 = b + a;
        assertTrue(sum1 == sum2, "Randomized Addition Commutative " + std::to_string(i));

        // 测试乘法交换律
        Bit_uint32 prod1 = a * b;
        Bit_uint32 prod2 = b * a;
        assertTrue(prod1 == prod2, "Randomized Multiplication Commutative " + std::to_string(i));

        // 测试除法和乘法的关系
        Bit_uint32 quot = a / b;
        Bit_uint32 remainder = a % b;
        Bit_uint32 reconstructed = quot * b + remainder;
        assertTrue(reconstructed == a, "Randomized Division-Multiplication Relationship " + std::to_string(i));
    }
}

void PureBitCalculatorTest::testExtensiveEdgeCases() {
    // 测试所有整数类型的边界值

    // Int8 边界
    Bit_int8 int8_min = -128, int8_max = 127;
    assertEqual((int8_t)-128, (int8_t)int8_min, "Int8 MIN boundary");
    assertEqual((int8_t)127, (int8_t)int8_max, "Int8 MAX boundary");

    Bit_int8 int8_overflow = int8_max + Bit_int8(1);
    assertEqual((int8_t)-128, (int8_t)int8_overflow, "Int8 overflow to MIN");

    // UInt8 边界
    Bit_uint8 uint8_min = 0, uint8_max = 255;
    assertEqual((uint8_t)0, (uint8_t)uint8_min, "UInt8 MIN boundary");
    assertEqual((uint8_t)255, (uint8_t)uint8_max, "UInt8 MAX boundary");

    // Int16 边界
    Bit_int16 int16_min = -32768, int16_max = 32767;
    assertEqual((int16_t)-32768, (int16_t)int16_min, "Int16 MIN boundary");
    assertEqual((int16_t)32767, (int16_t)int16_max, "Int16 MAX boundary");

    // UInt16 边界
    Bit_uint16 uint16_max = 65535U;
    assertEqual((uint16_t)65535U, (uint16_t)uint16_max, "UInt16 MAX boundary");

    // 测试零值运算
    for (int type = 0; type < 4; type++) {
        switch (type) {
        case 0: {
            Bit_int32 zero = 0, val = 42;
            assertTrue(zero + val == val, "Zero addition int32");
            assertTrue(val + zero == val, "Zero addition commutative int32");
            assertTrue(zero * val == zero, "Zero multiplication int32");
            assertTrue(val * zero == zero, "Zero multiplication commutative int32");
            break;
        }
        case 1: {
            Bit_int16 zero = 0, val = 42;
            assertTrue(zero + val == val, "Zero addition int16");
            assertTrue(zero * val == zero, "Zero multiplication int16");
            break;
        }
        case 2: {
            Bit_int8 zero = 0, val = 42;
            assertTrue(zero + val == val, "Zero addition int8");
            assertTrue(zero * val == zero, "Zero multiplication int8");
            break;
        }
        case 3: {
            Bit_uint32 zero = 0, val = 42;
            assertTrue(zero + val == val, "Zero addition uint32");
            assertTrue(zero * val == zero, "Zero multiplication uint32");
            break;
        }
        }
    }
}

void PureBitCalculatorTest::testLargeScaleCalculations() {
    // 大规模连续计算
    Bit_int64 accumulator = 0;
    for (int i = 1; i <= 100; i++) {
        accumulator = accumulator + Bit_int64(i);
    }
    // 1+2+...+100 = 100*101/2 = 5050
    assertEqual((int64_t)5050, (int64_t)accumulator, "Large scale sum 1 to 100");

    // 大规模乘法
    Bit_uint64 product = 1;
    for (int i = 1; i <= 10; i++) {
        product = product * Bit_uint64(i);
    }
    // 10! = 3628800
    assertEqual((uint64_t)3628800, (uint64_t)product, "Large scale factorial 10");

    // 浮点大规模计算
    Bit_double pi_approx = 0.0;
    for (int i = 0; i < 100; i++) {
        double term = (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
        pi_approx = pi_approx + Bit_double(term);
    }
    // π/4 ≈ pi_approx * 4
    Bit_double pi_estimate = pi_approx * Bit_double(4.0);
    assertTrue(std::abs((double)pi_estimate - 3.141592653589793) < 0.01,
        "Large scale π approximation");
}

void PureBitCalculatorTest::testAllTypeCombinations() {
    // 测试不同类型之间的一致性（通过类型转换）

    int32_t test_val = 12345;
    Bit_int32 val32 = test_val;
    Bit_int16 val16 = (int16_t)test_val;

    // 在16位范围内的值应该一致
    if (test_val >= -32768 && test_val <= 32767) {
        assertEqual((int16_t)test_val, (int16_t)val16, "Type consistency int32->int16");
    }

    // 测试无符号类型
    uint32_t utest_val = 12345U;
    Bit_uint32 uval32 = utest_val;
    Bit_uint16 uval16 = (uint16_t)utest_val;

    if (utest_val <= 65535U) {
        assertEqual((uint16_t)utest_val, (uint16_t)uval16, "Type consistency uint32->uint16");
    }

    // 浮点类型精度对比
    float f_val = 123.456f;
    double d_val = 123.456;

    Bit_float bf = f_val;
    Bit_double bd = d_val;

    assertTrue(std::abs((float)bf - f_val) < 0.001f, "Float precision consistency");
    assertTrue(std::abs((double)bd - d_val) < 0.000001, "Double precision consistency");
}

void PureBitCalculatorTest::testSequentialOperations() {
    // 测试连续运算的稳定性

    Bit_int32 counter = 0;
    for (int i = 0; i < 100; i++) {
        counter++;
        counter = counter + Bit_int32(i);
        counter = counter - Bit_int32(i);
        counter--;
    }
    assertEqual((int32_t)0, (int32_t)counter, "Sequential increment/decrement stability");

    // 测试连续乘除法
    Bit_uint32 multiplier = 1000;
    for (int i = 2; i <= 10; i++) {
        multiplier = multiplier * Bit_uint32(i);
        multiplier = multiplier / Bit_uint32(i);
    }
    assertEqual((uint32_t)1000, (uint32_t)multiplier, "Sequential multiply/divide stability");

    // 浮点连续运算
    Bit_float accumulator = 0.0f;
    for (int i = 1; i <= 50; i++) {
        accumulator = accumulator + Bit_float(1.0f / i);
    }
    // 调和级数前50项的近似值
    assertTrue((float)accumulator > 4.4f && (float)accumulator < 4.6f,
        "Sequential harmonic series approximation");
}

void PureBitCalculatorTest::testMathematicalProperties() {
    // 测试数学属性

    // 分配律：a * (b + c) = a * b + a * c
    for (int i = 1; i <= 20; i++) {
        Bit_int32 a = i, b = i * 2, c = i * 3;

        Bit_int32 left = a * (b + c);
        Bit_int32 right = (a * b) + (a * c);

        assertTrue(left == right, "Distributive property test " + std::to_string(i));
    }

    // 结合律：(a + b) + c = a + (b + c)
    for (int i = 1; i <= 20; i++) {
        Bit_uint16 a = i * 100, b = i * 200, c = i * 300;

        Bit_uint16 left = (a + b) + c;
        Bit_uint16 right = a + (b + c);

        assertTrue(left == right, "Associative property test " + std::to_string(i));
    }

    // 恒等元素：a + 0 = a, a * 1 = a
    for (int i = 1; i <= 20; i++) {
        Bit_int64 a = i * 1000000LL;
        Bit_int64 zero = 0, one = 1;

        assertTrue((a + zero) == a, "Additive identity test " + std::to_string(i));
        assertTrue((a * one) == a, "Multiplicative identity test " + std::to_string(i));
    }

    // 逆元素：a + (-a) = 0
    for (int i = 1; i <= 20; i++) {
        Bit_int16 a = i * 100;
        Bit_int16 neg_a = Bit_int16(0) - a;
        Bit_int16 zero = 0;

        assertTrue((a + neg_a) == zero, "Additive inverse test " + std::to_string(i));
    }
}

void PureBitCalculatorTest::runExtensiveTests() {
    runTestGroup("压力测试", [this]() {
        testStressIntegerOperations();
        testStressFloatingPointOperations();
        testRandomizedOperations();
        testExtensiveEdgeCases();
        testLargeScaleCalculations();
        testAllTypeCombinations();
        testSequentialOperations();
        testMathematicalProperties();
        });
}