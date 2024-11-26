#include "simpleTasks.h"
#include <math.h>

void insertionSort(unsigned int n,unsigned int *arrayOfNumbers){
    unsigned int found,temp,thePosition;
    for(int i=1;i<=n-1;i++){
        found=0;
        for(int j=0;j<=i-1;j++){
            if((!found) && (arrayOfNumbers[j]>arrayOfNumbers[i])){
                found=1;
                temp=arrayOfNumbers[i];
                thePosition=j;
            }
            if(found){
                int backCount = (i-1)-(j-thePosition);
                arrayOfNumbers[backCount+1]=arrayOfNumbers[backCount];
            }
        }
        if(found){
            arrayOfNumbers[thePosition]=temp;
        }
    }
}


void selectionSort(unsigned int n,unsigned int *arrayOfNumbers){
    unsigned int smallest;
    for(int i=0;i<=n-2;i++){
        smallest = i;
        for(int j=i+1;j<=n-1;j++){
            if(arrayOfNumbers[j]<arrayOfNumbers[smallest]){
                smallest = j;
            }
        }
        swap(&arrayOfNumbers[smallest], &
        arrayOfNumbers[i]);
    }
}


double log_base2(unsigned int n){
    double result = log(n)/log(2);
    return result;
}

void xSort(unsigned int n,unsigned int *arrayOfNumbers){
    unsigned int temp, nums_to_deal=n ,times_to_deal = 1;;
    int iterations = floor(log_base2(n));
    for(int i=0;i<iterations;i++){
        nums_to_deal = (nums_to_deal-(nums_to_deal%2))/2;
        for(int thisTime=0;thisTime<times_to_deal;thisTime++){
            unsigned int space = 2* nums_to_deal;
            for(int j = (space * thisTime); j < (space * thisTime) + nums_to_deal; j++){
                if(arrayOfNumbers[j]>arrayOfNumbers[j+nums_to_deal]){
                    swap(&arrayOfNumbers[j],&arrayOfNumbers[j+nums_to_deal]);
                }
            }
        }
        times_to_deal*=2;
    }
    selectionSort(n,arrayOfNumbers);
}