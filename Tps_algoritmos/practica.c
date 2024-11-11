#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 // Definición de la estructura para los productos
typedef struct {
  int cod;
  char nombreproducto[50];
  int cantidad;
  float costo;
}Producto;

// Nodo de lista, pila y cola
typedef struct Node {
  Producto producto;
  struct Node * next;
}Node;

// Función para crear un nuevo nodo con un producto
Node * createNode(Producto producto) {
  Node * newNode = (Node * ) malloc(sizeof(Node));

  newNode -> producto = producto;
  newNode -> next = NULL;
  return newNode;
}

// Función para apilar un nodo (push)
void push(Node ** top, Producto producto) {
  Node * newNode = createNode(producto);
  newNode -> next = * top;
  * top = newNode;
}

// Función para desapilar un nodo (pop)
Producto pop(Node ** top) {
  if ( * top == NULL) {
    printf("La pila está vacía.\n");
    exit(1);
  }
  Node * temp = * top;
  Producto producto = temp -> producto;
  * top = ( * top) -> next;
  free(temp);
  return producto;
}

// Función para encolar un nodo (enqueue)
void enqueue(Node ** front,  Node ** rear, Producto producto) {
  Node * newNode = createNode(producto);
  if ( * rear == NULL) {
    * front = * rear = newNode;
  } else {
    ( * rear) -> next = newNode;
    * rear = newNode;
  }
}

// Función para desencolar un nodo (dequeue)
Producto dequeue(Node ** front, Node ** rear) {
  if ( * front == NULL) {
    printf("La cola está vacía.\n");
    exit(1);
  }
  Node * temp = * front;
  Producto producto = temp -> producto;
  * front = ( * front) -> next;
  if ( * front == NULL) {
    * rear = NULL;
  }
  free(temp);
  return producto;
}

// Función para agregar un producto a una lista enlazada
void insertEnd(Node ** head, Producto producto) {
  Node * newNode = createNode(producto);
  if ( * head == NULL) {
    * head = newNode;
  } else {
    Node * temp = * head;
    while (temp -> next != NULL) {
      temp = temp -> next;
    }
    temp->next = newNode;
  }
}

// Función para imprimir una lista enlazada de productos
void printList(Node * head) {
  while (head != NULL) {
    printf("Cod: %d, Producto: %s, Cantidad: %d, Costo: %.2f\n",
      head -> producto.cod, head -> producto.nombreproducto,
      head -> producto.cantidad, head -> producto.costo);
    head = head -> next;
  }
}

int main() {
  // Datos de los productos
  Producto productos[3] = {
    {
      1,
      "Producto1",
      10,
      100.50
    },
    {
      2,
      "Producto2",
      5,
      200.75
    },
    {
      3,
      "Producto3",
      20,
      150.00
    }
  };
  // Manejo de la pila
  Node * stack = NULL;
  for (int i = 0; i < 3; i++) {
    push( & stack, productos[i]);
  }

  // Desapilar y crear una lista enlazada desde la pila
  Node * listaDesdePila = NULL;
  while (stack != NULL) {
    Producto producto = pop( & stack);
    insertEnd( & listaDesdePila, producto);
  }
  printf("Lista desde la pila:\n");
  printList(listaDesdePila);
  // Manejo de la cola
  Node * queueFront = NULL;
  Node * queueRear = NULL;
  for (int i = 0; i < 3; i++) {
    enqueue( & queueFront, & queueRear, productos[i]);
  }

  // Desencolar y crear una lista enlazada desde la cola
  Node * listaDesdeCola = NULL;
  while (queueFront != NULL) {
    Producto producto = dequeue( & queueFront, & queueRear);
    insertEnd( & listaDesdeCola, producto);
  }
  printf("\nLista desde la cola:\n");
  printList(listaDesdeCola);
  return 0;
}
