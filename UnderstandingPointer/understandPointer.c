#include <stdio.h>

int p(int* a){
    int t = *a;
    (*a) = 4;
    return t;
}

int main(){
    int a = 1;
    printf("value of t = %d",p(&a));
    return 0;
}