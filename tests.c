#include <stdio.h>
#include <string.h>
#include "func.h"

static void test_zero(void) {
    char result[33];
    Struct error = convert(0, 2, result, sizeof(result));
    printf("Test zero: %d, result: %s\n", error, result);
}

static void test_normal(void) {
    char result[33];
    Struct error = convert(10, 2, result, sizeof(result));
    printf("Test normal (10 to base 2): %d, result: %s\n", error, result);
}

static void test_different_bases(void) {
    char result[33];
    unsigned int number = 15;
    
    printf("Test different bases for number %u:\n", number);
    for (unsigned int base = 2; base <= 5; base++) {
        Struct error = convert(number, base, result, sizeof(result));
        printf("Base %u: %d, result: %s\n", base, error, result);
    }
}

static void test_invalid_base(void) {
    char result[33];
    Struct error = convert(10, 1, result, sizeof(result));
    printf("Test invalid base (1): %d\n", error);
    
    error = convert(10, 6, result, sizeof(result));
    printf("Test invalid base (6): %d\n", error);
}

static void test_null_pointer(void) {
    Struct error = convert(10, 2, 0, 33);
    printf("Test null pointer: %d\n", error);
}

static void test_buffer_overflow(void) {
    char small[3];
    Struct error = convert(100, 2, small, sizeof(small));
    printf("Test buffer overflow: %d\n", error);
}

static void test_large_number(void) {
    char result[33];
    Struct error = convert(4294967295U, 2, result, sizeof(result));
    printf("Test large number: %d, result length: %lu\n", error, strlen(result));
}

static void run_all_tests(void) {
    printf("Running tests:\n");
    printf("==============\n");
    
    test_zero();
    test_normal();
    test_different_bases();
    test_invalid_base();
    test_null_pointer();
    test_buffer_overflow();
    test_large_number();

    printf("=== Tests Completed ===\n");
}

int main(void) {
    run_all_tests();
    return 0;
}