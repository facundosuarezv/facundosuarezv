#include<stdio.h>

void insercion_order(int array[], int array_size);


int main(){

    int array[] = {2,9,3,10,15,43,90,5,1,54,7,98,36};
    int arrsize = sizeof(array)/sizeof(array[0]);

    insercion_order(array, arrsize);

    printf("Sorted array: \n");
    for (int i = 0; i < arrsize; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    
}

void insercion_order(int array[], int array_size){

    for (int i = 1; i < array_size; i++){
        int key = array[i];
        int j = i-1;

        while (j >= 0 && array[j]>key){
            array[j+1]=array[j];
            j = j-1;
        }
        array[j+1] = key;
    }
}