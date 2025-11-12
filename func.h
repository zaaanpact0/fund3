#ifndef FUNC_H
#define FUNC_H

typedef enum {
    SUCCESS = 0,
    INVALID_BASE,
    NULL_POINTER,
    BUFFER_OVERFLOW
} Struct;

Struct convert(unsigned int number, unsigned int base, char* result, unsigned int bufferSize);

#endif