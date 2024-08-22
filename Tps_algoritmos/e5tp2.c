#include <stdio.h>

void define_biggest(int cantidad);

int n=0;

int main(){

    printf("Indique la cantidad de numeros a comparar: \n");
    scanf("%d",&n);
        
    define_biggest(n);

    return 0;
}



void define_biggest(int cantidad){
    
    int numbers [cantidad], biggest = 0;
    if (cantidad == 0){
        printf("biggest = \n",biggest);
    }

    for(int i = 1; i <= cantidad; i++){
        printf ("Ingresa el numero %d: \n",i);
        scanf("%d", &numbers[i]);

        if (biggest< numbers[i]){
            biggest = numbers[i];
        }  
    }
    printf("biggest = %d \n",biggest);
    
}