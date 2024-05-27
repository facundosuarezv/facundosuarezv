#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constantes
#define PORCENTAJE 0.3
float costo[] = {2437.35, 3934.55, 5870.23, 7023.78};
int MinxPlan[] = {132, 326, 446, 497};

// Variables de entrada
int PlanUs;
int MinUS;
int bonif;

// Prototipo de la función
bool correspondeBonif(int i, int minutosLibres);

int main() {
    // Ingreso de datos de usuario
    printf("Introduzca el numero de plan: \n");
    scanf("%d", &PlanUs);
    printf("Introduzca la cantidad de minutos utilizados: \n");
    scanf("%d", &MinUS);
    system("clear");

    int search_plan = PlanUs - 1; //para corregir la busqueda en el arreglo del plan y costo
    // Evaluo si corresponde bonif
    if (correspondeBonif(search_plan, MinUS)) {
        // de ser verdadero calculo la bonificacion y monto final
        bonif = PORCENTAJE * costo[search_plan];
        int monto_final = costo[search_plan] - bonif;

        // imprimo el monto final con su bonificacion
        printf("El monto final a abonar es %d con una bonificacion de %d\n", monto_final, bonif);
    } else { // si es falso el costo final es el mismo, pero evaluo porque no tuvo descuento
        bonif = 0;
        int monto_final = costo[search_plan];

        printf("El monto final a abonar es %d. Su bonificacion es de %d pesos\n", monto_final, bonif);

        double porc_min = (double) MinUS / MinxPlan[search_plan]; // porcentaje de minutos usados por el usuario

        if (porc_min < 0.85) {
            printf("por bajo consumo\n");
        } else {
            printf("por exceso de consumo\n");
        }
    }
    return 0;
}

bool correspondeBonif(int i, int minutosLibres) {
    double porc_min = (double) minutosLibres / MinxPlan[i]; // porcentaje de minutos usados por el usuario
    return (porc_min > 0.85 && porc_min < 1);
}
