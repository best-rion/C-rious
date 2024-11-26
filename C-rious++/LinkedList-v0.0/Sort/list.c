#include <stdio.h>
#include <stdlib.h>


struct node{
    struct node *next;
    unsigned short value;
};

typedef struct node Node;

// multiple selection
void add_node(Node *head_node, unsigned short val){

    Node* current_node = (Node*) malloc(sizeof(Node));

    current_node->value = val;
    current_node->next = head_node->next;
    head_node->next = current_node;
}

void remove_node(Node *head_node, unsigned short index){

    Node* current = head_node->next;
    Node* temp = head_node;

    for(unsigned short i=0;i<index;i++){
        temp = current;
        current = current->next;
    }

    temp->next = current->next;

    printf("BEFORE\n");
    printf("current->value %d\n",current->value);
    printf("current->next %p\n",current->next);

    free(current);
    
    printf("AFTER\n");
    printf("current->value %d\n",current->value);
    printf("current->next %p\n\n",current->next);
}

void print_nodes(Node* head_node){

    Node* current = head_node;

    while(current->next != NULL){
        current = current->next;
        printf("%d\n",current->value);
    }
}


void free_nodes(Node *head_node){

    Node* current;

    while(head_node->next != NULL){
        current = head_node->next;
        head_node->next = current->next;
        free(current);
    }
}


int main(){

    Node head_node;
    head_node.next = NULL;

    add_node(&head_node,4);
    add_node(&head_node,3);
    add_node(&head_node,2);

    print_nodes(&head_node);

    remove_node(&head_node,1);

    print_nodes(&head_node);

    free_nodes(&head_node);

    return 0;
}