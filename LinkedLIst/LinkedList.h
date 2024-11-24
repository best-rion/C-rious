#ifndef _STDLIB_H
    #include <stdlib.h>
#endif

#include "../MemoryAllocator/Allocator.h"

struct NodeStruct
{
    char* value;
    struct NodeStruct* next;
};
typedef struct NodeStruct Node;

Node head_node = {0, NULL};



void addToList(char string[])
{
    Node* current_node_ptr = &head_node;

    while (current_node_ptr->next != NULL)
    {
        current_node_ptr = current_node_ptr->next;
    }

    Node* new_node_ptr = malloc(sizeof(Node));;

    new_node_ptr->value = allocate(string);
    new_node_ptr->next = NULL;

    current_node_ptr->next = new_node_ptr;
}



void iterateList()
{
    Node* current_node_ptr = &head_node;

    while (current_node_ptr->next != NULL)
    {
        current_node_ptr = current_node_ptr->next;
        printf("%s\n", current_node_ptr->value);
    }
}



Node* getNodePtr(int index)
{
    Node* current_node_ptr = &head_node;
    
    for (int i=0; i<=index; i++)
    {
        current_node_ptr = current_node_ptr->next;
    }
        
    return current_node_ptr;
}



char* getValue(int index)
{
    return getNodePtr(index)->value;
}



void removeFromList(int index)
{
    Node* this_node_ptr;

    if( index != 0 )
    {
        Node* prev_node_ptr = getNodePtr(index-1);
        this_node_ptr = prev_node_ptr->next;

        prev_node_ptr->next = this_node_ptr->next;
    }
    else
    {
        this_node_ptr = head_node.next;

        head_node.next = NULL;
    }

    deallocate( this_node_ptr->value );

    free(this_node_ptr);
}



void recursiveDelete(Node* node)
{
    if(node->next != NULL)
    {
        recursiveDelete( node->next );
    }

    deallocate( node->value );

    free(node);
}

void deleteList()
{
    recursiveDelete(head_node.next);
}
