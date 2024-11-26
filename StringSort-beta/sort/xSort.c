#include "sortingAlgorithms.h"

#include <math.h>

int main(){
    unsigned int n;
    getN(&n);
    unsigned int arrayOfNumbers[n];
    getArray(n,arrayOfNumbers);
    xSort(n,arrayOfNumbers);
    printList(n,arrayOfNumbers);
    runTime();
    return 0;
}