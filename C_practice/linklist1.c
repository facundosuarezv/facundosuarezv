#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[30];
    int nota;
}alumnos;

typedef struct node{
    alumnos alumno;
    struct node* next;
}node;

typedef struct {
    node* head;
}lista;

lista* iniciarlista();
node* crearnodo(char* nombre, int nota);
void agregarnodo(lista* lista, char* nombre, int nota);
void imprimiraprobados(lista* lista);


int main(){
    lista* lista=iniciarlista();

    char nombre[30];
    int nota;
    char haymas = 's';

    do{
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);
        printf("Ingrese la nota del alumno: ");
        scanf("%d", &nota);
        agregarnodo(lista, nombre, nota);

        printf("Hay mas alumnos que agregar? (s/n): ");
        scanf(" %c", &haymas);
    }while(haymas == 's' || haymas =='S');

    printf("\nLista de alumnos:\n");
    imprimiraprobados(lista);


    return 0;    
}

lista* iniciarlista(){
    lista *lista =malloc(sizeof(lista));
    lista->head =NULL;
    return lista;
}

node* crearnodo(char* nombre, int nota){
    node* nuevonodo = malloc(sizeof(node));
    strcpy(nuevonodo->alumno.nombre, nombre);
    nuevonodo->alumno.nota = nota;
    nuevonodo->next = NULL;
    return nuevonodo;
}

void agregarnodo(lista* lista, char* nombre, int nota){ //En este el nodo se agrega al final de la lista
    node* nuevonodo = crearnodo(nombre,nota);
    if(lista->head == NULL){
        lista->head = nuevonodo;
    }else{
        node* temp = lista->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nuevonodo;
    }
}

void agregarNodoInicio(lista* lista, char* nombre, int nota) {  //En este el nodo se agrega al inicio de la lista
    node* nuevoNodo = crearnodo(nombre, nota);
    nuevoNodo->next = lista->head;
    lista->head = nuevoNodo;
}


void imprimirlista(lista* lista){ //Esta no se usa pero es para imprimir toda la lista
    node* temp = lista->head;
    while(temp != NULL){
        printf("alumno %s, Nota: %d\n", temp->alumno.nombre, temp->alumno.nota);
        temp = temp->next;
    }
}

void imprimiraprobados(lista* lista){
    node* temp = lista->head;
    while (temp != NULL){
        if (temp->alumno.nota >= 4){
            printf("%s\n", temp->alumno.nombre);
            temp = temp->next;
        }
    }
}


void liberarlista(lista* lista){
    node* temp = lista->head;
    while(temp != NULL){
        node* siguiente = temp->next;
        free(temp);
        temp = siguiente;
    }
    free(lista);
}