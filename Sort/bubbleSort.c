#include "simpleTasks.h"

void bubbleSort(unsigned int n,unsigned int *arrayOfNumbers){
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-2-i;j++){
            if(arrayOfNumbers[j]>arrayOfNumbers[j+1]){
                swap(&arrayOfNumbers[j], &arrayOfNumbers[j+1]);
            }
        }
    }
}

int main(){
    unsigned int n;
    getN(&n);
    unsigned int arrayOfNumbers[n];
    getArray(n,arrayOfNumbers);

    bubbleSort(n,arrayOfNumbers);

    printList(n,arrayOfNumbers);
    runTime();
    return 0;
}