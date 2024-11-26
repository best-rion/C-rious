#include <stdio.h>
#include <stdlib.h>
int NUM=0;

struct Node{
    
    int value;
    struct Node * next;
    struct Node * prev;
};

void createList(struct Node ** FirstNode, struct Node ** LastNode){
    struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = 0;   //assigning zero as first value
    newNode->prev = NULL;
    newNode->next = NULL;
    *FirstNode = newNode;
    *LastNode = newNode;
    NUM=1;
}

void listPrinter(struct Node * FirstNode){
    struct Node * localNode = FirstNode->next;
    for(int i=0; i<=NUM; i++){
        printf("%d\n",localNode->value);
        localNode = localNode->next;
    }
}

void addNode(struct Node ** LastNode, int value){
    struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));

    newNode->value = value;
    newNode->prev = *(LastNode);
    newNode->next = NULL; // this will be used to count the length
    (*LastNode)->next = newNode;
    *LastNode = newNode;
    NUM+=1;
}

void insertNode(struct Node * FirstNode, int position, int value){
    struct Node * newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value; //node created

    struct Node * positionNode = FirstNode;

    for(int i=1; i<position; i++){
        positionNode=positionNode->next;
    }
    newNode->prev = positionNode;
    newNode->next = positionNode->next;
    positionNode->next = newNode;
    (newNode->next)->prev = newNode;
    NUM+=1;
}

unsigned int length(struct Node * FirstNode){
    struct Node * localNode = FirstNode->next;
    unsigned int n = 0;
    while(localNode != NULL){
        localNode = localNode->next;
        n++;
    }
    return n;
}

void removeNode(struct Node * FirstNode, int position){
    struct Node * positionNode = FirstNode;
    struct Node * tempNodePrev;
    struct Node * tempNode;
    for(int i=1; i<position; i++){
        positionNode=positionNode->next;
    }
    tempNode = positionNode->next;
    positionNode->next=tempNode->next;
    (tempNode->next)->prev = positionNode;
        free(tempNode);
    NUM-=1;
}

// void freeMemory(struct Node * FirstNode){
//     struct Node * localNode = FirstNode;
//     struct Node * tempNode;
//     int  n=0;
//     while(1){
//         if(localNode->next == NULL){
            
//             printf("before next = %p, value = %d, sl = %d\n", localNode->next,localNode->value,n);
//             free(localNode);
//             printf("after  next = %p, value = %d, sl = %d\n", localNode->next,localNode->value,n);
//             break;
//         }else{
//             tempNode = localNode;
//             localNode = localNode->next;
            
//             printf("before next = %p, value = %d, sl = %d\n", tempNode->next,tempNode->value,n);
//             free(tempNode);
//             printf("after  next = %p, value = %d, sl = %d\n", tempNode->next,tempNode->value,n);
//             n++;
//         }
//     }
// }
void freeMemory(struct Node* head_node){
    struct Node* current_node = head_node;
    while(current_node->next != NULL){
        printf("before next = %p, value = %d\n",  head_node->next, head_node->next->value);
        struct Node* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
        printf("after  next = %p, value = %d\n",  head_node->next, head_node->next->value);
    }
}
int main(){
    int number[] = {7,8,6};

    struct Node * firstNode;
    struct Node * lastNode;

    createList(&firstNode, &lastNode);

    for(int i=0; i<sizeof(number)/sizeof(int); i++){
        addNode(&lastNode,number[i]);
    }

    insertNode(firstNode,2,33);

    removeNode(firstNode,3);

    freeMemory(firstNode);

    listPrinter(firstNode);

    return 0;
}