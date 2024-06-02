#include <stdio.h>

int main () {
    int a = 108;
    int u = a % 10;

    printf("digito:%d \n numero:%d \n", u, a);
    
    a = a / 10;
    u = a % 10;

    printf("digito:%d \n nuevonumero:%d \n",u,a);
    
    a = a / 10;
    u = a % 10;

    printf("digito:%d \n nuevonumero:%d \n", u, a);

    a = a / 10;
    u = a % 10;

    printf("digito:%d \n nuevonumero:%d \n", u, a);


    
}
