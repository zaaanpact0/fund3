#include <stdio.h>
#include "func.h"

int main(void) {
    char result[33];
    
    unsigned int test_numbers[] = {0, 5, 10, 15, 25, 42, 100};
    unsigned int bases[] = {2, 3, 4, 5};
    
    for (int i = 0; i < 7; i++) {
        printf("Number: %u\n", test_numbers[i]);
        for (int j = 0; j < 4; j++) {
            Struct error = convert(test_numbers[i], bases[j], result, sizeof(result));
            if (error == SUCCESS) {
                printf("Base %u: %s\n", bases[j], result);
            } else {
                printf("Base %u: Error %d\n", bases[j], error);
            }
        }
        printf("\n");
    }
    
    return 0;
}