#ifndef PURE_BIT_CALCULATOR_TEST_H
#define PURE_BIT_CALCULATOR_TEST_H

#include "PureBitOpsPerfect.h"
#include <string>
#include <vector>
#include <functional>

// 测试结果结构
struct TestResult {
    bool passed;
    std::string testName;
    std::string errorMessage;

    TestResult(const std::string& name, bool success, const std::string& error = "")
        : passed(success), testName(name), errorMessage(error) {
    }
};

// 纯位运算计算器测试类
class PureBitCalculatorTest {
private:
    std::vector<TestResult> results;
    int totalTests;
    int passedTests;
    int failedTests;

    // 内部辅助方法
    void recordTest(const std::string& testName, bool passed, const std::string& errorMsg = "");
    template<typename T>
    bool assertEqual(const T& expected, const T& actual, const std::string& testName);
    template<typename T>
    bool assertNotEqual(const T& expected, const T& actual, const std::string& testName);
    bool assertTrue(bool condition, const std::string& testName);
    bool assertFalse(bool condition, const std::string& testName);

public:
    PureBitCalculatorTest();

    // 基础运算测试
    void testInt32BasicOperations();
    void testUInt32BasicOperations();
    void testInt64BasicOperations();
    void testUInt64BasicOperations();
    void testInt16BasicOperations();
    void testUInt16BasicOperations();
    void testInt8BasicOperations();
    void testUInt8BasicOperations();
    void testFloatBasicOperations();
    void testDoubleBasicOperations();

    // 比较运算测试
    void testInt32Comparisons();
    void testUInt32Comparisons();
    void testInt64Comparisons();
    void testUInt64Comparisons();
    void testInt16Comparisons();
    void testUInt16Comparisons();
    void testInt8Comparisons();
    void testUInt8Comparisons();
    void testFloatComparisons();
    void testDoubleComparisons();

    // 位运算测试
    void testInt32BitOperations();
    void testUInt32BitOperations();
    void testInt64BitOperations();
    void testUInt64BitOperations();
    void testInt16BitOperations();
    void testUInt16BitOperations();
    void testInt8BitOperations();
    void testUInt8BitOperations();
    void testFloatBitOperations();
    void testDoubleBitOperations();

    // 自增自减测试
    void testIncrementDecrementOperations();

    // 边界条件测试
    void testBoundaryConditions();
    void testOverflowHandling();
    void testDivisionByZero();

    // 特殊值测试
    void testSpecialValues();
    void testFloatSpecialValues();
    void testDoubleSpecialValues();

    // 类型转换测试
    void testTypeConversions();
    void testImplicitConversions();

    // 复杂表达式测试
    void testComplexExpressions();
    void testChainedOperations();

    // 新语法测试
    void testNewSyntax();
    void testDirectAssignment();

    // 性能相关测试
    void testLargeNumbers();
    void testPrecisionTests();

    // 压力测试和扩展测试
    void testStressIntegerOperations();
    void testStressFloatingPointOperations();
    void testRandomizedOperations();
    void testExtensiveEdgeCases();
    void testLargeScaleCalculations();
    void testAllTypeCombinations();
    void testSequentialOperations();
    void testMathematicalProperties();

    // 运行所有测试
    void runAllTests();
    void runExtensiveTests();
    void runBasicTests();
    void runAdvancedTests();
    void runBoundaryTests();
    void runSpecialTests();

    // 结果报告
    void printTestResults() const;
    void printSummary() const;
    void printDetailedReport() const;
    void printFailedTests() const;

    // 获取测试统计
    int getTotalTests() const;
    int getPassedTests() const;
    int getFailedTests() const;
    double getSuccessRate() const;

    // 重置测试状态
    void reset();

    // 单独运行测试组
    void runTestGroup(const std::string& groupName, std::function<void()> testFunction);
};

// 测试辅助宏定义
#define TEST_ASSERT_EQ(expected, actual, testName) \
    assertEqual((expected), (actual), (testName))

#define TEST_ASSERT_NE(expected, actual, testName) \
    assertNotEqual((expected), (actual), (testName))

#define TEST_ASSERT_TRUE(condition, testName) \
    assertTrue((condition), (testName))

#define TEST_ASSERT_FALSE(condition, testName) \
    assertFalse((condition), (testName))

#endif