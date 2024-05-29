/*Se desea calcular e imprimir el porcentaje de alumnos aprobados en una comisión de 40
alumnos y la nota promedio de aprobación. El porcentaje debe calcularse con 2 dígitos
decimales y la nota promedio debe ser entera y redondearse para abajo.*/

#include <stdio.h>

#define alumnos 10
#define aprobar 4

int main() {
    float porc_pass, nota_prom, nota;
    float suma_notas_pass = 0;  // Cambié el nombre para mayor claridad
    int countAl_pass = 0;

    for (int i = 0; i < alumnos; i++) {
        printf("Ingrese la nota del alumno %d: \n", i + 1);
        scanf("%f", &nota);

        if (nota >= aprobar) {  // Condición corregida
            countAl_pass++;
            suma_notas_pass += nota;  // Acumular la nota aprobada
        }
    }

    porc_pass = (countAl_pass * 100.0) / alumnos;
    if (countAl_pass > 0) {
        nota_prom = suma_notas_pass / countAl_pass;
    } else {
        nota_prom = 0;  // Evitar división por cero
    }

    printf("El porcentaje de alumnos aprobados es de %.2f%% \n", porc_pass);
    printf("La nota promedio de aprobacion es de %.0f \n", nota_prom);

    return 0;
}


