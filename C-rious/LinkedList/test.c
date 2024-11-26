#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
};

struct Node* createHead(int value){

    struct Node* head_node = (struct Node*) malloc(sizeof(struct Node));

    head_node->value = value;
    head_node->next = NULL;

    return head_node;
}

void pushNode(struct Node* head, int value){

    // 1. Going to the last node

    struct Node* current_node = head;
    while(current_node->next != NULL){

        current_node = current_node->next;
    }
    
    // 2. Creating the last node

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;
    new_node->next = NULL;

    // 3. Making changes to the former last node

    current_node->next = new_node;
}

unsigned int length(struct Node* head){

    struct Node* current_node = head; // "head" is enough, I created "current_node" for aesthetics

    unsigned int length = 1;

    while(current_node->next != NULL){

        current_node = current_node->next;
        length++;
    }

    return length;
}

void printList(struct Node* head){

    struct Node* current_node = head;

    printf("[%d] [%X] -> %X\n", current_node->value, current_node, current_node->next);

    while(current_node->next != NULL){

        current_node = current_node->next;
        
        printf("[%d] [%X] -> %X\n", current_node->value, current_node, current_node->next);
    }
}

void deleteList( struct Node* current_node){
    struct Node* next_node;
    if(current_node->next != NULL){
        next_node = current_node->next;
        deleteList(next_node);
        free(current_node);
        
    }else{
        free(current_node);
    }
}

/*
void deleteListThatWillNotWork( struct Node* head){
    struct Node* current_node = head;
    struct Node* next_node;
    while(current_node->next != NULL){
        struct Node* toDelete = current_node;
        next_node = current_node->next;
        free(toDelete);
        current_node = next_node;
    }
}
*/

int main(){
    struct Node* head = createHead(5);
    pushNode(head,1);
    pushNode(head,3);
    pushNode(head,4);
    pushNode(head,2);

    // Debug part 1 start
    struct Node* list[5];
    struct Node* current_node = head;
    for(int i=0; i<5; i++){
        list[i] = current_node;
        current_node = current_node->next;
    }
    // Debug part 1 end

    printList(head);

    deleteList(head);

    // Debug part 2 start
    for(int i=0; i<5; i++){
        printf("\n %d. '%X' => %d\n",i,list[i], list[i]->value);
    }
    // Debug part 2 end

    return 0;
}