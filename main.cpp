#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include"PureBitOpsPerfect.h"
#include"PureBitCalculatorTest.h"
#include"PerformanceBenchmark.h"
#include"ComprehensiveReport.h"

static void getReport()
{
    ComprehensiveReport report;
    report.generateFullReport();
}

static void runbenchmark()
{
    PerformanceBenchmark benchmark;
    benchmark.runAllBenchmarks();
}

static void runTests()
{
    PureBitCalculatorTest tester;
    tester.runAllTests();
}


int main()
{
    runTests();
	runbenchmark();
    getReport();
	Bit_double a = 1.05;
	Bit_double b = 1.21;
	Bit_double c = 1.0;
	std::cout << std::setprecision(16);
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a/ b = " << (a / b) << std::endl;
	std::cout << "a/(1/b)=" << (a / (c/ b)) << std::endl;
	std::cout << "a*a=" << (a * a) << std::endl;
	std::cout << "a*a*a=" << (a * a * a) << std::endl;
	std::cout << "a*a*a*a=" << (a * a * a * a) << std::endl;
	std::cout << "a*a*a*a-1.21550625=" << (a * a * a * a-Bit_double(1.21550625)) << std::endl;
	std::cout << "a=" << a << std::endl;
	std::cout << "0/0=" << (Bit_double(0) / Bit_double(0)) << std::endl;
	//test0
	Bit_double pi_approx = 0.0;
	for (long long int i = 0; i < 1000000000; i++) {
		double term = (i % 2 == 0 ? 1.0 : -1.0) / (2.0 * i + 1.0);
		pi_approx = pi_approx + Bit_double(term);
	}
	Bit_double pi_estimate = pi_approx * Bit_double(4.0);
	std::cout << "$pi=" << pi_estimate << std::endl;
	return 0;
}