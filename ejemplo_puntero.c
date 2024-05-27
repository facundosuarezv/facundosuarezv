#include<stdio.h>
#include<stdlib.h> // Incluir la librería para la función system()

int num, *punteroNumero;

int main() {
    printf("Ejemplo de uso de punteros\n");
    printf("Ingrese un numero: ");
    scanf("%d", &num); // Lectura normal de un valor
    

    punteroNumero = &num; // Asigno a la variable punteroNumero la dirección de num

    printf("Ingreso: %d\nLa variable punteroNumero contiene: %d\n", num, *punteroNumero); // Muestro el contenido
    getchar(); // Esperar a que el usuario presione una tecla

    

    *punteroNumero = 10; // Modificamos la información de num a través del puntero a su dirección de memoria
    printf("Ahora la variable 'num' tiene valor: %d\n", num); // Verificamos que efectivamente se modificó el valor
    getchar(); // Esperar a que el usuario presione una tecla

    
    return 0;
}
