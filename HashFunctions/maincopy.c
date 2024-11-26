#include <stdio.h>
#include <string.h>

#define MaxSize 10
#define NameSize 20

int Hash(char* text){
    int i=0;
    long int num=0;
    char c;
    while( (c = *(text+i)) != '\0'){
        num += (int) c;
        i++;
    }
    return num % MaxSize;
}

struct Student{
    char name[20];
    unsigned int age;
    struct Student * ptr_to_next;
};

struct Student * class1[MaxSize];

void init_hash_func(){
    for(int i = 0; i < MaxSize; i++){
        class1[i] = NULL;
    }
}

void insert(struct Student* myStudent){
    int index = Hash(myStudent->name);
    printf("%s >>> %d\n",myStudent->name,index);
    if(class1[index]==NULL){
        class1[index] = myStudent;
    }
}

void print_table(){
    for(int i=0;i<MaxSize;i++){
        if(class1[i] != NULL){
            printf("%d. %s => %d\n", i,  class1[i]->name, class1[i]->age);
        }else{
            printf("%d. --------\n", i);
        }
    }
}


int main()
{
    init_hash_func();
    struct Student
    jubaidul = {"Jubaidul",30},
    abdullah = {"Abdullah",40},
    rakib = {"Rakib",31},
    sakib = {"Sakib",15},
    jarif = {"Jarif",26},
    sabir = {"Sabir",23},
    kabir = {"Kabir",14},
    salman = {"Salman",57},
    sabbu = {"Sabbu",18};

    insert(&jubaidul);
    insert(&abdullah);
    insert(&rakib);
    insert(&sakib);
    insert(&jarif);
    insert(&sabir);
    insert(&kabir);
    insert(&salman);
    insert(&sabbu);

    print_table();

    return 0;
}
