#include <stdio.h>
#include "func.h"

int main(void) {
    char result[33];
    
    unsigned int test_numbers[] = {0, 5, 10, 15, 25, 42, 100, 255};
    unsigned int r_values[] = {1, 2, 3, 4, 5};
    unsigned int bases[] = {2, 4, 8, 16, 32};
    
    printf("Перевод чисел в системы счисления с основаниями 2^r:\n");
    printf("===================================================\n");
    
    for (int i = 0; i < 8; i++) {
        printf("Десятичное число: %u\n", test_numbers[i]);
        printf("------------------------\n");
        
        for (int j = 0; j < 5; j++) {
            Status error = convert(test_numbers[i], r_values[j], result, sizeof(result));
            if (error == SUCCESS) {
                printf("r=%u (основание %u): %s\n", r_values[j], bases[j], result);
            } else {
                printf("r=%u: Ошибка %d\n", r_values[j], error);
            }
        }
        printf("\n");
    }
    
    return 0;
}