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

int main(){

    void* f1_ptr = &cat;

    call(f1_ptr);
}