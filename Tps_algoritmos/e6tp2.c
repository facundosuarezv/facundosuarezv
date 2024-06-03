#include <stdio.h>

int potencia (int numero, int exponente);

int main(){

    int m,n;

    printf("M = ");
    scanf("%d", &m);
    printf("N = ");
    scanf("%d", &n);

    for (int i = 0; i <= n; i++){
        printf("%d^%d = %d \n", m,i,potencia(m,i));
    }       

}

int potencia (int numero, int exponente){
    if (exponente == 0){
        return 1;
    }

    return numero * potencia(numero, exponente - 1);
}