#include <stdio.h>
#define VUELOS 2

// Declaración de variables globales
int totalSolicitudes = 0; //contadores 
int totalValijas20kg = 0; //contadores
int maxValijasRechazadas = 0; 
int aeropuertoExcedido1 = 0, aeropuertoExcedido2 = 0, aeropuertoExcedido3 = 0, aeropuertoExcedido4 = 0; //Flag

// Modulos:
// Función para leer capacidad de bodega y número de aeropuerto
void leerCapacidadYAeropuerto(int *capacidadBodega, int *aeropuerto, int numeroVuelo); //declaracion para indicar que modulos existen
// Función para leer solicitudes de valijas
void leerSolicitudes(int *solicitudes20kg, int *solicitudes32kg, int *totalSolicitudesPorVuelo);
// Función para calcular valijas rechazadas
void calcularValijasRechazadas(int capacidadBodega, int totalSolicitudesPorVuelo, int aeropuerto);
// Función para calcular porcentaje de valijas de 32kg
float calcularPorcentaje32kg(int solicitudes32kg, int totalSolicitudesPorVuelo);
// Función para reportar resultados por vuelo
void reportarPorVuelo(int numeroVuelo, float porcentaje32kg);
// Función para imprimir resultados finales
void imprimirResultadosFinales(); //void no da ningun valor de retorno

int main() {
    // Bucle for para repetir la secuencia de ingreso para todos los vuelos
    for (int numeroVuelo = 1; numeroVuelo <= VUELOS; numeroVuelo++) { //numerovuelvo es un contador, 
        // Inicializo contadores para cada iteración
        int capacidadBodega, aeropuerto;
        int solicitudes20kg = 0, solicitudes32kg = 0, totalSolicitudesPorVuelo = 0; //contadores

        leerCapacidadYAeropuerto(&capacidadBodega, &aeropuerto, numeroVuelo); //llamada al modulo 1

        leerSolicitudes(&solicitudes20kg, &solicitudes32kg, &totalSolicitudesPorVuelo); //llamada modulo 2

        calcularValijasRechazadas(capacidadBodega, totalSolicitudesPorVuelo, aeropuerto); //llamada al modulo 3

        float porcentaje32kg = calcularPorcentaje32kg(solicitudes32kg, totalSolicitudesPorVuelo); //llamada al modulo 4

        reportarPorVuelo(numeroVuelo, porcentaje32kg); //llamada al modulo 5
    }

    imprimirResultadosFinales(); //llamada al sexto modulo, impresion de resultados

    return 0;
}

void leerCapacidadYAeropuerto(int *capacidadBodega, int *aeropuerto, int numeroVuelo) { //modulo 1. (parametros, indicar las variables que voy a usar y alojar la informacion en la memoria) procedimiento. capacidad de bodega y aeropuerto 
    printf("Ingrese la capacidad de bodega del vuelo %d: \n", numeroVuelo);
    scanf("%d", capacidadBodega);

    printf("Ingrese el numero del aeropuerto (1 a 4) del vuelo %d: \n", numeroVuelo);
    scanf("%d", aeropuerto);

    while (*aeropuerto < 1 || *aeropuerto > 4) { //las dos barras verticales significa or
        printf("Numero invalido, ingreselo nuevamente: \n");
        scanf("%d", aeropuerto); // por si se ingresa otro numero de aeropuerto
    }
}  // en este moudlo establecemos la capacidad maxima de bodega por vuelo, el numero de aereopuerto 

void leerSolicitudes(int *solicitudes20kg, int *solicitudes32kg, int *totalSolicitudesPorVuelo) {  //segundo modulo(procedimiento) ((parametros, indicar las varaibles que voy a utilizar y mandar la informaicon)) que calcula solicitud de 20 y 32
    int pesoValija, hayValijas = 1; // variables locales, variables solamente para este modulo y poder calcular el peso y la cantidad de valijas
    
    while (hayValijas) {
        printf("Ingrese el peso de la valija (20kg o 32kg) o (0) para terminar el ingreso: \n");
        scanf("%d", &pesoValija);
        
        if (pesoValija == 0) { //para evitar la pregunta hay valijas, se poner 0 para terminar
            hayValijas = 0;
        } else { //si hay valijas, entonces:
            if (pesoValija == 20) {
                (*solicitudes20kg)++;
                totalValijas20kg++;
            } else if (pesoValija == 32) {
                (*solicitudes32kg)++;
            }
            (*totalSolicitudesPorVuelo)++; // es para sumar de a 1, el asterisco sirve para almacenar por referencia, guarda en la memoria donde esta alojada la variable. acumlando
            totalSolicitudes++;
        } 
    }  // este moudlo lo que hacemos al calcular las solicitudes de las valijas de 20 y de 32. Lo primero que haces es preguntar si hay valijas, luego a traves de las condiciones vamos analizando.
       // la primara condicion es si el peso de valija es de 20 kg lo suma a la variables por referencia solcitudes20 kg. c
       // la segunda condicion es si el peso de valija es de 32 kg lo suma a la variables por referencia solcitudes32 kg. c
}      // la ultimo que hace, que esa encadenada el primero if, va sumando el total de solicitudes de las valijas por vuelo.
       // el numero cero indica que ya no hay mas valijas y da fin a este apartado.

void calcularValijasRechazadas(int capacidadBodega, int totalSolicitudesPorVuelo, int aeropuerto) { //tecer mododulo (funcion), calculos por eso no esta el asterisco del comienzo
    int valijasRechazadas = 0; //esta por copia y no por referencia, porque calculamos con valor obtenido hasta el momento

    if (totalSolicitudesPorVuelo > capacidadBodega) {
        valijasRechazadas = totalSolicitudesPorVuelo - capacidadBodega;
        if (valijasRechazadas > maxValijasRechazadas) {
            maxValijasRechazadas = valijasRechazadas;
        }
        // este modulo lo primero que haces es preguntar si hay valijas rechazadas. En el caso de haya comprueba el total de las solicutides  de valijas rechazadas por vuelo y la capacidad
        // Si total de solicitudes por vuelo es mayor a la capacidad de la bodega entonces al total de solicidudes por vuelo le resto la capacidad de bodega para obtener ese numero.
        //el paso siguiente es comparar entre la mayor cantidad de valijas rechazdas, eso se hace comparando en cada vuelo dicha cantidad y se queda con la mayor.
        
        // Registrar aeropuerto excedido de capacidad
        switch (aeropuerto) { //casos para analizar los aeropuertos, porque hay que buscar que aeropuerto fue excedido en valijas, aca esta la variables aereopuereto
            case 1: //caso de que aereopuerto, en este caso es el 1, calcula en dicho aereopuerto
                aeropuertoExcedido1 = 1;
                break;
            case 2: //lo mismos pero con el 2
                aeropuertoExcedido2 = 1;
                break;
            case 3: //lo mismo con el 3
                aeropuertoExcedido3 = 1;
                break;
            case 4: //lo mismo con el 4
                aeropuertoExcedido4 = 1;
                break;
            default: // por si ingresa otro numero
                break;
                // lo que hace aca es ver en que aerepuerto se excedio la capidad.
        }
    }
}

float calcularPorcentaje32kg(int solicitudes32kg, int totalSolicitudesPorVuelo) { //cuarto modulo (funcion), para calcular las solicitudes de valijas de 32 y el total por vuelo.
    if (totalSolicitudesPorVuelo > 0) {
        return ((float)solicitudes32kg / totalSolicitudesPorVuelo) * 100;
    }
    return 0.0;
}  // en este modulo calculoamos el porcentaje de de solicitudes de valijas de 32 kg. Se establece la primer condiciones, si total solicitudes por vuevlo es mayor a cero,
   // entonces calculaomos el porcentaje con ese calculo solituces de 32 kg dividido el total de las solicitudes por vuelvo, mutiplicado por 100.

void reportarPorVuelo(int numeroVuelo, float porcentaje32kg) { //quinto modulo (funcion, por copia), porque no esta el ampersan que es donde esta la memoria ni el asterisco, que manda la informacion.
    printf("Orden de vuelo: %d \n", numeroVuelo); // calculamos por vuelo el porentaje de valijas de 32 kg
    printf("Porcentaje de solicitudes de valijas de 32kg para el vuelo %d es de: %.2f%% \n---------------\n", numeroVuelo, porcentaje32kg);
}                                                                 //numero de vuelo //porcentaje 
  //este modulo imprime dos cosas, por un lado el numero de orden de vuelo y por otro el porcentaje de las solicitudes de 32 por cada vuelo.


void imprimirResultadosFinales() { //sexto modulo copia, es un procedimiento  que imprime los resultados
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
    printf("Promedio de valijas solicitadas por vuelo: %.2f \n", (float)totalSolicitudes / VUELOS); //
} 

 // en este ultimo modulo, solo imprimimos los resultados de todo la informaicon obtenida en los modulos anteriores.