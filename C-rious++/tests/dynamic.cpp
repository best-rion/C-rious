#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next = NULL;
};
/*
Node* createHead(int value){

    Node* head_node = new Node;

    head_node->value = value;
    head_node->next = NULL;

    return head_node;
}

void pushNode(Node* head, int value){

    // 1. Going to the last node

    Node* current_node = head;
    while(current_node->next != NULL){

        current_node = current_node->next;
    }
    
    // 2. Creating the last node

    Node* new_node = new Node;

    new_node->value = value;
    new_node->next = NULL;

    // 3. Making changes to the former last node

    current_node->next = new_node;
}
*/
void deleteList(Node* current_node){
    Node* next_node;
    if(current_node->next != NULL){
        next_node = current_node->next;
        deleteList(next_node);
        delete current_node;
        
    }else{
        delete current_node;
    }
}
int main(){

    Node* head = new Node;
    head->value = 50;

    Node* current_node = head;
    Node* new_node;
    for(int i=0; i<4; i++){
        new_node = new Node;
        new_node->value = i+10;
        current_node->next = new_node;
        current_node = new_node;
    }

    // Address Saving;

    Node* addresses[5];
    int i0 = 0;
    Node* cn0 = head;
    while(cn0!=NULL){
        addresses[i0] = cn0;
        cn0 = cn0->next;
        i0++;
    }

    // Printing;

    int i1 = 0;
    Node* cn1 = head;
    while(cn1!=NULL){
        cout << cn1->value << " -> " << cn1 << " = " << addresses[i1] << " -> " << addresses[i1]->value << endl;
        cn1 = cn1->next;
        i1++;
    }

    // Deleting;

    /*
    Node* current = head;
    Node* next;
   while (current != NULL)
   {
       next = current->next;
       delete current;
       current = next;
   }*/

    /*Node* cn2 = head;
    Node* temp;
    while(cn2!=NULL){
        temp = cn2;
        cn2 = cn2->next;
        delete temp;
    }*/

    deleteList(head);

    i0-=1;
    while(i0>=0){
        cout << addresses[4-i0] << " -> " << addresses[4-i0]->value << " -> " << addresses[4-i0]->next << endl;
        i0--;
    }

    return 0;
}