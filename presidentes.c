#include <stdio.h>

int main() {
    int votos[4], total = 0, max_votos = 0, indice_ganador = 0;
    float pvotos[4];

    // Entrada de votos para cada candidato
    for (int i = 0; i < 4; i++) {
        printf("Ingrese la cantidad de votos recibidos por el candidato número %d: ", i + 1);
        scanf("%d", &votos[i]);
        total += votos[i];
        
        // Comparar y determinar el ganador
        if (votos[i] > max_votos) {
            max_votos = votos[i];
            indice_ganador = i;
        }
    }

    // Calcular el porcentaje de votos de cada candidato
    for (int i = 0; i < 4; i++) {
        pvotos[i] = (float)votos[i] * 100 / total;
        printf("El porcentaje de votos del candidato número %d es de %.2f%% \n", i + 1, pvotos[i]);
    }

    // Mostrar el candidato ganador
    printf("El ganador es el candidato número %d con %d votos.\n", indice_ganador + 1, max_votos);

    return 0;
}
