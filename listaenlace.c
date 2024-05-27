#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node *next;
} node;

void insert_end(node **root, int value){
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL){
        exit(1);
    }
    new_node->next = NULL;
    new_node->x= value;

    node *curr = *root;
    while(curr->next != NULL){
        curr = curr->next; 
    }
    curr->next = new_node;

}

int main () {

    node *root= malloc(sizeof(node));
    if (root ==NULL){
        exit(2);
    }
    root->x = 15;
    root->next = NULL;

    for (node *curr = root;curr!= NULL; curr= curr->next){
        printf("%d\n", curr->x);

    }
}