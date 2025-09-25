#ifndef PURE_BIT_CALCULATOR_TEST_H
#define PURE_BIT_CALCULATOR_TEST_H

#include "PureBitOpsPerfect.h"
#include <string>
#include <vector>
#include <functional>

// ���Խ���ṹ
struct TestResult {
    bool passed;
    std::string testName;
    std::string errorMessage;

    TestResult(const std::string& name, bool success, const std::string& error = "")
        : passed(success), testName(name), errorMessage(error) {
    }
};

// ��λ���������������
class PureBitCalculatorTest {
private:
    std::vector<TestResult> results;
    int totalTests;
    int passedTests;
    int failedTests;

    // �ڲ���������
    void recordTest(const std::string& testName, bool passed, const std::string& errorMsg = "");
    template<typename T>
    bool assertEqual(const T& expected, const T& actual, const std::string& testName);
    template<typename T>
    bool assertNotEqual(const T& expected, const T& actual, const std::string& testName);
    bool assertTrue(bool condition, const std::string& testName);
    bool assertFalse(bool condition, const std::string& testName);

public:
    PureBitCalculatorTest();

    // �����������
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

    // �Ƚ��������
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

    // λ�������
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

    // �����Լ�����
    void testIncrementDecrementOperations();

    // �߽���������
    void testBoundaryConditions();
    void testOverflowHandling();
    void testDivisionByZero();

    // ����ֵ����
    void testSpecialValues();
    void testFloatSpecialValues();
    void testDoubleSpecialValues();

    // ����ת������
    void testTypeConversions();
    void testImplicitConversions();

    // ���ӱ��ʽ����
    void testComplexExpressions();
    void testChainedOperations();

    // ���﷨����
    void testNewSyntax();
    void testDirectAssignment();

    // ������ز���
    void testLargeNumbers();
    void testPrecisionTests();

    // ѹ�����Ժ���չ����
    void testStressIntegerOperations();
    void testStressFloatingPointOperations();
    void testRandomizedOperations();
    void testExtensiveEdgeCases();
    void testLargeScaleCalculations();
    void testAllTypeCombinations();
    void testSequentialOperations();
    void testMathematicalProperties();

    // �������в���
    void runAllTests();
    void runExtensiveTests();
    void runBasicTests();
    void runAdvancedTests();
    void runBoundaryTests();
    void runSpecialTests();

    // �������
    void printTestResults() const;
    void printSummary() const;
    void printDetailedReport() const;
    void printFailedTests() const;

    // ��ȡ����ͳ��
    int getTotalTests() const;
    int getPassedTests() const;
    int getFailedTests() const;
    double getSuccessRate() const;

    // ���ò���״̬
    void reset();

    // �������в�����
    void runTestGroup(const std::string& groupName, std::function<void()> testFunction);
};

// ���Ը����궨��
#define TEST_ASSERT_EQ(expected, actual, testName) \
    assertEqual((expected), (actual), (testName))

#define TEST_ASSERT_NE(expected, actual, testName) \
    assertNotEqual((expected), (actual), (testName))

#define TEST_ASSERT_TRUE(condition, testName) \
    assertTrue((condition), (testName))

#define TEST_ASSERT_FALSE(condition, testName) \
    assertFalse((condition), (testName))

#endif