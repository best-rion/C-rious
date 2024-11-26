#include <stdio.h>

#define d  2
#define d2 8
#define d1 8

void recurring_for(void *mat,int *s,int l,int *sum){
    l--;
    for(int i=0; i<*s; i++){
        if(l>0){
            if(i==0){
                //printf("\n");
            }
            recurring_for(mat,s+1,l,sum);
        }else{
            if(i==0){
                *sum += *s;
            }
            printf("%d, ",*((int*)mat + *sum + i));
            
        }
    }
    printf("\n");
}


void printMat(void *mat,int *s,int l,int *sum){
    recurring_for(mat,s,l,sum);
    *sum = -*(s+l-1);
}
// Let's not stick to 2D array

int main(){
    int mat1_sum = -d1;
    int s[d] = {d2,d1};
    int mat[d2][d1] = {
                        {1,2,3,4,1,2,3,4},
                        {4,5,6,7,1,2,3,4},
                        {1,-2,-3,4,4,5,-6,7},
                        {1,2,3,-4,1,2,3,4},
                        {4,-5,2,3,4,6,7,1},
                        {1,4,3,-4,2,-3,6,7},
                        {1,4,4,5,-2,-3,6,7},
                        {-4,5,6,7,7,4,5,6}
                    };

    printMat(mat,s,d,&mat1_sum);
    printf("%d",mat1_sum);
    return 0;
}