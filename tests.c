#include <stdio.h>
#include <string.h>
#include "func.h"

static void test_zero(void) {
    char result[33];
    Status error = convert(0, 1, result, sizeof(result));
    printf("Test zero: %d, result: %s\n", error, result);
}

static void test_binary(void) {
    char result[33];
    Status error = convert(10, 1, result, sizeof(result));
    printf("Test binary (r=1): %d, result: %s\n", error, result);
}

static void test_hex(void) {
    char result[33];
    Status error = convert(255, 4, result, sizeof(result));
    printf("Test hex (r=4): %d, result: %s\n", error, result);
}

static void test_invalid_r(void) {
    char result[33];
    Status error = convert(10, 0, result, sizeof(result));
    printf("Test invalid r (0): %d\n", error);
    
    error = convert(10, 6, result, sizeof(result));
    printf("Test invalid r (6): %d\n", error);
}

static void test_all_bases(void) {
    char result[33];
    unsigned int number = 42;
    
    printf("Test all bases for number %u:\n", number);
    for (unsigned int r = 1; r <= 5; r++) {
        Status error = convert(number, r, result, sizeof(result));
        printf("r=%u: %d, result: %s\n", r, error, result);
    }
}

static void run_all_tests(void) {
    printf("Running tests:\n");
    printf("==============\n");
    
    test_zero();
    test_binary();
    test_hex();
    test_invalid_r();
    test_all_bases();

    printf("=======Complete=======\n");
}

int main(void) {
    run_all_tests();
    return 0;
}