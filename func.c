#include "func.h"

static char getDigitChar(unsigned int digit) {
    static const char digits[] = "0123456789";
    if (digit > 9) digit = 9;
    return digits[digit];
}

Struct convert(unsigned int number, unsigned int base, char* result, unsigned int bufferSize) {
    if (result == 0) {
        return NULL_POINTER;
    }
    
    if (base < 2 || base > 5) {
        result[0] = '\0';
        return INVALID_BASE;
    }
    
    if (number == 0) {
        if (bufferSize < 2) {
            return BUFFER_OVERFLOW;
        }
        result[0] = '0';
        result[1] = '\0';
        return SUCCESS;
    }
    
    char temp[32];
    int index = 0;
    unsigned int n = number;
    
    if (base == 2) {
        while (n > 0) {
            if (index >= 31) {
                return BUFFER_OVERFLOW;
            }
            temp[index++] = getDigitChar(n & 1);
            n = n >> 1;
        }
    } else if (base == 3) {
        while (n > 0) {
            if (index >= 31) {
                return BUFFER_OVERFLOW;
            }
            unsigned int quotient = 0;
            unsigned int temp_n = n;
            while (temp_n >= 3) {
                temp_n = (temp_n >> 1) - (temp_n >> 3);
                quotient++;
            }
            unsigned int remainder = n - quotient * 3;
            if (remainder > 2) remainder = 2;
            temp[index++] = getDigitChar(remainder);
            n = quotient;
        }
    } else if (base == 4) {
        while (n > 0) {
            if (index >= 31) {
                return BUFFER_OVERFLOW;
            }
            temp[index++] = getDigitChar(n & 3);
            n = n >> 2;
        }
    } else if (base == 5) {
        while (n > 0) {
            if (index >= 31) {
                return BUFFER_OVERFLOW;
            }
            unsigned int quotient = 0;
            unsigned int temp_n = n;
            while (temp_n >= 5) {
                temp_n = (temp_n >> 2) - (temp_n >> 4);
                quotient++;
            }
            unsigned int remainder = n - quotient * 5;
            if (remainder > 4) remainder = 4;
            temp[index++] = getDigitChar(remainder);
            n = quotient;
        }
    }
    
    if ((unsigned int)(index + 1) > bufferSize) {
        return BUFFER_OVERFLOW;
    }
    
    int result_index = 0;
    while (index > 0) {
        result[result_index++] = temp[--index];
    }
    result[result_index] = '\0';
    
    return SUCCESS;
}