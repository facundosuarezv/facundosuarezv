#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[30];
} alumnos;

typedef struct node {
    alumnos alumno;
    struct node *next;
} node;

typedef struct {
    node *head;
} lista;

// Inicializar la lista
lista* inicializarlista() {
    lista* nuevaLista = (lista*)malloc(sizeof(lista));
    nuevaLista->head = NULL;
    return nuevaLista;
}

// Función para crear un nuevo nodo
node* crearNodo(char* nombre) {
    node* nuevoNodo = (node*) malloc(sizeof(node));
    strcpy(nuevoNodo->alumno.nombre, nombre);
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

// Función para agregar un nodo al principio de la lista
void agregarNodoInicio(lista* lista, char* nombre) {
    node* nuevoNodo = crearNodo(nombre);
    nuevoNodo->next = lista->head;
    lista->head = nuevoNodo;
}

// Función para imprimir la lista
void imprimirLista(lista* lista) {
    node* temp = lista->head;
    while (temp != NULL) {
        printf("Alumno: %s\n", temp->alumno.nombre);
        temp = temp->next;
    }
}

// Función para liberar la memoria de la lista
void liberarLista(lista* lista) {
    node* temp = lista->head;
    while (temp != NULL) {
        node* siguiente = temp->next;
        free(temp);
        temp = siguiente;
    }
    lista->head = NULL;  // Asegurarse de que la lista esté vacía después de liberar
}

// Función para eliminar un nodo con un nombre específico
void eliminarnodo(lista* lista, char* nombre) {
    node* temp = lista->head;
    node* prev = NULL;

    // Si la lista está vacía
    if (temp == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    // Si el nodo a eliminar es el primero de la lista
    if (strcasecmp(temp->alumno.nombre, nombre) == 0) {
        lista->head = temp->next;
        free(temp);
        printf("Nodo con nombre '%s' eliminado.\n", nombre);
        return;
    }

    // Buscar el nodo a eliminar
    while (temp != NULL && strcasecmp(temp->alumno.nombre, nombre) != 0) {
        prev = temp;
        temp = temp->next;
    }

    // Si no se encontró el nodo
    if (temp == NULL) {
        printf("Nodo con nombre '%s' no encontrado.\n", nombre);
        return;
    }

    // Desenlazar el nodo de la lista
    prev->next = temp->next;
    free(temp);
    printf("Nodo con nombre '%s' eliminado.\n", nombre);
}

int main() {
    lista* lista = inicializarlista();

    char nombre[30];
    char haymas = 's';

    do {
        printf("Ingrese el nombre del alumno: ");
        scanf("%s", nombre);
        agregarNodoInicio(lista, nombre);

        printf("Hay mas alumnos que agregar? (s/n): ");
        scanf(" %c", &haymas); // Espacio antes de %c para consumir el '\n' anterior
    } while (haymas == 's' || haymas == 'S');

    printf("\nLista de alumnos:\n");
    imprimirLista(lista);

    // Eliminar un nodo
    printf("Ingrese el nombre del alumno a eliminar: ");
    scanf("%s", nombre);
    eliminarnodo(lista, nombre);

    printf("\nLista de alumnos despues de eliminar:\n");
    imprimirLista(lista);

    liberarLista(lista);
    free(lista); 

    return 0;
}
