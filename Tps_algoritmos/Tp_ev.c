#include <stdio.h>
#include <stdbool.h>

#define vuelos 5

// Declaramos las variables a utilizar
int total_valijas, total_valijas20kg, total_valijas32kg, total_valijasxvuelo; 
int valijas20kgA1, valijas20kgA2, valijas20kgA3, valijas20kgA4;
int valijas32kgA1, valijas32kgA2, valijas32kgA3, valijas32kgA4;
int numero_vuelo, numero_aeropuerto, maxvalijasrechazadas,valijas_rechazadas, capacidadbodega;
int overcapacityA1 ,overcapacityA2, overcapacityA3, overcapacityA4;
float porcentaje_valijas32kg, promedio_valijas;

//Inicializamos variables
total_valijas = 0;
maxvalijasrechazadas = 0; 

//contador para valijas 20kg x aeropuerto
valijas20kgA1 = 0;
valijas20kgA2 = 0;
valijas20kgA3 = 0;
valijas20kgA4 = 0;

//contador para valijas 32kg x aeropuerto
valijas32kgA1 = 0;
valijas32kgA2 = 0;
valijas32kgA3 = 0;
valijas32kgA4 = 0;

overcapacityA1 = false;
overcapacityA2 = false;
overcapacityA3 = false;
overcapacityA4 = false;

int main (){
    for (numero_vuelo = 1; numero_vuelo <= vuelos; numero_vuelo++){
        total_valijasxvuelo = 0;
        total_valijas20kg = 0;
        total_valijas32kg = 0;
        valijas_rechazadas = 0;

        printf("Ingrese la capacaidad de bodega del vuelo: ");
        scanf("%d", &capacidadbodega);
        printf("Ingrese el numero de aeropuerto (1 a 4) del vuelo: ")
        scanf("%d", &numero_aeropuerto);

        while (numero_aeropuerto <1 || numero_aeropuerto >4){
            printf("Numero de aeropuerto inválido. Por favor ingrese un número entre 1 y 4");
            scanf("%d", &numero_aeropuerto);
        }
        
    }
}