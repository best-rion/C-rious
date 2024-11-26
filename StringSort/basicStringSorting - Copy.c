#include <stdio.h>
#include <string.h>
#define N 7

void stringSort(int n, char **textArray){

}

int main(){
    char textArray[N][6] = {"shuvo","johny","rakib","jarin","nadim","jasim","arman"};
    char temp[6];
    int leftmost;
    for(int iterNo=0;iterNo<N-1;iterNo++){
        leftmost = iterNo;
        for(int current=iterNo+1;current<N;current++){
            for(int letr=0;letr<5;letr++){
                int dif = textArray[leftmost][letr] - textArray[current][letr];
                // Break; if the leftmost element's letter is already smaller
                if(dif<0){
                    break;
                }
                // check the next letter; if current's letter is same as the leftmost's letter
                else if(dif==0){
                    continue;
                }
                // assign current element as leftmost element; if current element's letter is smaller
                else{
                    leftmost = current;
                    break;
                }
            }
        }
        strcpy(temp ,textArray[iterNo]);
        strcpy(textArray[iterNo],textArray[leftmost]);
        strcpy(textArray[leftmost], temp);
    }

    for(int i=0;i<N;i++){
        printf("%s\n",textArray[i]);
    }
    return 0;
}