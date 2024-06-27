#include <stdio.h>
#define vuelos 2

//Declaracion de variables a utilizar
int capacidadBodega, solicitudes20kg, solicitudes32kg;
float porcentake32kg, promedioValijasPorVuelo;
int aeropuerto;

//Inicializo variables
int totalSolicitudes = 0;
int totalValijas20kg = 0;
int maxValijasRechazadas = 0;
int valijasRechazadas = 0;
int aeropuertoexcedido1 = 0;
int aeropuertoexcedido2 = 0;
int aeropuertoexcedido3 = 0;
int aeropuertoexcedido4 = 0;


int main(){
    //Bucle for para repetir la secuencia de ingreso para todos los vuelos
    for (int numero_vuelo = 1; numero_vuelo <= vuelos; numero_vuelo++){

        //Inicializo contadores para cada iteracion
        int totalSolicitudesPorVuelo = 0;
        int pesoValija;
        int hay_valijas = 1;
        solicitudes20kg = 0;
        solicitudes32kg = 0;

        //Ingreso capacidad de bodega del vuelo
        printf("Ingrese la capacidad de bodega del vuelo %d: \n", numero_vuelo);
        scanf("%d", &capacidadBodega);

        //Ingreso el numero de aeropuerto
        printf("Ingrese el numero del aeropuerto (1 a 4) del vuelo %d: \n", numero_vuelo);
        scanf("%d", &aeropuerto);

        while (aeropuerto < 1 || aeropuerto > 4){
            printf("Numero invalido, ingreselo nuevamente: \n");
            scanf("%d", &aeropuerto);
        }

        //Comienzo a leer las solicitudes de valijas
        while(hay_valijas == 1){
            printf("Ingrese el peso de la valija (20kg o 32kg) o (0) para terminar el ingreso: \n");
            scanf("%d", &pesoValija);
            if (pesoValija == 0){
                hay_valijas = 0;
            }else{

                if (pesoValija == 20){
                    solicitudes20kg++;
                    totalValijas20kg++;
                }else{
                    solicitudes32kg++;
                }
                totalSolicitudesPorVuelo++; //Contador solicitudes por vuelo
                totalSolicitudes++; //Contador solicitudes TOTALES
            }
        }
        //Calculo de valijas rechazadas
        if (totalSolicitudesPorVuelo > capacidadBodega){
            valijasRechazadas = totalSolicitudesPorVuelo - capacidadBodega;
            if (valijasRechazadas > maxValijasRechazadas){
                maxValijasRechazadas = valijasRechazadas;
            } 
            
            //Registrar aeropuerto excedido de capacidad
            switch (aeropuerto){
            case 1:
                aeropuertoexcedido1 = 1;
                break;
            case 2 :
                aeropuertoexcedido2 = 1;                
                break;
            case 3:
                aeropuertoexcedido3 = 1;
                break;
            case 4:
                aeropuertoexcedido4 = 1;
                break;
            
            default:
                break;
            }
        }

        //Calculo porcentaje de solicitudes de 32kg
        if (totalSolicitudesPorVuelo > 0){
            porcentake32kg = (solicitudes32kg * 100)/totalSolicitudesPorVuelo;
        }else{porcentake32kg = 0;} 

        //Imprimo el orden de vuelo y el porcentaje de solicitudes de 32kg (punto 2)
        printf("Orden de vuelo: %d \n", numero_vuelo);
        printf("Porcentaje de solicitudes de valijas de 32kg para el vuelo %d es de: %.2f%% \n---------------\n", numero_vuelo, porcentake32kg);       
    }

    //Calculo de promedio de valijas por vuelo
    promedioValijasPorVuelo = totalSolicitudes / vuelos;

    //Impresiones finales
    //Punto 1
    printf("Aeropuertos con vuelos que excedieron la capacidad de bodega: \n");

    if(aeropuertoexcedido1 == 1){
        printf("Aeropuerto 1 \n");
    }
    if(aeropuertoexcedido2 == 1){
        printf("Aeropuerto 2 \n");
    }
    if(aeropuertoexcedido3 == 1){
        printf("Aeropuerto 3 \n");
    }
    if(aeropuertoexcedido4 == 1){
        printf("Aeropuerto 4 \n");
    }
    printf("Maxima cantidad de valijas rechazadas en un vuelo: %d \n", maxValijasRechazadas); //Punto 3
    printf("Total de solicitudes de valijas de 20kg: %d \n", totalValijas20kg); //Punto 4
    printf("Promedio de valijas solicitadas por vuelo: %.2f \n", promedioValijasPorVuelo); //Punto 5
}