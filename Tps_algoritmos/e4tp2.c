#include <stdio.h>

int height;

int main(){

    printf("determine la altura del triangulo: \n");
    scanf("%d", &height);

    for (int i = 1; i<= height; i++){
        for (int j = 1; j <= i; j++){
            printf("#");
        }
        printf("\n");
    }
}