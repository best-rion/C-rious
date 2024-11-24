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


struct ListStruct
{
    Node head_node;
    int length;
};
typedef struct ListStruct List;
List newList = {{0,NULL},0};



void addToList(List* list, char string[])
{
    Node* current_node_ptr = &list->head_node;

    while (current_node_ptr->next != NULL)
    {
        current_node_ptr = current_node_ptr->next;
    }

    Node* new_node_ptr = malloc(sizeof(Node));

    new_node_ptr->value = allocate(string);
    new_node_ptr->next = NULL;

    current_node_ptr->next = new_node_ptr;
}



void iterateList(List* list)
{
    Node* current_node_ptr = &list->head_node;

    while (current_node_ptr->next != NULL)
    {
        current_node_ptr = current_node_ptr->next;
        printf("%s\n", current_node_ptr->value);
    }
}



Node* getNodePtr(List* list, int index)
{
    Node* current_node_ptr = &list->head_node;
    
    for (int i=0; i<=index; i++)
    {
        current_node_ptr = current_node_ptr->next;
    }
        
    return current_node_ptr;
}



char* getValue(List* list, int index)
{
    return getNodePtr(list, index)->value;
}



void removeFromList(List* list, int index)
{
    Node* this_node_ptr;

    if( index != 0 )
    {
        Node* prev_node_ptr = getNodePtr(list, index-1);
        this_node_ptr = prev_node_ptr->next;

        prev_node_ptr->next = this_node_ptr->next;
    }
    else
    {
        this_node_ptr = list->head_node.next;

        list->head_node.next = NULL;
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

void deleteList(List* list)
{
    recursiveDelete(list->head_node.next);
}
