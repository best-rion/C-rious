#include "simpleTasks.h"


void insertionSort2(unsigned int n,unsigned int *arrayOfNumbers){
    for(int i=1;i<=n-1;i++){
        for(int j=i-1;j>=0;j--){
            if(arrayOfNumbers[j]>arrayOfNumbers[j+1]){
                swap(&arrayOfNumbers[j], &arrayOfNumbers[j+1]);
            }else{
                break;
            }
        }
    }
}

int main(){
    unsigned int n;
    getN(&n);
    unsigned int arrayOfNumbers[n];
    getArray(n,arrayOfNumbers);
    insertionSort2(n,arrayOfNumbers);
    printList(n,arrayOfNumbers);
    runTime();
    return 0;
}