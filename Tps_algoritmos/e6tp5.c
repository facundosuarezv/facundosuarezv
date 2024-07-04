#include <stdio.h>
#include <stdio.h>
#include <string.h>

#define FILAS 10
#define COLUMNAS 20

void print_array(char array[FILAS][COLUMNAS], int filas);
void insertion_sort(char array[FILAS][COLUMNAS], int filas);

int main() {
    char matriz[FILAS][COLUMNAS];

    // Leer las palabras y llenar la matriz
    for (int i = 0; i < FILAS; i++) {
        char palabra[COLUMNAS];
        printf("Ingrese la palabra numero %d: ", i + 1);
        scanf("%s", palabra);
        int len_palabra = strlen(palabra);

        // Copiar la palabra a la matriz
        for (int j = 0; j < len_palabra; j++) {
            matriz[i][j] = palabra[j];
        }
        // Rellenar el resto de la fila con espacios en blanco
        for (int j = len_palabra; j < COLUMNAS; j++) {
            matriz[i][j] = ' ';
        }
    }

    // Ordenar las filas de la matriz
    insertion_sort(matriz, FILAS);

    // Imprimir la matriz ordenada
    print_array(matriz, FILAS);

    return 0;
}

void print_array(char array[FILAS][COLUMNAS], int filas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c", array[i][j]);
        }
        printf("\n");
    }
}

void insertion_sort(char array[FILAS][COLUMNAS], int filas) {
    for (int i = 1; i < filas; i++) {
        char key[COLUMNAS];
        // Copiar la fila i a la clave
        strcpy(key, array[i]);
        int j = i - 1;

        // Mover las filas mayores a la clave una posición adelante
        while (j >= 0 && strcmp(array[j], key) > 0) {
            strcpy(array[j + 1], array[j]);
            j = j - 1;
        }
        // Colocar la clave en su posición correcta
        strcpy(array[j + 1], key);
    }
}
