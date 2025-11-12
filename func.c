#include "func.h"

static char getDigitChar(unsigned int digit) {
    static const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    return digits[digit];
}

Status convert(unsigned int number, unsigned int r, char* result, unsigned int bufferSize) {
    if (result == 0) {
        return NULL_POINTER;
    }
    
    if (r < 1 || r > 5) {
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
    
    unsigned int bit_mask = (1U << r) - 1;
    
    while (n > 0) {
        if (index >= 31) {
            return BUFFER_OVERFLOW;
        }
        
        unsigned int digit = n & bit_mask;
        temp[index++] = getDigitChar(digit);
        
        n = n >> r;
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