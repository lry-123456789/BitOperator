#include "PureBitOpsPerfect.h"

// ==================== PureBitOpsPerfect 实现 ====================

// 基础32位运算
uint32_t PureBitOpsPerfect::add32(uint32_t a, uint32_t b) {
    while (b) {
        uint32_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

uint32_t PureBitOpsPerfect::sub32(uint32_t a, uint32_t b) {
    return add32(a, add32(~b, 1));
}

uint32_t PureBitOpsPerfect::mul32(uint32_t a, uint32_t b) {
    uint32_t result = 0;
    while (b) {
        if (b & 1) {
            result = add32(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}

uint32_t PureBitOpsPerfect::div32(uint32_t a, uint32_t b) {
    if (!b) return 0;
    uint32_t quotient = 0;
    uint32_t i = 32;
    while (i) {
        i = sub32(i, 1);
        if (isGreaterOrEqualUnsigned32(a >> i, b)) {
            quotient = quotient | (1U << i);
            a = sub32(a, b << i);
        }
    }
    return quotient;
}

uint32_t PureBitOpsPerfect::mod32(uint32_t a, uint32_t b) {
    if (!b) return 0;
    return sub32(a, mul32(div32(a, b), b));
}

// 基础64位运算
uint64_t PureBitOpsPerfect::add64(uint64_t a, uint64_t b) {
    while (b) {
        uint64_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

uint64_t PureBitOpsPerfect::sub64(uint64_t a, uint64_t b) {
    return add64(a, add64(~b, 1));
}

uint64_t PureBitOpsPerfect::mul64(uint64_t a, uint64_t b) {
    uint64_t result = 0;
    while (b) {
        if (b & 1) {
            result = add64(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}

uint64_t PureBitOpsPerfect::div64(uint64_t a, uint64_t b) {
    if (!b) return 0;
    uint64_t quotient = 0;
    uint32_t i = 64;
    while (i) {
        i = sub32(i, 1);
        if (isGreaterOrEqualUnsigned64(a >> i, b)) {
            quotient = quotient | (1ULL << i);
            a = sub64(a, b << i);
        }
    }
    return quotient;
}

uint64_t PureBitOpsPerfect::mod64(uint64_t a, uint64_t b) {
    if (!b) return 0;
    return sub64(a, mul64(div64(a, b), b));
}

// 基础16位运算
uint16_t PureBitOpsPerfect::add16(uint16_t a, uint16_t b) {
    while (b) {
        uint16_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

uint16_t PureBitOpsPerfect::sub16(uint16_t a, uint16_t b) {
    return add16(a, add16(~b, 1));
}

uint16_t PureBitOpsPerfect::mul16(uint16_t a, uint16_t b) {
    uint16_t result = 0;
    while (b) {
        if (b & 1) {
            result = add16(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}

uint16_t PureBitOpsPerfect::div16(uint16_t a, uint16_t b) {
    if (!b) return 0;
    uint16_t quotient = 0;
    uint16_t i = 16;
    while (i) {
        i = sub16(i, 1);
        if (isGreaterOrEqualUnsigned16(a >> i, b)) {
            quotient = quotient | (1U << i);
            a = sub16(a, b << i);
        }
    }
    return quotient;
}

uint16_t PureBitOpsPerfect::mod16(uint16_t a, uint16_t b) {
    if (!b) return 0;
    return sub16(a, mul16(div16(a, b), b));
}

// 基础8位运算
uint8_t PureBitOpsPerfect::add8(uint8_t a, uint8_t b) {
    while (b) {
        uint8_t carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

uint8_t PureBitOpsPerfect::sub8(uint8_t a, uint8_t b) {
    return add8(a, add8(~b, 1));
}

uint8_t PureBitOpsPerfect::mul8(uint8_t a, uint8_t b) {
    uint8_t result = 0;
    while (b) {
        if (b & 1) {
            result = add8(result, a);
        }
        a = a << 1;
        b = b >> 1;
    }
    return result;
}

uint8_t PureBitOpsPerfect::div8(uint8_t a, uint8_t b) {
    if (!b) return 0;
    uint8_t quotient = 0;
    uint8_t i = 8;
    while (i) {
        i = sub8(i, 1);
        if (isGreaterOrEqualUnsigned8(a >> i, b)) {
            quotient = quotient | (1U << i);
            a = sub8(a, b << i);
        }
    }
    return quotient;
}

uint8_t PureBitOpsPerfect::mod8(uint8_t a, uint8_t b) {
    if (!b) return 0;
    return sub8(a, mul8(div8(a, b), b));
}

// 比较函数
bool PureBitOpsPerfect::isEqual32(uint32_t a, uint32_t b) {
    return (a ^ b) == 0;
}

bool PureBitOpsPerfect::isEqual64(uint64_t a, uint64_t b) {
    return (a ^ b) == 0;
}

bool PureBitOpsPerfect::isEqual16(uint16_t a, uint16_t b) {
    return (a ^ b) == 0;
}

bool PureBitOpsPerfect::isEqual8(uint8_t a, uint8_t b) {
    return (a ^ b) == 0;
}

bool PureBitOpsPerfect::isLessSigned32(uint32_t a, uint32_t b) {
    bool signA = (a >> 31) & 1;
    bool signB = (b >> 31) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // 相同符号时进行纯位运算比较
    if (signA) {
        // 两个负数：较大的位模式表示较小的数值
        return isLessUnsigned32(b & 0x7FFFFFFF, a & 0x7FFFFFFF);
    }
    else {
        // 两个正数：直接比较位模式
        return isLessUnsigned32(a & 0x7FFFFFFF, b & 0x7FFFFFFF);
    }
}

bool PureBitOpsPerfect::isLessSigned64(uint64_t a, uint64_t b) {
    bool signA = (a >> 63) & 1;
    bool signB = (b >> 63) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // 相同符号时进行纯位运算比较
    if (signA) {
        // 两个负数：较大的位模式表示较小的数值
        return isLessUnsigned64(b & 0x7FFFFFFFFFFFFFFFULL, a & 0x7FFFFFFFFFFFFFFFULL);
    }
    else {
        // 两个正数：直接比较位模式
        return isLessUnsigned64(a & 0x7FFFFFFFFFFFFFFFULL, b & 0x7FFFFFFFFFFFFFFFULL);
    }
}

bool PureBitOpsPerfect::isLessUnsigned32(uint32_t a, uint32_t b) {
    // 纯位运算实现无符号整数比较
    // 从最高位开始逐位比较
    for (int i = 31; i >= 0; i--) {
        uint32_t bitA = (a >> i) & 1;
        uint32_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, 继续比较下一位
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessUnsigned64(uint64_t a, uint64_t b) {
    // 纯位运算实现无符号整数比较
    // 从最高位开始逐位比较
    for (int i = 63; i >= 0; i--) {
        uint64_t bitA = (a >> i) & 1;
        uint64_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, 继续比較下一位
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessSigned16(uint16_t a, uint16_t b) {
    bool signA = (a >> 15) & 1;
    bool signB = (b >> 15) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // 相同符号时进行纯位运算比较
    if (signA) {
        // 两个负数：较大的位模式表示较小的数值
        return isLessUnsigned16(b & 0x7FFF, a & 0x7FFF);
    }
    else {
        // 两个正数：直接比较位模式
        return isLessUnsigned16(a & 0x7FFF, b & 0x7FFF);
    }
}

bool PureBitOpsPerfect::isLessSigned8(uint8_t a, uint8_t b) {
    bool signA = (a >> 7) & 1;
    bool signB = (b >> 7) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // 相同符号时进行纯位运算比较
    if (signA) {
        // 两个负数：较大的位模式表示较小的数值
        return isLessUnsigned8(b & 0x7F, a & 0x7F);
    }
    else {
        // 两个正数：直接比较位模式
        return isLessUnsigned8(a & 0x7F, b & 0x7F);
    }
}

bool PureBitOpsPerfect::isLessUnsigned16(uint16_t a, uint16_t b) {
    // 纯位运算实现无符号整数比较
    // 从最高位开始逐位比较
    for (int i = 15; i >= 0; i--) {
        uint16_t bitA = (a >> i) & 1;
        uint16_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, 继续比較下一位
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessUnsigned8(uint8_t a, uint8_t b) {
    // 纯位运算实现无符号整数比较
    // 从最高位开始逐位比较
    for (int i = 7; i >= 0; i--) {
        uint8_t bitA = (a >> i) & 1;
        uint8_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, 继续比較下一位
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isGreaterOrEqualUnsigned64(uint64_t a, uint64_t b) {
    return !isLessUnsigned64(a, b);
}

bool PureBitOpsPerfect::isGreaterOrEqualUnsigned32(uint32_t a, uint32_t b) {
    return !isLessUnsigned32(a, b);
}

bool PureBitOpsPerfect::isGreaterOrEqualUnsigned16(uint16_t a, uint16_t b) {
    return !isLessUnsigned16(a, b);
}

bool PureBitOpsPerfect::isGreaterOrEqualUnsigned8(uint8_t a, uint8_t b) {
    return !isLessUnsigned8(a, b);
}

// IEEE754浮点运算
uint32_t PureBitOpsPerfect::floatMul(uint32_t aBits, uint32_t bBits) {
    if (!aBits || !bBits) return 0;

    uint32_t aAbs = aBits & 0x7FFFFFFF;
    uint32_t bAbs = bBits & 0x7FFFFFFF;
    if (aAbs == 0x7F800000 || bAbs == 0x7F800000) {
        return ((aBits ^ bBits) & 0x80000000) | 0x7F800000;
    }

    uint32_t signA = aBits & 0x80000000;
    uint32_t signB = bBits & 0x80000000;
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = (aBits & 0x7FFFFF);
    uint32_t mantB = (bBits & 0x7FFFFF);

    uint32_t resultSign = signA ^ signB;

    if (expA == 0) {
        if (mantA == 0) return resultSign;
        while (!(mantA & 0x800000)) {
            mantA = mantA << 1;
            expA = sub32(expA, 1);
        }
        expA = add32(expA, 1);
    }
    else {
        mantA = mantA | 0x800000;
    }

    if (expB == 0) {
        if (mantB == 0) return resultSign;
        while (!(mantB & 0x800000)) {
            mantB = mantB << 1;
            expB = sub32(expB, 1);
        }
        expB = add32(expB, 1);
    }
    else {
        mantB = mantB | 0x800000;
    }

    uint32_t resultExp = add32(add32(expA, expB), sub32(0, 127));

    uint64_t mantResult = mul64(mantA, mantB);

    if (mantResult & 0x800000000000ULL) {
        mantResult = mantResult >> 1;
        resultExp = add32(resultExp, 1);
    }

    uint32_t finalMant = (mantResult >> 23) & 0x7FFFFF;

    if (resultExp >= 0xFF) {
        return resultSign | 0x7F800000;
    }
    if (resultExp == 0 || (resultExp & 0x80000000)) {
        return resultSign;
    }

    return resultSign | (resultExp << 23) | finalMant;
}

uint32_t PureBitOpsPerfect::floatAdd(uint32_t aBits, uint32_t bBits) {
    if (!aBits) return bBits;
    if (!bBits) return aBits;

    uint32_t signA = aBits & 0x80000000;
    uint32_t signB = bBits & 0x80000000;
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = (aBits & 0x7FFFFF) | (expA ? 0x800000 : 0);
    uint32_t mantB = (bBits & 0x7FFFFF) | (expB ? 0x800000 : 0);

    if (expA < expB) {
        uint32_t diff = sub32(expB, expA);
        if (diff > 24) return bBits;
        mantA = mantA >> diff;
        expA = expB;
    }
    else if (expB < expA) {
        uint32_t diff = sub32(expA, expB);
        if (diff > 24) return aBits;
        mantB = mantB >> diff;
        expB = expA;
    }

    uint32_t resultMant;
    uint32_t resultSign;
    uint32_t resultExp = expA;

    if (signA == signB) {
        resultMant = add32(mantA, mantB);
        resultSign = signA;
    }
    else {
        if (mantA >= mantB) {
            resultMant = sub32(mantA, mantB);
            resultSign = signA;
        }
        else {
            resultMant = sub32(mantB, mantA);
            resultSign = signB;
        }
    }

    if (!resultMant) return 0;

    if (resultMant & 0x1000000) {
        resultMant = resultMant >> 1;
        resultExp = add32(resultExp, 1);
    }
    else {
        while (!(resultMant & 0x800000) && resultExp) {
            resultMant = resultMant << 1;
            resultExp = sub32(resultExp, 1);
        }
    }

    if (resultExp >= 0xFF) {
        return resultSign | 0x7F800000;
    }

    if (resultExp) {
        resultMant = resultMant & 0x7FFFFF;
    }
    else {
        resultMant = resultMant >> 1;
    }

    return resultSign | (resultExp << 23) | resultMant;
}

uint32_t PureBitOpsPerfect::floatSub(uint32_t aBits, uint32_t bBits) {
    return floatAdd(aBits, bBits ^ 0x80000000);
}

uint32_t PureBitOpsPerfect::floatDiv(uint32_t aBits, uint32_t bBits) {
    // 提取IEEE754组件
    uint32_t signA = aBits & 0x80000000;
    uint32_t signB = bBits & 0x80000000;
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = aBits & 0x7FFFFF;
    uint32_t mantB = bBits & 0x7FFFFF;
    uint32_t resultSign = signA ^ signB;

    // 处理特殊情况

    // 检查A是否为NaN
    if (expA == 0xFF && mantA != 0) {
        return aBits; // 传播NaN
    }

    // 检查B是否为NaN
    if (expB == 0xFF && mantB != 0) {
        return bBits; // 传播NaN
    }

    // 检查A是否为无穷大
    if (expA == 0xFF && mantA == 0) {
        if (expB == 0xFF && mantB == 0) {
            // ∞ / ∞ = NaN
            return 0x7FC00000; // Quiet NaN
        }
        // ∞ / finite = ±∞
        return resultSign | 0x7F800000;
    }

    // 检查B是否为无穷大
    if (expB == 0xFF && mantB == 0) {
        // finite / ∞ = ±0
        return resultSign;
    }

    // 检查A是否为0
    if (expA == 0 && mantA == 0) {
        if (expB == 0 && mantB == 0) {
            // 0 / 0 = NaN
            return 0x7FC00000; // Quiet NaN
        }
        // 0 / finite = ±0
        return resultSign;
    }

    // 检查B是否为0
    if (expB == 0 && mantB == 0) {
        // finite / 0 = ±∞
        return resultSign | 0x7F800000;
    }

    // 正常数值计算
    uint64_t extMantA, extMantB;
    int32_t biasedExpA = expA, biasedExpB = expB;

    // 处理非规格化数
    if (expA == 0) {
        biasedExpA = 1;
        extMantA = (uint64_t)mantA << 23;
    }
    else {
        extMantA = ((uint64_t)(mantA | 0x800000)) << 23;
    }

    if (expB == 0) {
        biasedExpB = 1;
        extMantB = mantB | 0x800000;
    }
    else {
        extMantB = mantB | 0x800000;
    }

    int32_t resultExp = biasedExpA - biasedExpB + 127;
    uint64_t resultMant = div64(extMantA, extMantB);

    // 规格化结果
    if (resultMant & 0x1000000) {
        resultMant = resultMant >> 1;
        resultExp++;
    }

    resultMant = resultMant & 0x7FFFFF;

    // 检查指数溢出和下溢
    if (resultExp >= 0xFF) {
        return resultSign | 0x7F800000; // ±∞
    }
    if (resultExp <= 0) {
        return resultSign; // ±0 (简化处理)
    }

    return resultSign | ((uint32_t)resultExp << 23) | ((uint32_t)resultMant);
}

bool PureBitOpsPerfect::floatLess(uint32_t aBits, uint32_t bBits) {
    // 提取符号位
    bool signA = (aBits >> 31) & 1;
    bool signB = (bBits >> 31) & 1;

    // 处理特殊情况：NaN
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = aBits & 0x7FFFFF;
    uint32_t mantB = bBits & 0x7FFFFF;

    // NaN永远不小于任何数
    if ((expA == 0xFF && mantA != 0) || (expB == 0xFF && mantB != 0)) {
        return false;
    }

    // 不同符号比较
    if (signA && !signB) return true;  // 负数 < 正数
    if (!signA && signB) return false; // 正数 > 负数

    // 相同符号比较
    if (signA) {
        // 两个都是负数：比较位模式，大的位模式对应小的数值
        return isLessUnsigned32(bBits & 0x7FFFFFFF, aBits & 0x7FFFFFFF);
    }
    else {
        // 两个都是正数：直接比较位模式
        return isLessUnsigned32(aBits & 0x7FFFFFFF, bBits & 0x7FFFFFFF);
    }
}

bool PureBitOpsPerfect::doubleLess(uint64_t aBits, uint64_t bBits) {
    // 提取符号位
    bool signA = (aBits >> 63) & 1;
    bool signB = (bBits >> 63) & 1;

    // 处理特殊情况：NaN
    uint64_t expA = (aBits >> 52) & 0x7FF;
    uint64_t expB = (bBits >> 52) & 0x7FF;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    // NaN永远不小于任何数
    if ((expA == 0x7FF && mantA != 0) || (expB == 0x7FF && mantB != 0)) {
        return false;
    }

    // 不同符号比较
    if (signA && !signB) return true;  // 负数 < 正数
    if (!signA && signB) return false; // 正数 > 负数

    // 相同符号比较
    if (signA) {
        // 两个都是负数：比较位模式，大的位模式对应小的数值
        return isLessUnsigned64(bBits & 0x7FFFFFFFFFFFFFFFULL, aBits & 0x7FFFFFFFFFFFFFFFULL);
    }
    else {
        // 两个都是正数：直接比较位模式
        return isLessUnsigned64(aBits & 0x7FFFFFFFFFFFFFFFULL, bBits & 0x7FFFFFFFFFFFFFFFULL);
    }
}

// 双精度运算 - 纯位运算精确实现
uint64_t PureBitOpsPerfect::doubleAdd(uint64_t aBits, uint64_t bBits) {
    if (!aBits) return bBits;
    if (!bBits) return aBits;

    // 提取IEEE754组件
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FFULL;
    uint64_t expB = (bBits >> 52) & 0x7FFULL;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    // 处理特殊情况：NaN
    if ((expA == 0x7FF && mantA != 0) || (expB == 0x7FF && mantB != 0)) {
        // 传播NaN，优先传播signaling NaN
        if (expA == 0x7FF && mantA != 0) return aBits;
        return bBits;
    }

    // 处理特殊情况：无穷大
    if (expA == 0x7FF && mantA == 0) { // A是无穷大
        if (expB == 0x7FF && mantB == 0) { // B也是无穷大
            if (signA == signB) {
                return aBits; // 同号无穷大相加 = 无穷大
            }
            else {
                return 0x7FF8000000000000ULL; // 异号无穷大相加 = NaN
            }
        }
        return aBits; // 无穷大 + 有限数 = 无穷大
    }

    if (expB == 0x7FF && mantB == 0) { // B是无穷大
        return bBits; // 有限数 + 无穷大 = 无穷大
    }

    // 添加隐含的1位（规格化数）或处理非规格化数
    if (expA == 0) {
        if (mantA == 0) return bBits;  // A是0
    }
    else {
        mantA = mantA | 0x10000000000000ULL;  // 添加隐含的1
    }

    if (expB == 0) {
        if (mantB == 0) return aBits;  // B是0
    }
    else {
        mantB = mantB | 0x10000000000000ULL;  // 添加隐含的1
    }

    // 对齐指数 - 让较小指数的尾数右移
    if (expA < expB) {
        uint64_t diff = sub64(expB, expA);
        if (diff > 54) return bBits;  // A太小，忽略
        mantA = mantA >> diff;
        expA = expB;
    }
    else if (expB < expA) {
        uint64_t diff = sub64(expA, expB);
        if (diff > 54) return aBits;  // B太小，忽略
        mantB = mantB >> diff;
    }

    uint64_t resultSign, resultExp, resultMant;
    resultExp = expA;

    // 执行加法或减法
    if (signA == signB) {
        // 相同符号：执行加法
        resultSign = signA;
        resultMant = add64(mantA, mantB);

        // 检查是否溢出（需要右移1位并增加指数）
        if (resultMant & 0x20000000000000ULL) {
            resultMant = resultMant >> 1;
            resultExp = add64(resultExp, 1);
        }
    }
    else {
        // 不同符号：执行减法
        if (mantA >= mantB) {
            resultSign = signA;
            resultMant = sub64(mantA, mantB);
        }
        else {
            resultSign = signB;
            resultMant = sub64(mantB, mantA);
        }

        // 规格化结果（左移直到最高位为1）
        if (resultMant == 0) return resultSign;  // 结果为0

        while (!(resultMant & 0x10000000000000ULL) && resultExp > 0) {
            resultMant = resultMant << 1;
            resultExp = sub64(resultExp, 1);
        }
    }

    // 检查指数溢出
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;  // 无穷大
    }

    // 处理结果为非规格化数
    if (resultExp == 0) {
        return resultSign | (resultMant & 0xFFFFFFFFFFFFFULL);
    }

    // 移除隐含的1位并组装结果
    resultMant = resultMant & 0xFFFFFFFFFFFFFULL;
    return resultSign | (resultExp << 52) | resultMant;
}

uint64_t PureBitOpsPerfect::doubleSub(uint64_t aBits, uint64_t bBits) {
    return doubleAdd(aBits, bBits ^ 0x8000000000000000ULL);
}

uint64_t PureBitOpsPerfect::doubleMul(uint64_t aBits, uint64_t bBits) {
    if (!aBits || !bBits) return 0;

    // 提取IEEE754组件
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FFULL;
    uint64_t expB = (bBits >> 52) & 0x7FFULL;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    uint64_t resultSign = signA ^ signB;

    // 处理特殊情况
    if (expA == 0x7FF || expB == 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;  // 无穷大或NaN
    }

    // 处理零
    if ((expA == 0 && mantA == 0) || (expB == 0 && mantB == 0)) {
        return resultSign;  // 结果为0
    }

    // 正确处理规格化和非规格化数
    uint64_t biasedExpA = expA;
    uint64_t biasedExpB = expB;

    if (expA == 0) {
        // 非规格化数：指数视为1，尾数不添加隐含1
        biasedExpA = 1;
        if (mantA == 0) return resultSign; // A是零
    }
    else {
        // 规格化数：添加隐含的1位
        mantA = mantA | 0x10000000000000ULL;
    }

    if (expB == 0) {
        // 非规格化数：指数视为1，尾数不添加隐含1
        biasedExpB = 1;
        if (mantB == 0) return resultSign; // B是零
    }
    else {
        // 规格化数：添加隐含的1位
        mantB = mantB | 0x10000000000000ULL;
    }

    // 计算结果指数 - 使用偏置指数
    uint64_t tempExp = add64(biasedExpA, biasedExpB);
    uint64_t resultExp;
    if (tempExp >= 1023) {
        resultExp = sub64(tempExp, 1023);
    }
    else {
        return resultSign; // 指数下溢
    }

    // IEEE754兼容的高精度乘法实现
    // 使用128位算术来处理53位×53位的乘法

    // 将53位尾数分解为高低两部分进行精确乘法
    uint64_t aHigh = mantA >> 26; // 高27位
    uint64_t aLow = mantA & 0x3FFFFFFULL; // 低26位
    uint64_t bHigh = mantB >> 26; // 高27位
    uint64_t bLow = mantB & 0x3FFFFFFULL; // 低26位

    // 计算四个部分积：(aHigh*2^26 + aLow) * (bHigh*2^26 + bLow)
    // = aHigh*bHigh*2^52 + (aHigh*bLow + aLow*bHigh)*2^26 + aLow*bLow
    uint64_t prodHH = mul64(aHigh, bHigh);   // 最高位部分
    uint64_t prodHL = mul64(aHigh, bLow);    // 中间部分1
    uint64_t prodLH = mul64(aLow, bHigh);    // 中间部分2
    uint64_t prodLL = mul64(aLow, bLow);     // 最低位部分

    // 组装106位的乘积结果
    // 最终结果的结构：[prodHH:52] + [prodHL+prodLH:26] + [prodLL:0]
    uint64_t resultHigh = prodHH;
    uint64_t resultMid = add64(prodHL, prodLH);
    uint64_t resultLow = prodLL;

    // 处理进位：将中间部分的高位加到高位部分
    resultHigh = add64(resultHigh, resultMid >> 26);
    resultMid = resultMid & 0x3FFFFFFULL;

    // 现在我们有一个106位的结果，需要规格化到53位精度
    uint64_t resultMant;

    // 检查最高位是否设置（overflow情况）
    if (resultHigh & 0x20000000000000ULL) {
        // 需要右移1位并调整指数
        resultMant = (resultHigh >> 1) | ((resultMid & 0x2000000ULL) ? 0x8000000000000ULL : 0);
        resultExp = add64(resultExp, 1);

        // 保留guard、round、sticky位用于舍入
        uint64_t guard = resultMid & 0x2000000ULL; // bit 25
        uint64_t round_bit = resultMid & 0x1000000ULL; // bit 24
        uint64_t sticky = (resultMid & 0xFFFFFFULL) | resultLow; // 其余所有位

        // IEEE754舍入到最近偶数
        if (guard) {
            if (round_bit || sticky || (resultMant & 1)) {
                resultMant = add64(resultMant, 1);
                // 检查舍入后溢出
                if (resultMant & 0x20000000000000ULL) {
                    resultMant = resultMant >> 1;
                    resultExp = add64(resultExp, 1);
                }
            }
        }
    }
    else {
        // 正常情况，最高位在bit 52
        resultMant = resultHigh;

        // 保留guard、round、sticky位用于舍入
        uint64_t guard = resultMid >> 25; // bit 25
        uint64_t round_bit = (resultMid >> 24) & 1; // bit 24
        uint64_t sticky = (resultMid & 0xFFFFFFULL) | resultLow; // 其余所有位

        // IEEE754舍入到最近偶数
        if (guard) {
            if (round_bit || sticky || (resultMant & 1)) {
                resultMant = add64(resultMant, 1);
                // 检查舍入后溢出
                if (resultMant & 0x20000000000000ULL) {
                    resultMant = resultMant >> 1;
                    resultExp = add64(resultExp, 1);
                }
            }
        }
    }

    // 检查指数溢出和下溢
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;
    }
    if (resultExp == 0) {
        return resultSign;
    }

    // 移除隐含的1位并组装结果
    resultMant = resultMant & 0xFFFFFFFFFFFFFULL;
    return resultSign | (resultExp << 52) | resultMant;
}

uint64_t PureBitOpsPerfect::doubleDiv(uint64_t aBits, uint64_t bBits) {
    // 提取IEEE754组件
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FF;
    uint64_t expB = (bBits >> 52) & 0x7FF;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;
    uint64_t resultSign = signA ^ signB;

    // 处理特殊情况

    // 检查A是否为NaN
    if (expA == 0x7FF && mantA != 0) {
        return aBits; // 传播NaN
    }

    // 检查B是否为NaN
    if (expB == 0x7FF && mantB != 0) {
        return bBits; // 传播NaN
    }

    // 检查A是否为无穷大
    if (expA == 0x7FF && mantA == 0) {
        if (expB == 0x7FF && mantB == 0) {
            // ∞ / ∞ = NaN
            return 0x7FF8000000000000ULL; // Quiet NaN
        }
        // ∞ / finite = ±∞
        return resultSign | 0x7FF0000000000000ULL;
    }

    // 检查B是否为无穷大
    if (expB == 0x7FF && mantB == 0) {
        // finite / ∞ = ±0
        return resultSign;
    }

    // 检查A是否为0
    if (expA == 0 && mantA == 0) {
        if (expB == 0 && mantB == 0) {
            // 0 / 0 = NaN
            return 0x7FF8000000000000ULL; // Quiet NaN
        }
        // 0 / finite = ±0
        return resultSign;
    }

    // 检查B是否为0
    if (expB == 0 && mantB == 0) {
        // finite / 0 = ±∞
        return resultSign | 0x7FF0000000000000ULL;
    }

    // 正常数值计算
    int64_t biasedExpA = expA, biasedExpB = expB;

    // 处理规格化数：添加隐含的1位
    if (expA != 0) {
        mantA |= 0x10000000000000ULL;
    }
    else {
        // 非规格化数处理
        biasedExpA = 1;
        // mantA保持原样，不添加隐含1位
    }

    if (expB != 0) {
        mantB |= 0x10000000000000ULL;
    }
    else {
        // 非规格化数处理
        biasedExpB = 1;
        // mantB保持原样，不添加隐含1位
    }

    // 计算结果指数
    int64_t resultExp = biasedExpA - biasedExpB + 1023;

    // 高精度除法实现
    // 为了得到准确的53位精度结果，我们需要进行扩展精度的除法
    // 将被除数扩展到更高精度
    uint64_t quotient = 0;
    uint64_t remainder = mantA;

    // 执行长除法算法，生成53位精度的商
    for (int i = 52; i >= 0; i--) {
        if (isGreaterOrEqualUnsigned64(remainder, mantB)) {
            quotient |= (1ULL << i);
            remainder = sub64(remainder, mantB);
        }
        // 左移remainder以准备下一位的计算
        if (i > 0) {
            remainder = remainder << 1;
        }
    }

    // 规格化结果
    uint64_t resultMant;
    if (quotient & 0x20000000000000ULL) {
        // quotient有54位，需要右移1位并调整指数
        resultMant = (quotient >> 1) & 0xFFFFFFFFFFFFFULL;
        resultExp = add64(resultExp, 1);
    }
    else if (quotient & 0x10000000000000ULL) {
        // quotient恰好是53位，已经规格化
        resultMant = quotient & 0xFFFFFFFFFFFFFULL;
    }
    else {
        // quotient小于53位，需要左移以规格化
        while (quotient && !(quotient & 0x10000000000000ULL) && resultExp > 0) {
            quotient = quotient << 1;
            resultExp = sub64(resultExp, 1);
        }
        resultMant = quotient & 0xFFFFFFFFFFFFFULL;
    }

    // 检查指数溢出和下溢
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL; // ±∞
    }
    if (resultExp <= 0) {
        return resultSign; // ±0 (简化的非规格化数处理)
    }

    return resultSign | ((uint64_t)resultExp << 52) | resultMant;
}


// ==================== PureBitCalculatorPerfect 模板实现 ====================

// 基本构造函数和运算符
template<typename T>
PureBitCalculatorPerfect<T>::PureBitCalculatorPerfect() : data(0) {}

template<typename T>
PureBitCalculatorPerfect<T>::PureBitCalculatorPerfect(T value) : data(value) {}

template<typename T>
PureBitCalculatorPerfect<T>::PureBitCalculatorPerfect(const PureBitCalculatorPerfect& other) : data(other.data) {}

template<typename T>
PureBitCalculatorPerfect<T>& PureBitCalculatorPerfect<T>::operator=(const PureBitCalculatorPerfect& other) {
    data = other.data;
    return *this;
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator~() const {
    return PureBitCalculatorPerfect(~data);
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator<<(const PureBitCalculatorPerfect& other) const {
    return PureBitCalculatorPerfect(data << other.data);
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator>>(const PureBitCalculatorPerfect& other) const {
    return PureBitCalculatorPerfect(data >> other.data);
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator^(const PureBitCalculatorPerfect& other) const {
    return PureBitCalculatorPerfect(data ^ other.data);
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator|(const PureBitCalculatorPerfect& other) const {
    return PureBitCalculatorPerfect(data | other.data);
}

template<typename T>
PureBitCalculatorPerfect<T> PureBitCalculatorPerfect<T>::operator&(const PureBitCalculatorPerfect& other) const {
    return PureBitCalculatorPerfect(data & other.data);
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator!=(const PureBitCalculatorPerfect& other) const {
    return !(operator==(other));
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator>(const PureBitCalculatorPerfect& other) const {
    return other.operator<(*this);
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator<=(const PureBitCalculatorPerfect& other) const {
    return !(operator>(other));
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator>=(const PureBitCalculatorPerfect& other) const {
    return !(operator<(other));
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator&&(const PureBitCalculatorPerfect& other) const {
    return (!isZero()) && (!other.isZero());
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator||(const PureBitCalculatorPerfect& other) const {
    return (!isZero()) || (!other.isZero());
}

template<typename T>
bool PureBitCalculatorPerfect<T>::operator!() const {
    return isZero();
}

template<typename T>
PureBitCalculatorPerfect<T>::operator T() const {
    return data;
}

template<typename T>
bool PureBitCalculatorPerfect<T>::isZero() const {
    return data == 0;
}

// ==================== 特化实现 ====================

// int32_t特化
template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator+(const PureBitCalculatorPerfect<int32_t>& other) const {
    return PureBitCalculatorPerfect<int32_t>(PureBitOpsPerfect::add32(data, other.data));
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator-(const PureBitCalculatorPerfect<int32_t>& other) const {
    return PureBitCalculatorPerfect<int32_t>(PureBitOpsPerfect::sub32(data, other.data));
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator*(const PureBitCalculatorPerfect<int32_t>& other) const {
    return PureBitCalculatorPerfect<int32_t>(PureBitOpsPerfect::mul32(data, other.data));
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator/(const PureBitCalculatorPerfect<int32_t>& other) const {
    bool signA = data & 0x80000000;
    bool signB = other.data & 0x80000000;
    uint32_t absA = signA ? PureBitOpsPerfect::sub32(0, data) : data;
    uint32_t absB = signB ? PureBitOpsPerfect::sub32(0, other.data) : other.data;
    uint32_t result = PureBitOpsPerfect::div32(absA, absB);
    return PureBitCalculatorPerfect<int32_t>((signA ^ signB) ? PureBitOpsPerfect::sub32(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator%(const PureBitCalculatorPerfect<int32_t>& other) const {
    bool signA = data & 0x80000000;
    uint32_t absA = signA ? PureBitOpsPerfect::sub32(0, data) : data;
    uint32_t absB = (other.data & 0x80000000) ? PureBitOpsPerfect::sub32(0, other.data) : other.data;
    uint32_t result = PureBitOpsPerfect::mod32(absA, absB);
    return PureBitCalculatorPerfect<int32_t>(signA ? PureBitOpsPerfect::sub32(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int32_t>& PureBitCalculatorPerfect<int32_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<int32_t>& PureBitCalculatorPerfect<int32_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int32_t> PureBitCalculatorPerfect<int32_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<int32_t>::operator==(const PureBitCalculatorPerfect<int32_t>& other) const {
    return PureBitOpsPerfect::isEqual32(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<int32_t>::operator<(const PureBitCalculatorPerfect<int32_t>& other) const {
    return PureBitOpsPerfect::isLessSigned32(data, other.data);
}

// uint32_t特化
template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator+(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitCalculatorPerfect<uint32_t>(PureBitOpsPerfect::add32(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator-(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitCalculatorPerfect<uint32_t>(PureBitOpsPerfect::sub32(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator*(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitCalculatorPerfect<uint32_t>(PureBitOpsPerfect::mul32(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator/(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitCalculatorPerfect<uint32_t>(PureBitOpsPerfect::div32(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator%(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitCalculatorPerfect<uint32_t>(PureBitOpsPerfect::mod32(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint32_t>& PureBitCalculatorPerfect<uint32_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<uint32_t>& PureBitCalculatorPerfect<uint32_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint32_t> PureBitCalculatorPerfect<uint32_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<uint32_t>::operator==(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitOpsPerfect::isEqual32(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<uint32_t>::operator<(const PureBitCalculatorPerfect<uint32_t>& other) const {
    return PureBitOpsPerfect::isLessUnsigned32(data, other.data);
}

// int64_t特化
template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator+(const PureBitCalculatorPerfect<int64_t>& other) const {
    return PureBitCalculatorPerfect<int64_t>(PureBitOpsPerfect::add64(data, other.data));
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator-(const PureBitCalculatorPerfect<int64_t>& other) const {
    return PureBitCalculatorPerfect<int64_t>(PureBitOpsPerfect::sub64(data, other.data));
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator*(const PureBitCalculatorPerfect<int64_t>& other) const {
    return PureBitCalculatorPerfect<int64_t>(PureBitOpsPerfect::mul64(data, other.data));
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator/(const PureBitCalculatorPerfect<int64_t>& other) const {
    bool signA = data & 0x8000000000000000ULL;
    bool signB = other.data & 0x8000000000000000ULL;
    uint64_t absA = signA ? PureBitOpsPerfect::sub64(0, data) : data;
    uint64_t absB = signB ? PureBitOpsPerfect::sub64(0, other.data) : other.data;
    uint64_t result = PureBitOpsPerfect::div64(absA, absB);
    return PureBitCalculatorPerfect<int64_t>((signA ^ signB) ? PureBitOpsPerfect::sub64(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator%(const PureBitCalculatorPerfect<int64_t>& other) const {
    bool signA = data & 0x8000000000000000ULL;
    uint64_t absA = signA ? PureBitOpsPerfect::sub64(0, data) : data;
    uint64_t absB = (other.data & 0x8000000000000000ULL) ? PureBitOpsPerfect::sub64(0, other.data) : other.data;
    uint64_t result = PureBitOpsPerfect::mod64(absA, absB);
    return PureBitCalculatorPerfect<int64_t>(signA ? PureBitOpsPerfect::sub64(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int64_t>& PureBitCalculatorPerfect<int64_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<int64_t>& PureBitCalculatorPerfect<int64_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int64_t> PureBitCalculatorPerfect<int64_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<int64_t>::operator==(const PureBitCalculatorPerfect<int64_t>& other) const {
    return PureBitOpsPerfect::isEqual64(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<int64_t>::operator<(const PureBitCalculatorPerfect<int64_t>& other) const {
    return PureBitOpsPerfect::isLessSigned64(data, other.data);
}

// uint64_t特化
template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator+(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitCalculatorPerfect<uint64_t>(PureBitOpsPerfect::add64(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator-(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitCalculatorPerfect<uint64_t>(PureBitOpsPerfect::sub64(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator*(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitCalculatorPerfect<uint64_t>(PureBitOpsPerfect::mul64(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator/(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitCalculatorPerfect<uint64_t>(PureBitOpsPerfect::div64(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator%(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitCalculatorPerfect<uint64_t>(PureBitOpsPerfect::mod64(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint64_t>& PureBitCalculatorPerfect<uint64_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<uint64_t>& PureBitCalculatorPerfect<uint64_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint64_t> PureBitCalculatorPerfect<uint64_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<uint64_t>::operator==(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitOpsPerfect::isEqual64(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<uint64_t>::operator<(const PureBitCalculatorPerfect<uint64_t>& other) const {
    return PureBitOpsPerfect::isLessUnsigned64(data, other.data);
}

// float特化
template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator+(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    resultBits = PureBitOpsPerfect::floatAdd(aBits, bBits);
    float result;
    std::memcpy(&result, &resultBits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator-(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    resultBits = PureBitOpsPerfect::floatSub(aBits, bBits);
    float result;
    std::memcpy(&result, &resultBits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator*(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    resultBits = PureBitOpsPerfect::floatMul(aBits, bBits);
    float result;
    std::memcpy(&result, &resultBits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator/(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    resultBits = PureBitOpsPerfect::floatDiv(aBits, bBits);
    float result;
    std::memcpy(&result, &resultBits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator%(const PureBitCalculatorPerfect<float>& other) const {
    PureBitCalculatorPerfect<float> div_result = this->operator/(other);
    int32_t truncated = (int32_t)div_result.data;
    PureBitCalculatorPerfect<float> truncated_float(truncated);
    PureBitCalculatorPerfect<float> mult_result = truncated_float.operator*(other);
    return this->operator-(mult_result);
}

template<>
PureBitCalculatorPerfect<float>& PureBitCalculatorPerfect<float>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1.0f));
    return *this;
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<float>& PureBitCalculatorPerfect<float>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1.0f));
    return *this;
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<float>::operator==(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    return PureBitOpsPerfect::isEqual32(aBits, bBits);
}

// float特化 - 位运算符
template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator~() const {
    uint32_t bits;
    std::memcpy(&bits, &data, sizeof(float));
    bits = ~bits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator<<(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(float));
    std::memcpy(&otherBits, &other.data, sizeof(float));
    bits = bits << otherBits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator>>(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(float));
    std::memcpy(&otherBits, &other.data, sizeof(float));
    bits = bits >> otherBits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator^(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(float));
    std::memcpy(&otherBits, &other.data, sizeof(float));
    bits = bits ^ otherBits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator|(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(float));
    std::memcpy(&otherBits, &other.data, sizeof(float));
    bits = bits | otherBits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
PureBitCalculatorPerfect<float> PureBitCalculatorPerfect<float>::operator&(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(float));
    std::memcpy(&otherBits, &other.data, sizeof(float));
    bits = bits & otherBits;
    float result;
    std::memcpy(&result, &bits, sizeof(float));
    return PureBitCalculatorPerfect<float>(result);
}

template<>
bool PureBitCalculatorPerfect<float>::operator<(const PureBitCalculatorPerfect<float>& other) const {
    uint32_t aBits, bBits;
    std::memcpy(&aBits, &data, sizeof(float));
    std::memcpy(&bBits, &other.data, sizeof(float));
    return PureBitOpsPerfect::floatLess(aBits, bBits);
}

// double特化
template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator+(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    resultBits = PureBitOpsPerfect::doubleAdd(aBits, bBits);
    double result;
    std::memcpy(&result, &resultBits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator-(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    resultBits = PureBitOpsPerfect::doubleSub(aBits, bBits);
    double result;
    std::memcpy(&result, &resultBits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator*(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    resultBits = PureBitOpsPerfect::doubleMul(aBits, bBits);
    double result;
    std::memcpy(&result, &resultBits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator/(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits, resultBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    resultBits = PureBitOpsPerfect::doubleDiv(aBits, bBits);
    double result;
    std::memcpy(&result, &resultBits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator%(const PureBitCalculatorPerfect<double>& other) const {
    PureBitCalculatorPerfect<double> div_result = this->operator/(other);
    int64_t truncated = (int64_t)div_result.data;
    PureBitCalculatorPerfect<double> truncated_double(truncated);
    PureBitCalculatorPerfect<double> mult_result = truncated_double.operator*(other);
    return this->operator-(mult_result);
}

template<>
PureBitCalculatorPerfect<double>& PureBitCalculatorPerfect<double>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1.0));
    return *this;
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<double>& PureBitCalculatorPerfect<double>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1.0));
    return *this;
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<double>::operator==(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    return PureBitOpsPerfect::isEqual64(aBits, bBits);
}

template<>
bool PureBitCalculatorPerfect<double>::operator<(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t aBits, bBits;
    std::memcpy(&aBits, &data, sizeof(double));
    std::memcpy(&bBits, &other.data, sizeof(double));
    return PureBitOpsPerfect::doubleLess(aBits, bBits);
}

// double特化 - 位运算符
template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator~() const {
    uint64_t bits;
    std::memcpy(&bits, &data, sizeof(double));
    bits = ~bits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator<<(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(double));
    std::memcpy(&otherBits, &other.data, sizeof(double));
    bits = bits << otherBits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator>>(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(double));
    std::memcpy(&otherBits, &other.data, sizeof(double));
    bits = bits >> otherBits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator^(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(double));
    std::memcpy(&otherBits, &other.data, sizeof(double));
    bits = bits ^ otherBits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator|(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(double));
    std::memcpy(&otherBits, &other.data, sizeof(double));
    bits = bits | otherBits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

template<>
PureBitCalculatorPerfect<double> PureBitCalculatorPerfect<double>::operator&(const PureBitCalculatorPerfect<double>& other) const {
    uint64_t bits, otherBits;
    std::memcpy(&bits, &data, sizeof(double));
    std::memcpy(&otherBits, &other.data, sizeof(double));
    bits = bits & otherBits;
    double result;
    std::memcpy(&result, &bits, sizeof(double));
    return PureBitCalculatorPerfect<double>(result);
}

// ==================== int16_t特化 ====================

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator+(const PureBitCalculatorPerfect<int16_t>& other) const {
    return PureBitCalculatorPerfect<int16_t>(PureBitOpsPerfect::add16(data, other.data));
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator-(const PureBitCalculatorPerfect<int16_t>& other) const {
    return PureBitCalculatorPerfect<int16_t>(PureBitOpsPerfect::sub16(data, other.data));
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator*(const PureBitCalculatorPerfect<int16_t>& other) const {
    return PureBitCalculatorPerfect<int16_t>(PureBitOpsPerfect::mul16(data, other.data));
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator/(const PureBitCalculatorPerfect<int16_t>& other) const {
    bool signA = data & 0x8000;
    bool signB = other.data & 0x8000;
    uint16_t absA = signA ? PureBitOpsPerfect::sub16(0, data) : data;
    uint16_t absB = signB ? PureBitOpsPerfect::sub16(0, other.data) : other.data;
    uint16_t result = PureBitOpsPerfect::div16(absA, absB);
    return PureBitCalculatorPerfect<int16_t>((signA ^ signB) ? PureBitOpsPerfect::sub16(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator%(const PureBitCalculatorPerfect<int16_t>& other) const {
    bool signA = data & 0x8000;
    uint16_t absA = signA ? PureBitOpsPerfect::sub16(0, data) : data;
    uint16_t absB = (other.data & 0x8000) ? PureBitOpsPerfect::sub16(0, other.data) : other.data;
    uint16_t result = PureBitOpsPerfect::mod16(absA, absB);
    return PureBitCalculatorPerfect<int16_t>(signA ? PureBitOpsPerfect::sub16(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int16_t>& PureBitCalculatorPerfect<int16_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<int16_t>& PureBitCalculatorPerfect<int16_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int16_t> PureBitCalculatorPerfect<int16_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<int16_t>::operator==(const PureBitCalculatorPerfect<int16_t>& other) const {
    return PureBitOpsPerfect::isEqual16(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<int16_t>::operator<(const PureBitCalculatorPerfect<int16_t>& other) const {
    return PureBitOpsPerfect::isLessSigned16(data, other.data);
}

// uint16_t特化
template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator+(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitCalculatorPerfect<uint16_t>(PureBitOpsPerfect::add16(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator-(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitCalculatorPerfect<uint16_t>(PureBitOpsPerfect::sub16(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator*(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitCalculatorPerfect<uint16_t>(PureBitOpsPerfect::mul16(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator/(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitCalculatorPerfect<uint16_t>(PureBitOpsPerfect::div16(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator%(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitCalculatorPerfect<uint16_t>(PureBitOpsPerfect::mod16(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint16_t>& PureBitCalculatorPerfect<uint16_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<uint16_t>& PureBitCalculatorPerfect<uint16_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint16_t> PureBitCalculatorPerfect<uint16_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<uint16_t>::operator==(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitOpsPerfect::isEqual16(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<uint16_t>::operator<(const PureBitCalculatorPerfect<uint16_t>& other) const {
    return PureBitOpsPerfect::isLessUnsigned16(data, other.data);
}

// int8_t特化
template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator+(const PureBitCalculatorPerfect<int8_t>& other) const {
    return PureBitCalculatorPerfect<int8_t>(PureBitOpsPerfect::add8(data, other.data));
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator-(const PureBitCalculatorPerfect<int8_t>& other) const {
    return PureBitCalculatorPerfect<int8_t>(PureBitOpsPerfect::sub8(data, other.data));
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator*(const PureBitCalculatorPerfect<int8_t>& other) const {
    return PureBitCalculatorPerfect<int8_t>(PureBitOpsPerfect::mul8(data, other.data));
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator/(const PureBitCalculatorPerfect<int8_t>& other) const {
    bool signA = data & 0x80;
    bool signB = other.data & 0x80;
    uint8_t absA = signA ? PureBitOpsPerfect::sub8(0, data) : data;
    uint8_t absB = signB ? PureBitOpsPerfect::sub8(0, other.data) : other.data;
    uint8_t result = PureBitOpsPerfect::div8(absA, absB);
    return PureBitCalculatorPerfect<int8_t>((signA ^ signB) ? PureBitOpsPerfect::sub8(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator%(const PureBitCalculatorPerfect<int8_t>& other) const {
    bool signA = data & 0x80;
    uint8_t absA = signA ? PureBitOpsPerfect::sub8(0, data) : data;
    uint8_t absB = (other.data & 0x80) ? PureBitOpsPerfect::sub8(0, other.data) : other.data;
    uint8_t result = PureBitOpsPerfect::mod8(absA, absB);
    return PureBitCalculatorPerfect<int8_t>(signA ? PureBitOpsPerfect::sub8(0, result) : result);
}

template<>
PureBitCalculatorPerfect<int8_t>& PureBitCalculatorPerfect<int8_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<int8_t>& PureBitCalculatorPerfect<int8_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<int8_t> PureBitCalculatorPerfect<int8_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<int8_t>::operator==(const PureBitCalculatorPerfect<int8_t>& other) const {
    return PureBitOpsPerfect::isEqual8(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<int8_t>::operator<(const PureBitCalculatorPerfect<int8_t>& other) const {
    return PureBitOpsPerfect::isLessSigned8(data, other.data);
}

// uint8_t特化
template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator+(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitCalculatorPerfect<uint8_t>(PureBitOpsPerfect::add8(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator-(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitCalculatorPerfect<uint8_t>(PureBitOpsPerfect::sub8(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator*(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitCalculatorPerfect<uint8_t>(PureBitOpsPerfect::mul8(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator/(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitCalculatorPerfect<uint8_t>(PureBitOpsPerfect::div8(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator%(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitCalculatorPerfect<uint8_t>(PureBitOpsPerfect::mod8(data, other.data));
}

template<>
PureBitCalculatorPerfect<uint8_t>& PureBitCalculatorPerfect<uint8_t>::operator++() {
    *this = operator+(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator++(int) {
    PureBitCalculatorPerfect temp = *this;
    operator++();
    return temp;
}

template<>
PureBitCalculatorPerfect<uint8_t>& PureBitCalculatorPerfect<uint8_t>::operator--() {
    *this = operator-(PureBitCalculatorPerfect(1));
    return *this;
}

template<>
PureBitCalculatorPerfect<uint8_t> PureBitCalculatorPerfect<uint8_t>::operator--(int) {
    PureBitCalculatorPerfect temp = *this;
    operator--();
    return temp;
}

template<>
bool PureBitCalculatorPerfect<uint8_t>::operator==(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitOpsPerfect::isEqual8(data, other.data);
}

template<>
bool PureBitCalculatorPerfect<uint8_t>::operator<(const PureBitCalculatorPerfect<uint8_t>& other) const {
    return PureBitOpsPerfect::isLessUnsigned8(data, other.data);
}

// 流操作符实现
template<typename T>
std::ostream& operator<<(std::ostream& os, const PureBitCalculatorPerfect<T>& obj) {
    os << static_cast<T>(obj);
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, PureBitCalculatorPerfect<T>& obj) {
    T temp;
    is >> temp;
    obj = PureBitCalculatorPerfect<T>(temp);
    return is;
}

// 显式实例化所有需要的模板
template class PureBitCalculatorPerfect<int32_t>;
template class PureBitCalculatorPerfect<uint32_t>;
template class PureBitCalculatorPerfect<int64_t>;
template class PureBitCalculatorPerfect<uint64_t>;
template class PureBitCalculatorPerfect<int16_t>;
template class PureBitCalculatorPerfect<uint16_t>;
template class PureBitCalculatorPerfect<int8_t>;
template class PureBitCalculatorPerfect<uint8_t>;
template class PureBitCalculatorPerfect<float>;
template class PureBitCalculatorPerfect<double>;

template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<int32_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<uint32_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<int64_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<uint64_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<int16_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<uint16_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<int8_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<uint8_t>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<float>&);
template std::ostream& operator<<(std::ostream&, const PureBitCalculatorPerfect<double>&);

template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<int32_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<uint32_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<int64_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<uint64_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<int16_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<uint16_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<int8_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<uint8_t>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<float>&);
template std::istream& operator>>(std::istream&, PureBitCalculatorPerfect<double>&);