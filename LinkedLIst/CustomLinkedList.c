#include <stdio.h>
#include "LinkedList.h"

int main()
{
    List firstList = newList;

    addToList(&firstList, "RION");
    addToList(&firstList, "RION1");
    addToList(&firstList, "RION1");
    addToList(&firstList, "RION2");

    removeFromList(&firstList, 2);

    addToList(&firstList, "Pou");

    iterateList(&firstList);


List firstList2 = newList;

    addToList(&firstList2, "2RION");
    addToList(&firstList2, "2RION1");
    addToList(&firstList2, "2RION1");
    addToList(&firstList2, "2RION2");

    removeFromList(&firstList2, 2);

    deleteList(&firstList);

    addToList(&firstList2, "2Pou");

    iterateList(&firstList2);

    for( int i=0; i<50; i++)
    {
        printf("%c\n", heap[i]);
    }
    return 0;
}