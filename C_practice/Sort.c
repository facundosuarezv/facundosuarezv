#include <stdio.h>

int main() {
    int nums[] = {1, 3, 2, 4, 5, 9, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int swap = 1;
    do {
        swap = 0;
        for (int i = 0; i < numsSize - 1; i++) {
            // Compara elementos adyacentes
            if (nums[i] > nums[i + 1]) {
                // Intercambia los elementos si están en el orden incorrecto
                int temp = nums[i];
                nums[i] = nums[i + 1];
                nums[i + 1] = temp;
                swap = 1;
            }
        }
    } while (swap == 1); // Corrige la condición de salida

    // Imprime el arreglo ordenado
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }

    return 0;
}
