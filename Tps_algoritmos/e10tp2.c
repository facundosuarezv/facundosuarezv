#include <stdio.h>



int main(){
    int numero;
    printf("Determinar el numero a examinar: \n");
    scanf("%d", &numero);


    for (int i = 1; i <= numero/2 ; i++){
        if (numero % i == 0){
            printf("%d \n",i);
        }
    }
    printf("\n");

}