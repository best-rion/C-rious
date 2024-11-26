#include <stdio.h>
#include <string.h>

int main(){
    char textArray[7][6] = {"shuvo","johny","rakib","jarin","nadim","jasim","arman"};
    char temp[6];
    int leftmost;
    for(int iterNo=0;iterNo<7-1;iterNo++){
        leftmost = iterNo;
        for(int current=iterNo+1;current<7;current++){
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

    for(int i=0;i<7;i++){
        printf("%s\n",textArray[i]);
    }
    return 0;
}