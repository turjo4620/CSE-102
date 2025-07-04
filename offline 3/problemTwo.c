#include <stdio.h>
#include<stdlib.h>

char** inputTaking(int n){
    char **w;
    w = malloc(n * sizeof(char *));
    if(w == NULL){
        printf("Memory allocation failed.\n");
    }
    for(int i = 0; i < n; i++){
        *(w + i) = malloc(26 * sizeof(char));
        if(*(w+i) == NULL){
            printf("Memory allocation failed.\n");
        }
        scanf("%s", *(w + i));
    }
    return w;
}
void compareWordSwap(char **a, char **b){
        char* w1 = *a;
        char* w2 = *b;
        while(*w1 == *w2 && *w1 != '.'){
                w1++;
                w2++;
            }
            if(*w1 > *w2){
                char *temp = *a;
                *a = *b;
                *b = temp;
                }      
}
void bubbleSorting(char** w, int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - 1 - i; j++){
            char *a = *(w + j);
            char *b = *(w + j + 1); 
            compareWordSwap((w + j), (w + j + 1)); 
        }
    }
}
void printingFinalResult(char** w, int n){
        for(int i = 0; i < n; i++){
        printf("%s\n", *(w + i));
    }
}
void freethememory(char  **w, int n){
        for(int i = 0; i < n; i++){
        free(*(w + i));
    }
}
int main(){
    int n;
    scanf("%d", &n);
    char** w = inputTaking(n);
    bubbleSorting(w, n);
    printingFinalResult(w, n);
    freethememory(w,n);
    free(w);
    return 0;
}