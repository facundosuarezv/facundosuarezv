#include <stdio.h>

int potencia (int numero, int exponente);
int suma = 0;
int main(){

    int m,n;

    printf("M = ");
    scanf("%d", &m);
    printf("N = ");
    scanf("%d", &n);

    for (int i = 0; i<=<; i++){
        suma += potencia (m,i);
    }
    printf("%d \n",suma);

    return 0;     

}

int potencia (int numero, int exponente){
    if (exponente == 0){
        return 1;
    }

    return numero * potencia(numero, exponente - 1);
}