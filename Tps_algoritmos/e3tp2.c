#include <stdio.h>

#define ciudades 3

int totalxciudad[] = {1000, 1500, 1530};
int menor5anosxciu[3] = {0};
int porcxciudad[3] = {0};

int main() {
    for (int i = 0; i < ciudades; i++) {
        printf("Ingresar cantidad de menores de 5 años para la ciudad %d: \n", i + 1);
        scanf("%d", &menor5anosxciu[i]);
        porcxciudad[i] = (menor5anosxciu[i] * 100) / totalxciudad[i];
    }
    
    int ciudad_con_mayor_porcentaje = 0;
    for (int j = 1; j < ciudades; j++) {
        if (porcxciudad[j] > porcxciudad[ciudad_con_mayor_porcentaje]) {
            ciudad_con_mayor_porcentaje = j;
        }
    }
    
    printf("La ciudad es %d con un porcentaje de %.2f%%\n", ciudad_con_mayor_porcentaje + 1, (float)porcxciudad[ciudad_con_mayor_porcentaje]);
    
    return 0;
}
