#include "PureBitOpsPerfect.h"

// ==================== PureBitOpsPerfect ʵ�� ====================

// ����32λ����
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

// ����64λ����
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

// ����16λ����
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

// ����8λ����
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

// �ȽϺ���
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

    // ��ͬ����ʱ���д�λ����Ƚ�
    if (signA) {
        // �����������ϴ��λģʽ��ʾ��С����ֵ
        return isLessUnsigned32(b & 0x7FFFFFFF, a & 0x7FFFFFFF);
    }
    else {
        // ����������ֱ�ӱȽ�λģʽ
        return isLessUnsigned32(a & 0x7FFFFFFF, b & 0x7FFFFFFF);
    }
}

bool PureBitOpsPerfect::isLessSigned64(uint64_t a, uint64_t b) {
    bool signA = (a >> 63) & 1;
    bool signB = (b >> 63) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // ��ͬ����ʱ���д�λ����Ƚ�
    if (signA) {
        // �����������ϴ��λģʽ��ʾ��С����ֵ
        return isLessUnsigned64(b & 0x7FFFFFFFFFFFFFFFULL, a & 0x7FFFFFFFFFFFFFFFULL);
    }
    else {
        // ����������ֱ�ӱȽ�λģʽ
        return isLessUnsigned64(a & 0x7FFFFFFFFFFFFFFFULL, b & 0x7FFFFFFFFFFFFFFFULL);
    }
}

bool PureBitOpsPerfect::isLessUnsigned32(uint32_t a, uint32_t b) {
    // ��λ����ʵ���޷��������Ƚ�
    // �����λ��ʼ��λ�Ƚ�
    for (int i = 31; i >= 0; i--) {
        uint32_t bitA = (a >> i) & 1;
        uint32_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, �����Ƚ���һλ
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessUnsigned64(uint64_t a, uint64_t b) {
    // ��λ����ʵ���޷��������Ƚ�
    // �����λ��ʼ��λ�Ƚ�
    for (int i = 63; i >= 0; i--) {
        uint64_t bitA = (a >> i) & 1;
        uint64_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, �������^��һλ
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessSigned16(uint16_t a, uint16_t b) {
    bool signA = (a >> 15) & 1;
    bool signB = (b >> 15) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // ��ͬ����ʱ���д�λ����Ƚ�
    if (signA) {
        // �����������ϴ��λģʽ��ʾ��С����ֵ
        return isLessUnsigned16(b & 0x7FFF, a & 0x7FFF);
    }
    else {
        // ����������ֱ�ӱȽ�λģʽ
        return isLessUnsigned16(a & 0x7FFF, b & 0x7FFF);
    }
}

bool PureBitOpsPerfect::isLessSigned8(uint8_t a, uint8_t b) {
    bool signA = (a >> 7) & 1;
    bool signB = (b >> 7) & 1;

    if (signA && !signB) return true;
    if (!signA && signB) return false;

    // ��ͬ����ʱ���д�λ����Ƚ�
    if (signA) {
        // �����������ϴ��λģʽ��ʾ��С����ֵ
        return isLessUnsigned8(b & 0x7F, a & 0x7F);
    }
    else {
        // ����������ֱ�ӱȽ�λģʽ
        return isLessUnsigned8(a & 0x7F, b & 0x7F);
    }
}

bool PureBitOpsPerfect::isLessUnsigned16(uint16_t a, uint16_t b) {
    // ��λ����ʵ���޷��������Ƚ�
    // �����λ��ʼ��λ�Ƚ�
    for (int i = 15; i >= 0; i--) {
        uint16_t bitA = (a >> i) & 1;
        uint16_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, �������^��һλ
    }
    return false; // a == b
}

bool PureBitOpsPerfect::isLessUnsigned8(uint8_t a, uint8_t b) {
    // ��λ����ʵ���޷��������Ƚ�
    // �����λ��ʼ��λ�Ƚ�
    for (int i = 7; i >= 0; i--) {
        uint8_t bitA = (a >> i) & 1;
        uint8_t bitB = (b >> i) & 1;
        if (bitA && !bitB) return false; // A=1, B=0 => A > B
        if (!bitA && bitB) return true;  // A=0, B=1 => A < B
        // bitA == bitB, �������^��һλ
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

// IEEE754��������
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
    // ��ȡIEEE754���
    uint32_t signA = aBits & 0x80000000;
    uint32_t signB = bBits & 0x80000000;
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = aBits & 0x7FFFFF;
    uint32_t mantB = bBits & 0x7FFFFF;
    uint32_t resultSign = signA ^ signB;

    // �����������

    // ���A�Ƿ�ΪNaN
    if (expA == 0xFF && mantA != 0) {
        return aBits; // ����NaN
    }

    // ���B�Ƿ�ΪNaN
    if (expB == 0xFF && mantB != 0) {
        return bBits; // ����NaN
    }

    // ���A�Ƿ�Ϊ�����
    if (expA == 0xFF && mantA == 0) {
        if (expB == 0xFF && mantB == 0) {
            // �� / �� = NaN
            return 0x7FC00000; // Quiet NaN
        }
        // �� / finite = ����
        return resultSign | 0x7F800000;
    }

    // ���B�Ƿ�Ϊ�����
    if (expB == 0xFF && mantB == 0) {
        // finite / �� = ��0
        return resultSign;
    }

    // ���A�Ƿ�Ϊ0
    if (expA == 0 && mantA == 0) {
        if (expB == 0 && mantB == 0) {
            // 0 / 0 = NaN
            return 0x7FC00000; // Quiet NaN
        }
        // 0 / finite = ��0
        return resultSign;
    }

    // ���B�Ƿ�Ϊ0
    if (expB == 0 && mantB == 0) {
        // finite / 0 = ����
        return resultSign | 0x7F800000;
    }

    // ������ֵ����
    uint64_t extMantA, extMantB;
    int32_t biasedExpA = expA, biasedExpB = expB;

    // ����ǹ����
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

    // ��񻯽��
    if (resultMant & 0x1000000) {
        resultMant = resultMant >> 1;
        resultExp++;
    }

    resultMant = resultMant & 0x7FFFFF;

    // ���ָ�����������
    if (resultExp >= 0xFF) {
        return resultSign | 0x7F800000; // ����
    }
    if (resultExp <= 0) {
        return resultSign; // ��0 (�򻯴���)
    }

    return resultSign | ((uint32_t)resultExp << 23) | ((uint32_t)resultMant);
}

bool PureBitOpsPerfect::floatLess(uint32_t aBits, uint32_t bBits) {
    // ��ȡ����λ
    bool signA = (aBits >> 31) & 1;
    bool signB = (bBits >> 31) & 1;

    // �������������NaN
    uint32_t expA = (aBits >> 23) & 0xFF;
    uint32_t expB = (bBits >> 23) & 0xFF;
    uint32_t mantA = aBits & 0x7FFFFF;
    uint32_t mantB = bBits & 0x7FFFFF;

    // NaN��Զ��С���κ���
    if ((expA == 0xFF && mantA != 0) || (expB == 0xFF && mantB != 0)) {
        return false;
    }

    // ��ͬ���űȽ�
    if (signA && !signB) return true;  // ���� < ����
    if (!signA && signB) return false; // ���� > ����

    // ��ͬ���űȽ�
    if (signA) {
        // �������Ǹ������Ƚ�λģʽ�����λģʽ��ӦС����ֵ
        return isLessUnsigned32(bBits & 0x7FFFFFFF, aBits & 0x7FFFFFFF);
    }
    else {
        // ��������������ֱ�ӱȽ�λģʽ
        return isLessUnsigned32(aBits & 0x7FFFFFFF, bBits & 0x7FFFFFFF);
    }
}

bool PureBitOpsPerfect::doubleLess(uint64_t aBits, uint64_t bBits) {
    // ��ȡ����λ
    bool signA = (aBits >> 63) & 1;
    bool signB = (bBits >> 63) & 1;

    // �������������NaN
    uint64_t expA = (aBits >> 52) & 0x7FF;
    uint64_t expB = (bBits >> 52) & 0x7FF;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    // NaN��Զ��С���κ���
    if ((expA == 0x7FF && mantA != 0) || (expB == 0x7FF && mantB != 0)) {
        return false;
    }

    // ��ͬ���űȽ�
    if (signA && !signB) return true;  // ���� < ����
    if (!signA && signB) return false; // ���� > ����

    // ��ͬ���űȽ�
    if (signA) {
        // �������Ǹ������Ƚ�λģʽ�����λģʽ��ӦС����ֵ
        return isLessUnsigned64(bBits & 0x7FFFFFFFFFFFFFFFULL, aBits & 0x7FFFFFFFFFFFFFFFULL);
    }
    else {
        // ��������������ֱ�ӱȽ�λģʽ
        return isLessUnsigned64(aBits & 0x7FFFFFFFFFFFFFFFULL, bBits & 0x7FFFFFFFFFFFFFFFULL);
    }
}

// ˫�������� - ��λ���㾫ȷʵ��
uint64_t PureBitOpsPerfect::doubleAdd(uint64_t aBits, uint64_t bBits) {
    if (!aBits) return bBits;
    if (!bBits) return aBits;

    // ��ȡIEEE754���
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FFULL;
    uint64_t expB = (bBits >> 52) & 0x7FFULL;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    // �������������NaN
    if ((expA == 0x7FF && mantA != 0) || (expB == 0x7FF && mantB != 0)) {
        // ����NaN�����ȴ���signaling NaN
        if (expA == 0x7FF && mantA != 0) return aBits;
        return bBits;
    }

    // ������������������
    if (expA == 0x7FF && mantA == 0) { // A�������
        if (expB == 0x7FF && mantB == 0) { // BҲ�������
            if (signA == signB) {
                return aBits; // ͬ���������� = �����
            }
            else {
                return 0x7FF8000000000000ULL; // ����������� = NaN
            }
        }
        return aBits; // ����� + ������ = �����
    }

    if (expB == 0x7FF && mantB == 0) { // B�������
        return bBits; // ������ + ����� = �����
    }

    // ���������1λ�������������ǹ����
    if (expA == 0) {
        if (mantA == 0) return bBits;  // A��0
    }
    else {
        mantA = mantA | 0x10000000000000ULL;  // ���������1
    }

    if (expB == 0) {
        if (mantB == 0) return aBits;  // B��0
    }
    else {
        mantB = mantB | 0x10000000000000ULL;  // ���������1
    }

    // ����ָ�� - �ý�Сָ����β������
    if (expA < expB) {
        uint64_t diff = sub64(expB, expA);
        if (diff > 54) return bBits;  // A̫С������
        mantA = mantA >> diff;
        expA = expB;
    }
    else if (expB < expA) {
        uint64_t diff = sub64(expA, expB);
        if (diff > 54) return aBits;  // B̫С������
        mantB = mantB >> diff;
    }

    uint64_t resultSign, resultExp, resultMant;
    resultExp = expA;

    // ִ�мӷ������
    if (signA == signB) {
        // ��ͬ���ţ�ִ�мӷ�
        resultSign = signA;
        resultMant = add64(mantA, mantB);

        // ����Ƿ��������Ҫ����1λ������ָ����
        if (resultMant & 0x20000000000000ULL) {
            resultMant = resultMant >> 1;
            resultExp = add64(resultExp, 1);
        }
    }
    else {
        // ��ͬ���ţ�ִ�м���
        if (mantA >= mantB) {
            resultSign = signA;
            resultMant = sub64(mantA, mantB);
        }
        else {
            resultSign = signB;
            resultMant = sub64(mantB, mantA);
        }

        // ��񻯽��������ֱ�����λΪ1��
        if (resultMant == 0) return resultSign;  // ���Ϊ0

        while (!(resultMant & 0x10000000000000ULL) && resultExp > 0) {
            resultMant = resultMant << 1;
            resultExp = sub64(resultExp, 1);
        }
    }

    // ���ָ�����
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;  // �����
    }

    // ������Ϊ�ǹ����
    if (resultExp == 0) {
        return resultSign | (resultMant & 0xFFFFFFFFFFFFFULL);
    }

    // �Ƴ�������1λ����װ���
    resultMant = resultMant & 0xFFFFFFFFFFFFFULL;
    return resultSign | (resultExp << 52) | resultMant;
}

uint64_t PureBitOpsPerfect::doubleSub(uint64_t aBits, uint64_t bBits) {
    return doubleAdd(aBits, bBits ^ 0x8000000000000000ULL);
}

uint64_t PureBitOpsPerfect::doubleMul(uint64_t aBits, uint64_t bBits) {
    if (!aBits || !bBits) return 0;

    // ��ȡIEEE754���
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FFULL;
    uint64_t expB = (bBits >> 52) & 0x7FFULL;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;

    uint64_t resultSign = signA ^ signB;

    // �����������
    if (expA == 0x7FF || expB == 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;  // ������NaN
    }

    // ������
    if ((expA == 0 && mantA == 0) || (expB == 0 && mantB == 0)) {
        return resultSign;  // ���Ϊ0
    }

    // ��ȷ�����񻯺ͷǹ����
    uint64_t biasedExpA = expA;
    uint64_t biasedExpB = expB;

    if (expA == 0) {
        // �ǹ������ָ����Ϊ1��β�����������1
        biasedExpA = 1;
        if (mantA == 0) return resultSign; // A����
    }
    else {
        // ����������������1λ
        mantA = mantA | 0x10000000000000ULL;
    }

    if (expB == 0) {
        // �ǹ������ָ����Ϊ1��β�����������1
        biasedExpB = 1;
        if (mantB == 0) return resultSign; // B����
    }
    else {
        // ����������������1λ
        mantB = mantB | 0x10000000000000ULL;
    }

    // ������ָ�� - ʹ��ƫ��ָ��
    uint64_t tempExp = add64(biasedExpA, biasedExpB);
    uint64_t resultExp;
    if (tempExp >= 1023) {
        resultExp = sub64(tempExp, 1023);
    }
    else {
        return resultSign; // ָ������
    }

    // IEEE754���ݵĸ߾��ȳ˷�ʵ��
    // ʹ��128λ����������53λ��53λ�ĳ˷�

    // ��53λβ���ֽ�Ϊ�ߵ������ֽ��о�ȷ�˷�
    uint64_t aHigh = mantA >> 26; // ��27λ
    uint64_t aLow = mantA & 0x3FFFFFFULL; // ��26λ
    uint64_t bHigh = mantB >> 26; // ��27λ
    uint64_t bLow = mantB & 0x3FFFFFFULL; // ��26λ

    // �����ĸ����ֻ���(aHigh*2^26 + aLow) * (bHigh*2^26 + bLow)
    // = aHigh*bHigh*2^52 + (aHigh*bLow + aLow*bHigh)*2^26 + aLow*bLow
    uint64_t prodHH = mul64(aHigh, bHigh);   // ���λ����
    uint64_t prodHL = mul64(aHigh, bLow);    // �м䲿��1
    uint64_t prodLH = mul64(aLow, bHigh);    // �м䲿��2
    uint64_t prodLL = mul64(aLow, bLow);     // ���λ����

    // ��װ106λ�ĳ˻����
    // ���ս���Ľṹ��[prodHH:52] + [prodHL+prodLH:26] + [prodLL:0]
    uint64_t resultHigh = prodHH;
    uint64_t resultMid = add64(prodHL, prodLH);
    uint64_t resultLow = prodLL;

    // �����λ�����м䲿�ֵĸ�λ�ӵ���λ����
    resultHigh = add64(resultHigh, resultMid >> 26);
    resultMid = resultMid & 0x3FFFFFFULL;

    // ����������һ��106λ�Ľ������Ҫ��񻯵�53λ����
    uint64_t resultMant;

    // ������λ�Ƿ����ã�overflow�����
    if (resultHigh & 0x20000000000000ULL) {
        // ��Ҫ����1λ������ָ��
        resultMant = (resultHigh >> 1) | ((resultMid & 0x2000000ULL) ? 0x8000000000000ULL : 0);
        resultExp = add64(resultExp, 1);

        // ����guard��round��stickyλ��������
        uint64_t guard = resultMid & 0x2000000ULL; // bit 25
        uint64_t round_bit = resultMid & 0x1000000ULL; // bit 24
        uint64_t sticky = (resultMid & 0xFFFFFFULL) | resultLow; // ��������λ

        // IEEE754���뵽���ż��
        if (guard) {
            if (round_bit || sticky || (resultMant & 1)) {
                resultMant = add64(resultMant, 1);
                // �����������
                if (resultMant & 0x20000000000000ULL) {
                    resultMant = resultMant >> 1;
                    resultExp = add64(resultExp, 1);
                }
            }
        }
    }
    else {
        // ������������λ��bit 52
        resultMant = resultHigh;

        // ����guard��round��stickyλ��������
        uint64_t guard = resultMid >> 25; // bit 25
        uint64_t round_bit = (resultMid >> 24) & 1; // bit 24
        uint64_t sticky = (resultMid & 0xFFFFFFULL) | resultLow; // ��������λ

        // IEEE754���뵽���ż��
        if (guard) {
            if (round_bit || sticky || (resultMant & 1)) {
                resultMant = add64(resultMant, 1);
                // �����������
                if (resultMant & 0x20000000000000ULL) {
                    resultMant = resultMant >> 1;
                    resultExp = add64(resultExp, 1);
                }
            }
        }
    }

    // ���ָ�����������
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL;
    }
    if (resultExp == 0) {
        return resultSign;
    }

    // �Ƴ�������1λ����װ���
    resultMant = resultMant & 0xFFFFFFFFFFFFFULL;
    return resultSign | (resultExp << 52) | resultMant;
}

uint64_t PureBitOpsPerfect::doubleDiv(uint64_t aBits, uint64_t bBits) {
    // ��ȡIEEE754���
    uint64_t signA = aBits & 0x8000000000000000ULL;
    uint64_t signB = bBits & 0x8000000000000000ULL;
    uint64_t expA = (aBits >> 52) & 0x7FF;
    uint64_t expB = (bBits >> 52) & 0x7FF;
    uint64_t mantA = aBits & 0xFFFFFFFFFFFFFULL;
    uint64_t mantB = bBits & 0xFFFFFFFFFFFFFULL;
    uint64_t resultSign = signA ^ signB;

    // �����������

    // ���A�Ƿ�ΪNaN
    if (expA == 0x7FF && mantA != 0) {
        return aBits; // ����NaN
    }

    // ���B�Ƿ�ΪNaN
    if (expB == 0x7FF && mantB != 0) {
        return bBits; // ����NaN
    }

    // ���A�Ƿ�Ϊ�����
    if (expA == 0x7FF && mantA == 0) {
        if (expB == 0x7FF && mantB == 0) {
            // �� / �� = NaN
            return 0x7FF8000000000000ULL; // Quiet NaN
        }
        // �� / finite = ����
        return resultSign | 0x7FF0000000000000ULL;
    }

    // ���B�Ƿ�Ϊ�����
    if (expB == 0x7FF && mantB == 0) {
        // finite / �� = ��0
        return resultSign;
    }

    // ���A�Ƿ�Ϊ0
    if (expA == 0 && mantA == 0) {
        if (expB == 0 && mantB == 0) {
            // 0 / 0 = NaN
            return 0x7FF8000000000000ULL; // Quiet NaN
        }
        // 0 / finite = ��0
        return resultSign;
    }

    // ���B�Ƿ�Ϊ0
    if (expB == 0 && mantB == 0) {
        // finite / 0 = ����
        return resultSign | 0x7FF0000000000000ULL;
    }

    // ������ֵ����
    int64_t biasedExpA = expA, biasedExpB = expB;

    // �������������������1λ
    if (expA != 0) {
        mantA |= 0x10000000000000ULL;
    }
    else {
        // �ǹ��������
        biasedExpA = 1;
        // mantA����ԭ�������������1λ
    }

    if (expB != 0) {
        mantB |= 0x10000000000000ULL;
    }
    else {
        // �ǹ��������
        biasedExpB = 1;
        // mantB����ԭ�������������1λ
    }

    // ������ָ��
    int64_t resultExp = biasedExpA - biasedExpB + 1023;

    // �߾��ȳ���ʵ��
    // Ϊ�˵õ�׼ȷ��53λ���Ƚ����������Ҫ������չ���ȵĳ���
    // ����������չ�����߾���
    uint64_t quotient = 0;
    uint64_t remainder = mantA;

    // ִ�г������㷨������53λ���ȵ���
    for (int i = 52; i >= 0; i--) {
        if (isGreaterOrEqualUnsigned64(remainder, mantB)) {
            quotient |= (1ULL << i);
            remainder = sub64(remainder, mantB);
        }
        // ����remainder��׼����һλ�ļ���
        if (i > 0) {
            remainder = remainder << 1;
        }
    }

    // ��񻯽��
    uint64_t resultMant;
    if (quotient & 0x20000000000000ULL) {
        // quotient��54λ����Ҫ����1λ������ָ��
        resultMant = (quotient >> 1) & 0xFFFFFFFFFFFFFULL;
        resultExp = add64(resultExp, 1);
    }
    else if (quotient & 0x10000000000000ULL) {
        // quotientǡ����53λ���Ѿ����
        resultMant = quotient & 0xFFFFFFFFFFFFFULL;
    }
    else {
        // quotientС��53λ����Ҫ�����Թ��
        while (quotient && !(quotient & 0x10000000000000ULL) && resultExp > 0) {
            quotient = quotient << 1;
            resultExp = sub64(resultExp, 1);
        }
        resultMant = quotient & 0xFFFFFFFFFFFFFULL;
    }

    // ���ָ�����������
    if (resultExp >= 0x7FF) {
        return resultSign | 0x7FF0000000000000ULL; // ����
    }
    if (resultExp <= 0) {
        return resultSign; // ��0 (�򻯵ķǹ��������)
    }

    return resultSign | ((uint64_t)resultExp << 52) | resultMant;
}


// ==================== PureBitCalculatorPerfect ģ��ʵ�� ====================

// �������캯���������
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

// ==================== �ػ�ʵ�� ====================

// int32_t�ػ�
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

// uint32_t�ػ�
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

// int64_t�ػ�
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

// uint64_t�ػ�
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

// float�ػ�
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

// float�ػ� - λ�����
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

// double�ػ�
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

// double�ػ� - λ�����
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

// ==================== int16_t�ػ� ====================

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

// uint16_t�ػ�
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

// int8_t�ػ�
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

// uint8_t�ػ�
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

// ��������ʵ��
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

// ��ʽʵ����������Ҫ��ģ��
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