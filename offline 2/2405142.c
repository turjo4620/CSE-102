#include<stdio.h>
#include<string.h>
#include "utils.c"
#include<math.h>
#include<stdlib.h>
#define MAX_SIZE 1000000
#define MAX_BINS 1000
#define MAX_STARS 50
int bin_counts[MAX_BINS];
int size, seed, initialized = 0;
double array[MAX_SIZE];
char command[20];
char distribution[20];
void commandlist(){
    printf("Commands:\n");
    printf("  set     - Set array size, seed, and distribution (uniform or gaussian)\n");
    printf("  min     - Print minimum value\n");
    printf("  max     - Print maximum value\n");
    printf("  mean    - Print mean value\n");
    printf("  stddev  - Print standard deviation\n");
    printf("  hist    - Plot histogram\n");
    printf("  summary - Print min, max, mean, stddev\n");
    printf("  help    - Show this help message\n");
    printf("  exit    - Exit the program\n\n");
}
double min(){
    double min;
    if(initialized == 0){
        printf("Array not initialized. Use 'set' command first.\n");
        return 0.0;
    }
    min = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] < min){
            min = array[i];
        }
    }
    printf("Min       :   %.4lf\n", min);
    return min;
}
double max(){
    double max;
    if(initialized == 0){
        printf("Array not initialized. Use 'set' command first.\n");
        return 0.0;
    }
    max = array[0];
    for(int i = 0; i < size; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    printf("Max       :    %.4lf\n", max);
    return max;
}
double mean(){
     if(initialized == 0){
        printf("Array not initialized. Use 'set' command first.\n");
        return 0.0;
    }
    else {
        double sum = 0;
        double mean = 0;
        for(int i = 0; i < size; i++){
            sum = sum + array[i];
        }
        mean = sum / size;
        printf("Mean      :    %.4lf\n", mean);
        return mean;
    }
}
double stddev(){
    double stddev = 0.0;
    double squareddiff = 0.0;
    double variance = 0.0;
    double sum = 0;
    double mean = 0;
    for(int i = 0; i < size; i++){
            sum = sum + array[i];
        }
    mean = sum / size;
    for(int i = 0; i < size; i++){
        variance = variance + pow((array[i] - mean) , 2);
    }
    variance = variance / size;
    stddev = sqrt(variance);
    printf("Std Dev   :     %.4lf\n\n", stddev);
    return stddev;
}

int main(){
    commandlist();
    command[0] = '\0';
    while(strcmp(command, "exit") != 0){
    printf("Enter command: ");
    scanf("%s", command);
    if (strcmp(command, "help") == 0){
        commandlist();
    }
    else if(strcmp(command, "set") == 0){
        printf("Enter number of elements (<= 100000): ");
        scanf("%d", &size);
        if (size <= 0 || size > 100000){
            printf("Invalid size.\n");
            continue;
        }
        printf("Enter seed: ");
        scanf("%d", &seed);
        printf("Distribution? (uniform/gaussian): ");
        scanf("%s", distribution);
        if(strcmp(distribution, "uniform") == 0){
            double max, min;
            printf("Enter min and max: ");
            scanf("%lf %lf", &min, &max);
            populate_array_uniform(array, size, min, max, seed);
            initialized = 1;
            printf("Array initialized with uniform distribution.\n\n");
        }
        else if(strcmp(distribution, "gaussian") == 0){
            double mean, stddev;
            printf("Enter mean and stddev: ");
            scanf("%lf %lf", &mean, &stddev);
            if (stddev < 0){
                printf("Invalid standard deviation.\n");
                continue;
            }
            populate_array_gaussian(array, size, mean, stddev, seed);
            initialized = 1;
            printf("Array initialized with gaussian distribution.\n\n");
        }
        else {
            printf("Invalid distribution.\n");
            continue;
        }
    }
    else if (!initialized &&
        (strcmp(command, "min") == 0 ||
         strcmp(command, "max") == 0 ||
         strcmp(command, "mean") == 0 ||
         strcmp(command, "stddev") == 0 ||
         strcmp(command, "hist") == 0 ||
         strcmp(command, "summary") == 0)) {
    printf("Array not initialized. Use 'set' command first.\n");
    }
    else if (strcmp(command, "exit") == 0){
        break;
    }
    else if(strcmp(command, "min") == 0){
        min();
    }
        else if(strcmp(command, "max") == 0){
        max();
    }
            else if(strcmp(command, "mean") == 0){
        mean();
    }
    else if(strcmp(command, "stddev") == 0){
        stddev();
    }
    else if (strcmp(command, "summary") == 0){
        min();
        max();
        mean();
        stddev();
    }
    else if (strcmp(command, "hist") == 0){
        int bins;
        printf("Enter number of bins: ");
        scanf("%d", &bins);
    if (bins < 1 || bins > MAX_BINS) {
        printf("Invalid number of bins. Must be between 1 and 1000.\n");
        continue;
    }   double minv = min();
        double binw = (max() - minv) / bins;
        int bincounts[MAX_BINS] = {0};
        for (int i = 0; i < size; i++) {
        int bin_index = (int)((array[i] - minv) / binw);
        if (bin_index == bins) { 
        bin_index--;
    }
    bin_counts[bin_index]++;   
}
    int max_count = 0;
    for (int i = 0; i < bins; i++) {
    if (bin_counts[i] > max_count) {
        max_count = bin_counts[i];
    }
}
    double scale_factor = (max_count > MAX_STARS) ? (double)MAX_STARS / max_count : 1.0;
    for (int i = 0; i < bins; i++) {
    double bin_start =  + i * binw;
    double bin_end = bin_start + binw;


    printf("[%6.2f - %6.2f] : ", bin_start, bin_end);
    int star_count = (int)(bin_counts[i] * scale_factor);
    if (star_count == 0 && bin_counts[i] > 0) star_count = 1;
    for (int j = 0; j < star_count; j++) {
        printf("*");
    }
    printf("\n");
}
    }

    else{
        printf("Unknown command. Type 'help' for list of commands.\n");
    }

    }
    return 0;
}