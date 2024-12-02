#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar un periodista
typedef struct {
    int idPeriodista;
    char nombre[50];
    char apellido[50];
    char pasaporte[20];
    char medio[50];
    int tipoCredencial; // 1: Hospitality, 2: Boxes, 3: Palcos
    int incluyeComida;  // 1: Sí, 0: No
} Periodista;

// Nodo para la lista enlazada
typedef struct Nodo {
    Periodista periodista;
    struct Nodo* siguiente;
} Nodo;

// Función para insertar en una cola
void insertarEnCola(Nodo** frente, Nodo** fin, Periodista p) {
    Nodo* nuevo = (Nodo*)malloc(sizeof(Nodo));
    nuevo->periodista = p;
    nuevo->siguiente = NULL;
    if (*fin != NULL) {
        (*fin)->siguiente = nuevo;
    }
    *fin = nuevo;
    if (*frente == NULL) {
        *frente = *fin;
    }
}

int colaVacia(Nodo* frente) {
    return frente == NULL;
}

// Función para asignar nodos de la cola a las listas según tipo de credencial
void procesarCola(Nodo** frente, Nodo** hosp, Nodo** boxes, Nodo** palcos) {
    Nodo* actual = *frente;
    while (actual != NULL) {
        Nodo* siguiente = actual->siguiente; // Guardar referencia al siguiente nodo

        // Asignar el nodo actual a la lista correspondiente
        if (actual->periodista.tipoCredencial == 1) {
            actual->siguiente = *hosp;
            *hosp = actual;
        } else if (actual->periodista.tipoCredencial == 2) {
            actual->siguiente = *boxes;
            *boxes = actual;
        } else if (actual->periodista.tipoCredencial == 3) {
            actual->siguiente = *palcos;
            *palcos = actual;
        } else {
            printf("Error: Tipo de credencial desconocido para el periodista %d\n", actual->periodista.idPeriodista);
        }

        actual = siguiente; // Mover al siguiente nodo
    }

    // Vaciar la cola
    *frente = NULL;
}

// Función recursiva para contar elementos en una lista
int contarPedidos(Nodo* lista) {
    if (lista == NULL) {
        return 0;
    }
    return 1 + contarPedidos(lista->siguiente);
}

// Función para calcular el tipo de credencial más solicitado
void calcularMasSolicitado(Nodo* hosp, Nodo* boxes, Nodo* palcos) {
    int countHosp = contarPedidos(hosp);
    int countBoxes = contarPedidos(boxes);
    int countPalcos = contarPedidos(palcos);

    int max = countHosp;
    char tipo[20] = "Hospitality";

    if (countBoxes > max) {
        max = countBoxes;
        strcpy(tipo, "Boxes");
    }
    if (countPalcos > max) {
        max = countPalcos;
        strcpy(tipo, "Palcos");
    }

    printf("El tipo de credencial más solicitado es: %s con %d solicitudes.\n", tipo, max);
}

// Función para imprimir una lista
void imprimirLista(Nodo* lista) {
    while (lista != NULL) {
        Periodista p = lista->periodista;
        printf("ID: %d, Nombre: %s %s, Pasaporte: %s, Medio: %s, Credencial: %d, Comida: %s\n",
               p.idPeriodista, p.nombre, p.apellido, p.pasaporte, p.medio,
               p.tipoCredencial, p.incluyeComida ? "Sí" : "No");
        lista = lista->siguiente;
    }
}

// Programa principal
int main() {
    Nodo *cola = NULL, *fin = NULL; // Cola principal
    Nodo *hosp = NULL, *boxes = NULL, *palcos = NULL; // Listas por tipo de credencial

    // Datos de prueba
    Periodista p1 = {1, "Juan", "Pérez", "AA123456", "Medio1", 1, 1};
    Periodista p2 = {2, "María", "López", "BB654321", "Medio2", 2, 0};
    Periodista p3 = {3, "Carlos", "Gómez", "CC789123", "Medio3", 3, 1};
    Periodista p4 = {4, "Ana", "Martínez", "DD987654", "Medio4", 1, 0};

    insertarEnCola(&cola, &fin, p1);
    insertarEnCola(&cola, &fin, p2);
    insertarEnCola(&cola, &fin, p3);
    insertarEnCola(&cola, &fin, p4);

    printf("Procesando la cola principal...\n");
    procesarCola(&cola, &hosp, &boxes, &palcos);

    printf("\nLista de credenciales Hospitality:\n");
    imprimirLista(hosp);

    printf("\nLista de credenciales Boxes:\n");
    imprimirLista(boxes);

    printf("\nLista de credenciales Palcos:\n");
    imprimirLista(palcos);

    printf("\nCalculando el tipo de credencial más solicitado...\n");
    calcularMasSolicitado(hosp, boxes, palcos);

    return 0;
}
