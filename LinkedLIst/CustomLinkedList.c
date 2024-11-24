#include <stdio.h>
#include "LinkedList.h"

int main()
{
    addToList("RION");
    addToList("RION1");
    addToList("RION1");
    addToList("RION2");

    removeFromList(2);

    addToList("Pou");

    iterateList();

    deleteList();


    for( int i=0; i<25; i++)
    {
        printf("%c\n", heap[i]);
    }
    return 0;
}