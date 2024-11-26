#include <stdio.h>

struct numbers{
        int a;
        float f;
};

int main(){

    struct numbers num1;

    num1.a = 5;
    printf("%d\n",num1.a);

    return 0;
}