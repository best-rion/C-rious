#include <stdio.h>
#include <string.h>
#define N 16


void swap(unsigned int *a, unsigned int *b){
    unsigned int temp = *a;
    *a = *b;
    *b = temp;
}

int min(int a,int b){
    if(b<a){
        return b;
    }else{
        return a;
    }
}

int main(){
    char textArray[N][20] = {
                    "calista", "shuler",
                    "dariana", "woody",
                    "ronald", "daly",
                    "nayely", "cheatham",
                    "reese", "fowler",
                    "gavin", "buckley",
                    "shekinah", "keenan",
                    "1ryce", "beebe"
                            };

    // Making record of the length of each name
    unsigned int strLen[N];
    for( int i=0;i<N;i++){
        strLen[i] = strlen(textArray[i]);
    }

    // Sorting starts
    char temp[20];
    int leftmost;
    for(int iterNo=0;iterNo<N-1;iterNo++){
        leftmost = iterNo;
        for(int current=iterNo+1;current<N;current++){
            int ltr2comp = min(strLen[leftmost],strLen[leftmost]);
            for(int letr=0;letr<ltr2comp;letr++){
                int dif = textArray[leftmost][letr] - textArray[current][letr];
                // Break; if the leftmost element's letter is already smaller
                if(dif<0){
                    break;
                }
                // Check the next letter; if current's letter is same as the leftmost's letter
                else if(dif==0){
                    continue;
                }
                // Assign current element as leftmost element; if current element's letter is smaller
                else{
                    leftmost = current;
                    break;
                }
            }
        }
        // Swapping the words and their corresponding lengths
        
        strcpy(temp ,textArray[iterNo]);
        strcpy(textArray[iterNo],textArray[leftmost]);
        strcpy(textArray[leftmost], temp);
        swap(&strLen[iterNo],&strLen[leftmost]);
    }
    //Sorting ends



    for(int i=0;i<N;i++){
        printf("%s\n",textArray[i]);
        printf("%d\n",strLen[i]);
    }
    
    return 0;
}