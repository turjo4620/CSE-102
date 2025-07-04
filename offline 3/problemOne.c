#include <stdio.h>
#include<stdlib.h>

void removeNegatives(int* input, int n, int** output, int* newSize){
    *newSize = 0;
    for(int i = 0; i < n; i++){
    if(*(input + i) >= 0){
        (*newSize)++;
    } 
    }
    int k = 0;
    *output = (int*) malloc( n * sizeof(int));
    for(int i = 0; i < n; i++){
        if(*(input + i) >= 0){
        *(*output + k) = *(input + i);
        k++;
        }
    }
    for(int i = 0; i < *newSize; i++){
       printf("%d ", *(*output + i));
    }

 }
int main(){
    int n;
    int* input;
    int *output; 
    int newSize;
    scanf("%d", &n);
    input = (int*) malloc( n * sizeof(int));
    if (input == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }
    for(int i = 0; i < n; i++){
        scanf("%d", input + i);
    }
    removeNegatives(input, n, &output, &newSize);
    free(input);
    free(output);
    return 0;
}