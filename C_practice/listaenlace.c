#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
    char genero;
}personas;

typedef struct node {
    personas persona;
    struct node* next;
}node;

typedef struct {
    node* head;
}listapersonas;

listapersonas* inicializarlista() {
    listapersonas* nuevalista = (listapersonas*) malloc(sizeof(listapersonas));
    nuevalista->head = NULL;
    return nuevalista;
}

node* crearnodo(char* nombrep, char generop){
    node* nuevonodo = (node*)malloc(sizeof(node));
    strcpy(nuevonodo->persona.nombre, nombrep);
    nuevonodo->persona.genero = generop;
    nuevonodo->next = NULL;
    return nuevonodo;
}

void agregarnodo(listapersonas* lista, char* nombre, char genero){
    node* nuevonodo = crearnodo(nombre, genero);
    nuevonodo->next = lista->head;
    lista->head = nuevonodo;
}

void imprimirlista(listapersonas* lista){
    node* temp = lista->head;
    while (temp != NULL){
        printf("Nombre: %s Genero: %c\n", temp->persona.nombre, temp->persona.genero);
        temp = temp->next;
    }
    printf("---------------\n");
}

void liberarlista(listapersonas* lista){
    node* temp = lista->head;
    while (temp != NULL){
        node* siguiente = temp->next;
        free(temp);
        temp  = siguiente;
    }
    lista->head = NULL;
}

int contarxgenero(node* nodo, char genero){
    if (nodo == NULL){
        return 0;
    }

    int conteo = (nodo->persona.genero == genero) ? 1:0;

    return conteo + contarxgenero( nodo->next,genero);    
}


int main (){
    listapersonas* lista = inicializarlista();

    char nombre[30];
    char genero;
    char haymas ='s';

    do{
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);
        printf("Ingrese el genero del alumno: ");
        scanf(" %c", &genero);

        agregarnodo(lista, nombre, genero);
        printf("Hay mas alumnos que agregar? (s/n): ");
        scanf(" %c", &haymas);        
    } while (haymas =='s' || haymas == 'S');

    printf("\nLista de alumnos:\n");
    imprimirlista(lista);

    printf("Cantidad de hombres: %d\n", contarxgenero(lista->head,'m'));
    printf("Cantidad de mujeres: %d\n", contarxgenero(lista->head,'f'));

    liberarlista(lista);
    free(lista);
}