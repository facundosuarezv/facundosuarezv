#include <stdio.h>

int main(){

    int enfermedad , causaspersonales , licenciagremial;
    int total_inasistencias = 0 , total_enfermedad = 0 , total_causasp = 0 , total_licenciag = 0;
    float porc_en , porc_cp , porc_lg;

    for (int dias = 1; dias <= 5; dias++){
        enfermedad = 0, causaspersonales = 0, licenciagremial = 0;
        printf("Ausencias en el dia %d \n", dias);
        printf("Ingrese cantidad deinasistencias por enfermedad: ");
        scanf("%d", &enfermedad);
        printf("Ingrese cantidad deinasistencias por causas personales: ");
        scanf("%d", &causaspersonales);
        printf("Ingrese cantidad deinasistencias por licencia gremial: ");
        scanf("%d", &licenciagremial);

        printf("En el dia %d faltaron: \n %d por enfermedad \n %d por causas personales \n %d por licencia gremial \n \n" , dias, enfermedad, causaspersonales, licenciagremial);

        total_enfermedad += enfermedad;
        total_causasp += causaspersonales;
        total_licenciag += licenciagremial;                
    }
    total_inasistencias = total_enfermedad + total_causasp + total_licenciag;
    
    porc_en = (float) total_enfermedad * 100 / total_inasistencias;
    porc_cp = (float) total_causasp * 100 / total_inasistencias;
    porc_lg = (float) total_licenciag * 100 / total_inasistencias;

    printf("el porcentaje de faltas por enfermedad es de %.2f%% \n", porc_en);
    printf("el porcentaje de faltas por causas personales es de %.2f%% \n", porc_cp);
    printf("el porcentaje de faltas por licencia gremial es de %.2f%% \n", porc_lg);

}