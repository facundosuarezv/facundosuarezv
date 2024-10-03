#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node* next;
}node;

typedef struct {
    node* Pfin;
    node* Pinicio;
} fila;

fila* inicializarfila() {
    fila* nuevafila = (fila*)malloc(sizeof(fila));
    nuevafila->Pfin = NULL;
    nuevafila->Pinicio = NULL;
    return nuevafila;
}

bool esvacia(fila* fila) {
    return fila->Pinicio == NULL;
}


node* crearnodo(int numero){
    node* nuevonodo = (node*)malloc(sizeof(node));
    nuevonodo->numero = numero;
    nuevonodo->next = NULL;
    return nuevonodo;
}

void agregarnodofila (fila* fila, int numero){
    node* nuevonodo = crearnodo(numero);
    if (esvacia(fila)){
        fila->Pinicio = nuevonodo;
    }else{
        fila->Pfin->next = nuevonodo;
    }
    fila->Pfin = nuevonodo;
}

void sacardefila(fila* fila) {
    if (esvacia(fila)) {
        printf("La fila está vacía.\n");
        return;
    }
    node* temp = fila->Pinicio;
    fila->Pinicio = temp->next;   
    free(temp);
}

void imprimirfila(fila* fila){
    
    node* temp = fila->Pinicio;
    while(temp != NULL){
        printf("%d, ", temp->numero);
        temp = temp->next;
    }
}

int main(){
    fila* fila= inicializarfila();

    int numero;
    int eleccion;
    do{
        printf("\n1-Agregar numero\n2-Quitar de la fila\n0-Terminar\n-> ");
        
        scanf("%d",&eleccion);
        if (eleccion==1){
            printf("Ingresa el numero: \n");
            scanf("%d", &numero);
            agregarnodofila(fila,numero);
            imprimirfila(fila);
        }else if (eleccion == 2){
            sacardefila(fila);
            imprimirfila(fila);
        }
    } while(eleccion != 0);
    printf("---fila final---\n");

    imprimirfila(fila);

    return 0;
}