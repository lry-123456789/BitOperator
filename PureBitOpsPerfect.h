#ifndef PURE_BIT_CALCULATOR_PERFECT_H
#define PURE_BIT_CALCULATOR_PERFECT_H

#include <cstdint>
#include <cstring>
#include <iostream>
#include <ostream>
#include <istream>

// 100%准确的纯位运算工具类
class PureBitOpsPerfect {
public:
    // 基础32位运算
    static uint32_t add32(uint32_t a, uint32_t b);
    static uint32_t sub32(uint32_t a, uint32_t b);
    static uint32_t mul32(uint32_t a, uint32_t b);
    static uint32_t div32(uint32_t a, uint32_t b);
    static uint32_t mod32(uint32_t a, uint32_t b);

    // 基础64位运算
    static uint64_t add64(uint64_t a, uint64_t b);
    static uint64_t sub64(uint64_t a, uint64_t b);
    static uint64_t mul64(uint64_t a, uint64_t b);
    static uint64_t div64(uint64_t a, uint64_t b);
    static uint64_t mod64(uint64_t a, uint64_t b);

    // 基础16位运算
    static uint16_t add16(uint16_t a, uint16_t b);
    static uint16_t sub16(uint16_t a, uint16_t b);
    static uint16_t mul16(uint16_t a, uint16_t b);
    static uint16_t div16(uint16_t a, uint16_t b);
    static uint16_t mod16(uint16_t a, uint16_t b);

    // 基础8位运算
    static uint8_t add8(uint8_t a, uint8_t b);
    static uint8_t sub8(uint8_t a, uint8_t b);
    static uint8_t mul8(uint8_t a, uint8_t b);
    static uint8_t div8(uint8_t a, uint8_t b);
    static uint8_t mod8(uint8_t a, uint8_t b);

    // 比较函数
    static bool isEqual32(uint32_t a, uint32_t b);
    static bool isEqual64(uint64_t a, uint64_t b);
    static bool isEqual16(uint16_t a, uint16_t b);
    static bool isEqual8(uint8_t a, uint8_t b);
    static bool isLessSigned32(uint32_t a, uint32_t b);
    static bool isLessSigned64(uint64_t a, uint64_t b);
    static bool isLessSigned16(uint16_t a, uint16_t b);
    static bool isLessSigned8(uint8_t a, uint8_t b);
    static bool isLessUnsigned32(uint32_t a, uint32_t b);
    static bool isLessUnsigned64(uint64_t a, uint64_t b);
    static bool isLessUnsigned16(uint16_t a, uint16_t b);
    static bool isLessUnsigned8(uint8_t a, uint8_t b);
    static bool isGreaterOrEqualUnsigned64(uint64_t a, uint64_t b);
    static bool isGreaterOrEqualUnsigned32(uint32_t a, uint32_t b);
    static bool isGreaterOrEqualUnsigned16(uint16_t a, uint16_t b);
    static bool isGreaterOrEqualUnsigned8(uint8_t a, uint8_t b);

    // IEEE754浮点运算
    static uint32_t floatMul(uint32_t aBits, uint32_t bBits);
    static uint32_t floatAdd(uint32_t aBits, uint32_t bBits);
    static uint32_t floatSub(uint32_t aBits, uint32_t bBits);
    static uint32_t floatDiv(uint32_t aBits, uint32_t bBits);
    static bool floatLess(uint32_t aBits, uint32_t bBits);

    // 双精度运算
    static uint64_t doubleAdd(uint64_t aBits, uint64_t bBits);
    static uint64_t doubleSub(uint64_t aBits, uint64_t bBits);
    static uint64_t doubleMul(uint64_t a, uint64_t b);
    static uint64_t doubleDiv(uint64_t a, uint64_t b);
    static bool doubleLess(uint64_t aBits, uint64_t bBits);
};

// 100%准确的模板类
template<typename T>
class PureBitCalculatorPerfect {
private:
    T data;

public:
    PureBitCalculatorPerfect();
    PureBitCalculatorPerfect(T value);
    PureBitCalculatorPerfect(const PureBitCalculatorPerfect& other);

    PureBitCalculatorPerfect& operator=(const PureBitCalculatorPerfect& other);

    // 运算符声明
    PureBitCalculatorPerfect operator+(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator-(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator*(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator/(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator%(const PureBitCalculatorPerfect& other) const;

    PureBitCalculatorPerfect operator~() const;
    PureBitCalculatorPerfect operator<<(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator>>(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator^(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator|(const PureBitCalculatorPerfect& other) const;
    PureBitCalculatorPerfect operator&(const PureBitCalculatorPerfect& other) const;

    PureBitCalculatorPerfect& operator++();
    PureBitCalculatorPerfect operator++(int);
    PureBitCalculatorPerfect& operator--();
    PureBitCalculatorPerfect operator--(int);

    bool operator==(const PureBitCalculatorPerfect& other) const;
    bool operator!=(const PureBitCalculatorPerfect& other) const;
    bool operator<(const PureBitCalculatorPerfect& other) const;
    bool operator>(const PureBitCalculatorPerfect& other) const;
    bool operator<=(const PureBitCalculatorPerfect& other) const;
    bool operator>=(const PureBitCalculatorPerfect& other) const;

    bool operator&&(const PureBitCalculatorPerfect& other) const;
    bool operator||(const PureBitCalculatorPerfect& other) const;
    bool operator!() const;

    operator T() const;
    bool isZero() const;

    // 流操作符友元函数声明
    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const PureBitCalculatorPerfect<U>& obj);

    template<typename U>
    friend std::istream& operator>>(std::istream& is, PureBitCalculatorPerfect<U>& obj);
};

// 简洁的类型别名 - 支持直接赋值语法
using Bit_int32 = PureBitCalculatorPerfect<int32_t>;
using Bit_uint32 = PureBitCalculatorPerfect<uint32_t>;
using Bit_int64 = PureBitCalculatorPerfect<int64_t>;
using Bit_uint64 = PureBitCalculatorPerfect<uint64_t>;
using Bit_int16 = PureBitCalculatorPerfect<int16_t>;
using Bit_uint16 = PureBitCalculatorPerfect<uint16_t>;
using Bit_int8 = PureBitCalculatorPerfect<int8_t>;
using Bit_uint8 = PureBitCalculatorPerfect<uint8_t>;
using Bit_float = PureBitCalculatorPerfect<float>;
using Bit_double = PureBitCalculatorPerfect<double>;

// 保留原有别名以兼容
using PureBitInt32Perfect = PureBitCalculatorPerfect<int32_t>;
using PureBitUInt32Perfect = PureBitCalculatorPerfect<uint32_t>;
using PureBitInt64Perfect = PureBitCalculatorPerfect<int64_t>;
using PureBitUInt64Perfect = PureBitCalculatorPerfect<uint64_t>;
using PureBitInt16Perfect = PureBitCalculatorPerfect<int16_t>;
using PureBitUInt16Perfect = PureBitCalculatorPerfect<uint16_t>;
using PureBitInt8Perfect = PureBitCalculatorPerfect<int8_t>;
using PureBitUInt8Perfect = PureBitCalculatorPerfect<uint8_t>;
using PureBitFloatPerfect = PureBitCalculatorPerfect<float>;
using PureBitDoublePerfect = PureBitCalculatorPerfect<double>;

// 流操作符实现
template<typename T>
std::ostream& operator<<(std::ostream& os, const PureBitCalculatorPerfect<T>& obj);

template<typename T>
std::istream& operator>>(std::istream& is, PureBitCalculatorPerfect<T>& obj);

#endif