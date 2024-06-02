/*Se desea calcular e imprimir el porcentaje de alumnos aprobados en una comisión de 40
alumnos y la nota promedio de aprobación. El porcentaje debe calcularse con 2 dígitos
decimales y la nota promedio debe ser entera y redondearse para abajo.*/

#include <stdio.h>

#define alumnos 10
#define aprobar 4

void ingreso_notas(int *cont_alumnos,float *suma_notas);
void calculos(float *porcentaje_pass,float *promedio_notas, int cont_aln, float suma_notas);

int main() {
    float porc_pass, nota_prom;
    float suma_notas_pass = 0;
    int countAl_pass= 0;

    
    ingreso_notas(&countAl_pass, &suma_notas_pass);
    calculos(&porc_pass,&nota_prom, countAl_pass, suma_notas_pass);

    printf("El porcentaje de alumnos aprobados es de %.2f%% \n", porc_pass);
    printf("La nota promedio de aprobacion es de %.0f \n", nota_prom);

    return 0;
}

void ingreso_notas(int *cont_alumnos, float *suma_notas){
    float nota = 0;

    for (int i = 0; i < alumnos; i++){
        printf("Ingrese la nota del alumno %d: \n", i + 1);
        scanf("%f", &nota);

        if(nota >= aprobar){
            (*cont_alumnos)++;
            (*suma_notas) += nota;
        }
    }
}
void calculos(float *porcentaje_pass,float *promedio_notas, int cont_aln, float suma_notas){
    *porcentaje_pass = (cont_aln * 100) / alumnos;
    if (cont_aln > 0){
        *promedio_notas = suma_notas / cont_aln;
    }else {
        *promedio_notas = 0;
    }
}

