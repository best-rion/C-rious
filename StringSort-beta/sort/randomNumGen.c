#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    unsigned int n;
    printf("How many numbers : ");
    scanf("%d",&n);
    FILE *arrayP;
    arrayP = fopen("numbers.txt","w");
    fprintf(arrayP,"%d ",n);
    for(int i=0;i<n;i++){
        fprintf(arrayP,"%d ",rand()%2000+1);
    }
    fclose(arrayP);
    return 0;
}