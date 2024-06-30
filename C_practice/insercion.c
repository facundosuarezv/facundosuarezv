#include<stdio.h>

void insercion_order(int array[], int array_size);
void print_array(int array[], int array_size);

int main(){

    int array[] = {2,1,9,20,3,10,15};
    int arrsize = sizeof(array)/sizeof(array[0]);

    insercion_order(array, arrsize);

    printf("Sorted array: \n");
    print_array(array, arrsize);
    
}

void insercion_order(int array[], int array_size){

    for (int i = 1; i < array_size; i++){
        int key = array[i];
        int j = i-1;
        printf("key: %d \n", key);
        while (j >= 0 && array[j]>key){
            array[j+1]=array[j];
            j = j-1;
            print_array(array, array_size);
        }
        array[j+1] = key;
    }
}

void print_array(int array[], int array_size){
    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}