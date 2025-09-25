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

    // �����������
    std::mt19937 rng;
    std::uniform_int_distribution<int32_t> int_dist;
    std::uniform_real_distribution<float> float_dist;

public:
    PerformanceBenchmark() : rng(12345), int_dist(-10000, 10000), float_dist(-100.0f, 100.0f) {}

    // �����������ܲ���
    void benchmarkInt32Operations() {
        std::cout << "\n[NUM] Int32 �������ܶԱ�:" << std::endl;
        std::cout << "==============================" << std::endl;

        // ���ɲ�������
        std::vector<int32_t> data_a(ITERATIONS), data_b(ITERATIONS);
        for (int i = 0; i < ITERATIONS; i++) {
            data_a[i] = int_dist(rng);
            data_b[i] = int_dist(rng);
            if (data_b[i] == 0) data_b[i] = 1; // �������
        }

        // Ԥ��
        warmupInt32(data_a, data_b);

        // �ӷ�����
        benchmarkAddition(data_a, data_b);

        // ��������
        benchmarkSubtraction(data_a, data_b);

        // �˷�����
        benchmarkMultiplication(data_a, data_b);

        // ��������
        benchmarkDivision(data_a, data_b);

        // ģ�������
        benchmarkModulo(data_a, data_b);
    }

    // �����������ܲ���
    void benchmarkFloatOperations() {
        std::cout << "\n[NUM] Float �������ܶԱ�:" << std::endl;
        std::cout << "==============================" << std::endl;

        // ���ɲ�������
        std::vector<float> data_a(ITERATIONS), data_b(ITERATIONS);
        for (int i = 0; i < ITERATIONS; i++) {
            data_a[i] = float_dist(rng);
            data_b[i] = float_dist(rng);
            if (std::abs(data_b[i]) < 0.001f) data_b[i] = 1.0f; // �������
        }

        // Ԥ��
        warmupFloat(data_a, data_b);

        // �����������
        benchmarkFloatAddition(data_a, data_b);
        benchmarkFloatSubtraction(data_a, data_b);
        benchmarkFloatMultiplication(data_a, data_b);
        benchmarkFloatDivision(data_a, data_b);
    }

private:
    void warmupInt32(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            // ԭ������Ԥ��
            volatile int32_t native_result = a[i] + b[i];

            // ��λ����Ԥ��
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t bit_result = (int32_t)(bit_a + bit_b);
        }
    }

    void warmupFloat(const std::vector<float>& a, const std::vector<float>& b) {
        for (int i = 0; i < WARMUP_ITERATIONS; i++) {
            // ԭ������Ԥ��
            volatile float native_result = a[i] + b[i];

            // ��λ����Ԥ��
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float bit_result = (float)(bit_a + bit_b);
        }
    }

    void benchmarkAddition(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // ԭ���ӷ�
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] + b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ����ӷ�
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a + bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("�ӷ� (+)", native_time, bit_time);
    }

    void benchmarkSubtraction(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // ԭ������
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] - b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ�������
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a - bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("���� (-)", native_time, bit_time);
    }

    void benchmarkMultiplication(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // ԭ���˷�
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ����˷�
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a * bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("�˷� (*)", native_time, bit_time);
    }

    void benchmarkDivision(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // ԭ������
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] / b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ�������
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a / bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("���� (/)", native_time, bit_time);
    }

    void benchmarkModulo(const std::vector<int32_t>& a, const std::vector<int32_t>& b) {
        // ԭ��ģ����
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile int32_t result = a[i] % b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ����ģ����
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_int32 bit_a(a[i]), bit_b(b[i]);
            volatile int32_t result = (int32_t)(bit_a % bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("ģ���� (%)", native_time, bit_time);
    }

    void benchmarkFloatAddition(const std::vector<float>& a, const std::vector<float>& b) {
        // ԭ������ӷ�
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] + b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ���㸡��ӷ�
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a + bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("����ӷ� (+)", native_time, bit_time);
    }

    void benchmarkFloatSubtraction(const std::vector<float>& a, const std::vector<float>& b) {
        // ԭ���������
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] - b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ���㸡�����
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a - bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("������� (-)", native_time, bit_time);
    }

    void benchmarkFloatMultiplication(const std::vector<float>& a, const std::vector<float>& b) {
        // ԭ������˷�
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] * b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ���㸡��˷�
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a * bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("����˷� (*)", native_time, bit_time);
    }

    void benchmarkFloatDivision(const std::vector<float>& a, const std::vector<float>& b) {
        // ԭ���������
        auto start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            volatile float result = a[i] / b[i];
        }
        auto end = std::chrono::high_resolution_clock::now();
        auto native_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        // ��λ���㸡�����
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < ITERATIONS; i++) {
            Bit_float bit_a(a[i]), bit_b(b[i]);
            volatile float result = (float)(bit_a / bit_b);
        }
        end = std::chrono::high_resolution_clock::now();
        auto bit_time = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

        printComparison("������� (/)", native_time, bit_time);
    }

    void printComparison(const std::string& operation, long native_time, long bit_time) {
        double ratio = (double)bit_time / native_time;
        std::cout << std::left << std::setw(12) << operation
            << " | ԭ��: " << std::setw(8) << native_time << "��s"
            << " | ��λ: " << std::setw(8) << bit_time << "��s"
            << " | ����: " << std::fixed << std::setprecision(2) << ratio << "x";

        if (ratio < 1.5) {
            std::cout << " [FAST] ����";
        }
        else if (ratio < 3.0) {
            std::cout << " [GOOD] ����";
        }
        else if (ratio < 10.0) {
            std::cout << " [OK] һ��";
        }
        else {
            std::cout << " [SLOW] ����";
        }
        std::cout << std::endl;
    }

public:
    void runAllBenchmarks() {
        std::cout << "[START] ��λ������������ܻ�׼����" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "���Ե�������: " << ITERATIONS << std::endl;
        std::cout << "Ԥ�ȵ�������: " << WARMUP_ITERATIONS << std::endl;
        std::cout << "========================================" << std::endl;

        benchmarkInt32Operations();
        benchmarkFloatOperations();

        std::cout << "\n[REPORT] ���ܲ����ܽ�:" << std::endl;
        std::cout << "========================================" << std::endl;
        std::cout << "[FAST] ����: ���ܲ����1.5������" << std::endl;
        std::cout << "[GOOD] ����: ���ܲ����1.5-3��֮��" << std::endl;
        std::cout << "[OK] һ��: ���ܲ����3-10��֮��" << std::endl;
        std::cout << "[SLOW] ����: ���ܲ�೬��10��" << std::endl;
        std::cout << "\n[INFO] ��λ����ʵ�������������������߼���" << std::endl;
        std::cout << "   �ڽ�ѧ������Ӧ�ó����¾�����Ҫ��ֵ��" << std::endl;
    }
};

#endif // PERFORMANCE_BENCHMARK_H