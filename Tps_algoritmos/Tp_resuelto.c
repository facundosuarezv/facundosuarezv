#include <stdio.h>
#define VUELOS 120

// Declaración de variables globales
int totalSolicitudes = 0;
int totalValijas20kg = 0;
int maxValijasRechazadas = 0;
int aeropuertoExcedido1 = 0, aeropuertoExcedido2 = 0, aeropuertoExcedido3 = 0, aeropuertoExcedido4 = 0; //Flag

// Modulos:
// Función para leer capacidad de bodega y número de aeropuerto
void leerCapacidadYAeropuerto(int *capacidadBodega, int *aeropuerto, int numeroVuelo);
// Función para leer solicitudes de valijas
void leerSolicitudes(int *solicitudes20kg, int *solicitudes32kg, int *totalSolicitudesPorVuelo);
// Función para calcular valijas rechazadas
void calcularValijasRechazadas(int capacidadBodega, int totalSolicitudesPorVuelo, int aeropuerto);
// Función para calcular porcentaje
float calculoPorcentaje(int cantidad_parcial, int cantidad_total);
// Función para reportar resultados por vuelo
void reportarPorVuelo(int numeroVuelo, float porcentaje32kg);
// Función para imprimir resultados finales
void imprimirResultadosFinales();

int main() {
    // Bucle for para repetir la secuencia de ingreso para todos los vuelos
    for (int numeroVuelo = 1; numeroVuelo <= VUELOS; numeroVuelo++) {
        // Inicializo contadores para cada iteración
        int capacidadBodega, aeropuerto;
        int solicitudes20kg = 0, solicitudes32kg = 0, totalSolicitudesPorVuelo = 0;
        float porcentaje32kg = 0;

        leerCapacidadYAeropuerto(&capacidadBodega, &aeropuerto, numeroVuelo);

        leerSolicitudes(&solicitudes20kg, &solicitudes32kg, &totalSolicitudesPorVuelo);

        calcularValijasRechazadas(capacidadBodega, totalSolicitudesPorVuelo, aeropuerto);

        if (totalSolicitudesPorVuelo > 0){
            float porcentaje32kg = calculoPorcentaje(solicitudes32kg, totalSolicitudesPorVuelo);
        }

        reportarPorVuelo(numeroVuelo, porcentaje32kg);
    }

    imprimirResultadosFinales();

    return 0;
}

void leerCapacidadYAeropuerto(int *capacidadBodega, int *aeropuerto, int numeroVuelo) {
    printf("Ingrese la capacidad de bodega del vuelo %d: \n", numeroVuelo);
    scanf("%d", capacidadBodega);

    printf("Ingrese el numero del aeropuerto (1 a 4) del vuelo %d: \n", numeroVuelo);
    scanf("%d", aeropuerto);

    while (*aeropuerto < 1 || *aeropuerto > 4) {
        printf("Numero invalido, ingreselo nuevamente: \n");
        scanf("%d", aeropuerto);
    }
}

void leerSolicitudes(int *solicitudes20kg, int *solicitudes32kg, int *totalSolicitudesPorVuelo) {
    int pesoValija, hayValijas = 1;
    
    while (hayValijas) {
        printf("Ingrese el peso de la valija (20kg o 32kg) o (0) para terminar el ingreso: \n");
        scanf("%d", &pesoValija);
        
        if (pesoValija == 0) {
            hayValijas = 0;
        } else {
            if (pesoValija == 20) {
                (*solicitudes20kg)++;
                totalValijas20kg++;
            } else if (pesoValija == 32) {
                (*solicitudes32kg)++;
            }
            (*totalSolicitudesPorVuelo)++;
            totalSolicitudes++;
        }
    }
}

void calcularValijasRechazadas(int capacidadBodega, int totalSolicitudesPorVuelo, int aeropuerto) {
    int valijasRechazadas = 0;

    //Evaluo si hay o no valijas rechazadas
    if (totalSolicitudesPorVuelo > capacidadBodega) {
        valijasRechazadas = totalSolicitudesPorVuelo - capacidadBodega;
        if (valijasRechazadas > maxValijasRechazadas) {
            maxValijasRechazadas = valijasRechazadas;
        }

        // En caso de que haya valijas rechazadas, registra el aeropuerto excedido de capacidad
        switch (aeropuerto) {
            case 1:
                aeropuertoExcedido1 = 1;
                break;
            case 2:
                aeropuertoExcedido2 = 1;
                break;
            case 3:
                aeropuertoExcedido3 = 1;
                break;
            case 4:
                aeropuertoExcedido4 = 1;
                break;
            default:
                break;
        }
    }
}

float calculoPorcentaje(int cantidad_parcial, int cantidad_total) {
        return ((float)cantidad_parcial / cantidad_total) * 100;
}

void reportarPorVuelo(int numeroVuelo, float porcentaje32kg) {
    printf("Orden de vuelo: %d \n", numeroVuelo);
    printf("Porcentaje de solicitudes de valijas de 32kg para el vuelo %d es de: %.2f%% \n---------------\n", numeroVuelo, porcentaje32kg);
}

void imprimirResultadosFinales() {
    printf("Aeropuertos con vuelos que excedieron la capacidad de bodega: \n");
    if (aeropuertoExcedido1 == 1) {
        printf("Aeropuerto 1 \n");
    }
    if (aeropuertoExcedido2 == 1) {
        printf("Aeropuerto 2 \n");
    }
    if (aeropuertoExcedido3 == 1) {
        printf("Aeropuerto 3 \n");
    }
    if (aeropuertoExcedido4 == 1) {
        printf("Aeropuerto 4 \n");
    }

    printf("Maxima cantidad de valijas rechazadas en un vuelo: %d \n", maxValijasRechazadas);
    printf("Total de solicitudes de valijas de 20kg: %d \n", totalValijas20kg);
    printf("Promedio de valijas solicitadas por vuelo: %.2f \n", (float)totalSolicitudes / VUELOS);
}