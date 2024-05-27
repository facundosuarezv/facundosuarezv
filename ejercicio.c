#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int x;
    struct node *next;
}node;

int main(){
    node root;
    root.x = 15;
    root.next = malloc(sizeof(node));
    root.next->x = -2;
    root.next->next = NULL;

    node *curr = &root;

    while (curr != NULL){
        printf("%d\n",curr->x);
        curr = curr->next;
    }

    free(root.next);
    return 0;
} 