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

// Funciones para manejo de la cola
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

Periodista extraerDeCola(Nodo** frente) {
    if (*frente == NULL) {
        printf("Error: Cola vacía.\n");
        return 0;
    }
    Nodo* temp = *frente;
    Periodista p = temp->periodista;
    *frente = (*frente)->siguiente;
    free(temp);
    return p;
}

int colaVacia(Nodo* frente) {
    return frente == NULL;
}

// Función recursiva para contar elementos en una lista
int contarPedidos(Nodo* frente) {
    if (frente == NULL) {
        return 0;
    }
    return 1 + contarPedidos(frente->siguiente);
}

// Función para procesar la cola y separar por tipo de credencial
void procesarCola(Nodo** frente, Nodo** hosp, Nodo** boxes, Nodo** palcos, Nodo** finHosp, Nodo** finBoxes, Nodo** finPalcos) {
    while (!colaVacia(*frente)) {
        Periodista p = extraerDeCola(frente);
        switch (p.tipoCredencial) {
            case 1:
                insertarEnCola(hosp, finHosp, p);
                break;
            case 2:
                insertarEnCola(boxes, finBoxes, p);
                break;
            case 3:
                insertarEnCola(palcos, finPalcos, p);
                break;
            default:
                printf("Error: Tipo de credencial desconocido para el periodista %d\n", p.idPeriodista);
        }
    }
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
void imprimirLista(Nodo* frente) {
    while (frente != NULL) {
        Periodista p = frente->periodista;
        printf("ID: %d, Nombre: %s %s, Pasaporte: %s, Medio: %s, Credencial: %d, Comida: %s\n",
               p.idPeriodista, p.nombre, p.apellido, p.pasaporte, p.medio,
               p.tipoCredencial, p.incluyeComida ? "Sí" : "No");
        frente = frente->siguiente;
    }
}

// Programa principal
int main() {
    Nodo *cola = NULL, *fin = NULL; // Cola principal
    Nodo *hosp = NULL, *boxes = NULL, *palcos = NULL; // Colas por tipo de credencial
    Nodo *finHosp = NULL, *finBoxes = NULL, *finPalcos = NULL;

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
    procesarCola(&cola, &hosp, &boxes, &palcos, &finHosp, &finBoxes, &finPalcos);

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
