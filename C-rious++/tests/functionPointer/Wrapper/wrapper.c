#include <stdio.h>

void hi(int n){
    printf("Hi\n");
}



void love(int n){
    printf("I love you %d \n", n);
}

typedef void (*fPTR)(int);

// fPTR* x = void (**x)(int);

fPTR a ;
void swapper(fPTR from){
    a= from;
}
void b(int k){}
void confess(){
    a=b;
    //swapper(love);
    int l = 100;
    printf("Hey, I just want to say that ");

    a(l);
}
int main(){
    confess();
    return 0;
}