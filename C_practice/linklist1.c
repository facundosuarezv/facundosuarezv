#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nombre[30];
    int nota;
    struct node *next;
}node;



int main(){
    node *list = malloc(sizeof(node));
    list->next=NULL;    
}


node* insertar_alumnos(node **root){
    node new_node = malloc(sizeof(node));
    new_node->next =NULL;

}