#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* nuevonodo = (Node*)malloc(sizeof(Node));
    nuevonodo->data = data;
    nuevonodo->next = NULL;
    return nuevonodo;
}

void InsertNode(Node** node, int data) {
    Node* nuevonodo = createNode(data);
    nuevonodo->next = (*node);
    (*node) = nuevonodo;
}

void InsertByOrder(Node* lista12, Node** listaordenada) {
    Node* nodoOrdenado = createNode(lista12->data);
    if (*listaordenada == NULL || (*listaordenada)->data >= nodoOrdenado->data) {
        nodoOrdenado->next = *listaordenada;
        *listaordenada = nodoOrdenado;
    } else {
        Node* tempOrd = *listaordenada;        
        while (tempOrd->next != NULL && tempOrd->next->data < nodoOrdenado->data) {
            tempOrd = tempOrd->next;
        }
        nodoOrdenado->next = tempOrd->next;
        tempOrd->next = nodoOrdenado;
    }
}

void printList(Node* lista) {
    Node* temp = lista;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Función para recorrer todos los nodos de lista[i] e insertarlos en listaordenada
void InsertAllByOrder(Node* lista, Node** listaordenada) {
    Node* current = lista;
    while (current != NULL) {
        InsertByOrder(current, listaordenada);
        current = current->next;
    }
}

// Función recursiva para sumar todos los valores de los nodos
int sumarecursiva(Node* lista) {
    if (lista == NULL) {
        return 0;
    }
    return lista->data + sumarecursiva(lista->next);
}

// Función recursiva para contar el número de nodos
int conteorecursivo(Node* lista) {
    if (lista == NULL) {
        return 0;
    }
    return 1 + conteorecursivo(lista->next);
}

int main() {
    Node* lista[2] = {NULL, NULL};
    Node* listaord = NULL;
    int numero;

    // Entrada de datos para las dos listas
    for (int i = 0; i < 2; i++) {
        do {
            printf("Lista %d - Ingrese un numero (0 para salir): ", i + 1);
            scanf("%d", &numero);
            if (numero != 0) {
                InsertNode(&lista[i], numero);
            }
        } while (numero != 0);
    }

    // Inserta todos los elementos de cada lista[i] en listaordenada, en orden
    for (int i = 0; i < 2; i++) {
        InsertAllByOrder(lista[i], &listaord);
    }

    // Imprime la lista ordenada
    printf("Lista ordenada:\n");
    printList(listaord);

    // Calcula la suma y el conteo recursivamente
    printf("Suma de los elementos de la lista ordenada: %d\n", sumarecursiva(listaord));
    printf("Numero de elementos en la lista ordenada: %d\n", conteorecursivo(listaord));

    return 0;
}
