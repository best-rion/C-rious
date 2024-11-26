#include <stdio.h>

void dog(){
    printf("DOG");
}
void cat(){
    printf("CAT");
}
void bird(){
    printf("BIRD");
}

void call(void* function()){
   function();
}

typedef void funcky();


int main(){
    funcky *rat = bird;

    void* f1_ptr = rat;

    call(f1_ptr);
}