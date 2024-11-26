#include <stdio.h>

int Hash(char* text){
    int range = 15;
    int i=0;
    long int num=0;
    char c;
    while( (c = *(text+i)) != '\0'){
        num += (int) c;
        i++;
    }
    return (int) num % range;
}


struct Student{
    char name[20];
    unsigned int age;
};


int main(){
    struct Student class10[10] = {"Ali",56,"Javed",12, "Kalam",54, "Sindid",52, "Samir",74, "Gazi",23, "Mobassir",87, "Mudassir",56, "Harris",14, "salman",36};
    struct Student Class10easy[15];
    // for(int i=0;i<10; i++){
    //     printf("%s %d\n",class10[i], Hash(class10[i].name,15));
    // }

    int taly[10];
    for(int i=0;i<10; i++){
        taly[i] = 0;
    }
    int k=0,b,now;
    for(int i=0; i<10; i++){
        now = Hash(class10[i].name);
        b=1;
        for(int j=0;j<k;j++){
            if((now + 1) == taly[j]){
                b=0;
            }
        }
        if(b){
            Class10easy[now] = class10[i];
            taly[k] = now + 1;
            k++;
        }
    }
    
    int n;
    for(int i=0; i<15; i++){
        n=0;
        for(int j=0;j<10;j++){
            if(taly[j] == i+1 ){
                n=1;
            }
        }
        if(n){
            printf("%d. %s\n", i, Class10easy[i].name);
        }else{
            printf("%d. -----\n",i);
        }
    }





char givename[20];

    while(1){
        scanf("%s",givename);
        printf("Age = %d\n\n",Class10easy[Hash(givename)].age);

    }
    return 0;
}
