#include <stdio.h>
#define cant 5

void orden_ascendente(int *vector,int vec_size);
void orden_descendente(int *vector,int vec_size);
void imprimir_vector(int vector[],int vec_size);

int main(){
    int numeros[cant]={0};
    for (int i=0; i < cant; i++){
        printf("Ingrese el numero %d: \n", i+1);
        scanf("%d", &numeros[i]);
    }
    printf("orden ascendente: \n");
    orden_ascendente(numeros,cant); 
    imprimir_vector(numeros, cant);
         
    printf("orden descendente: \n");    
    orden_descendente(numeros,cant);
    imprimir_vector(numeros,cant);

    return 0;
}

void orden_ascendente(int *vector,int vec_size){
    for (int i = 1; i < vec_size; i++){
        int key = vector[i];
        int j = i-1;
        while (j >= 0 && vector[j] > key){
            vector[j+1]=vector[j];
            j--;
        }
        vector[j+1] = key;
    }
}

void orden_descendente(int *vector,int vec_size){
    for (int i = 1; i < vec_size; i++){
        int key = vector[i];
        int j = i-1;
        while (j >= 0 && vector[j] < key){
            vector[j+1]=vector[j];
            j--;
        }
        vector[j+1] = key;
    }
}

void imprimir_vector(int vector[],int vec_size){
    for (int i = 0; i < vec_size; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");
}