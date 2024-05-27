#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} node;

int main (int argc, char *argv[]) {

    node *list = NULL;

    for (int i = 1; i < argc; i++){
        int number = atoi(argv[i]);

        node *n = malloc(sizeof(node));
        if (n== NULL){
            //Free memory
            return 1;
        }
        n->number = number;
        n->next=list;
        list = n;


    }

    node *current = list;
    
    while (current != NULL){
        printf("%d \n", current->number);
        current = current->next;
    }
        current = list;
    while (current != NULL) {
        node *next = current->next;
        free(current);
        current = next;
    }

    return 0;
}