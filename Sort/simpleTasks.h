#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getN(unsigned int *np){
    FILE *arrayP;
    arrayP = fopen("numbers.txt","r");
    fscanf(arrayP,"%d ",np);
    fclose(arrayP);
    return 0;
}
int getArray(unsigned int n,unsigned int *arrayOfNumbers){

    unsigned int wasted;
    FILE *arrayP;
    arrayP = fopen("numbers.txt","r");
    fscanf(arrayP,"%d ",&wasted);
    for(int i=0;i<n;i++){
        fscanf(arrayP,"%d ", &arrayOfNumbers[i]);
    }
    fclose(arrayP);
    return 0;
}

void printList(unsigned int n, unsigned int *arrayOfNumbers){
    for(int i=0;i<n;i++){
        printf("%d, ",arrayOfNumbers[i]);
    }
}

void runTime(){
    clock_t endTime;
    endTime = clock();
    printf("\nTime Passed = %lf milliseconds.", ((double) endTime)*1000/CLOCKS_PER_SEC);
}

void swap(unsigned int *a, unsigned int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}