

// C program to illustrate 
// size of struct 
#include <stdio.h> 
  
int main() 
{ 
  
    struct C { 

        double z; 

        char a;
        char b;
        short int y;
        int x; 
    }; 
  
    printf("Size of struct: %ld\n", sizeof(struct C)); 
  
    return 0; 
} 
