#include <stdio.h>
#include <string.h>
#include <stdbool.h>


int main (){
    // Declaración e inicialización de variables
    int total= 0 ,  totalxciudad = 0 ,  cant_si= 0 ,  cant_no= 0 ;  
    char resp[3];

    // Iterar para cada ciudad a encuestar
    for (int ciudad = 1; ciudad <= 5; ciudad++){
        printf("Preguntas para la ciudad numero %d \n", ciudad);
        totalxciudad = 0; // Inicializar contador para cada ciudad
        bool hay = true;
        
        //Hacer las preguntas mientras haya gente que encuestar (hay=Y)
        while (hay){
            totalxciudad++;
            for (int pregunta = 1; pregunta <= 4; pregunta++){
                printf("Respuesta a la pregunta %d (Y/N): \n", pregunta);
                scanf("%s", resp);

                //Evaluo la respuesta
                if (strcmp(resp, "Y") == 0 || strcmp(resp, "y") == 0){
                    cant_si++;
                }else{
                    cant_no++;
                }
            }

            printf("Hay mas gente para entrevistar?(1 para si 0 para no): \n");
            int nhay = 1;
            scanf("%d", &nhay);
            if (nhay == 0){
                hay = false;
            }
            
        }

        printf("La cantidad de encuestados en la ciudad %d es %d personas.\n", ciudad, totalxciudad);
        total += totalxciudad;
    }

    printf("La cantidad de respuestas positivas es de %d \n", cant_si);
    printf("La cantidad de respuestas negativas es de %d \n", cant_no);
    printf("La cantidad total de encuestados es de %d personas \n", total);  
}