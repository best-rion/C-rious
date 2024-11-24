#include <stdio.h>
#include "Allocator.h"

int main()
{
    printf("Bismillah\n");

    char* myname = allocate("Rion");
    char* hername = allocate("Miss Siddique");
    char* myfriend = allocate("Saleh Ahmed");
    char* herfavourite = allocate("POU");
    char* myfriend2 = allocate("Mom");
    char* hisfriend = allocate("Miss Khan");
    char* myfriend3 = allocate("Zubair");

    deallocate(hername);

    deallocate(herfavourite);

    deallocate(hisfriend);

    char* hernameagain = allocate("Super-Sanjida");

    printf("My name is %s\n", myname);
    printf("Her name is %s\n", hername);
    printf("My Friend is %s\n", myfriend);
    printf("Her Favourite is %s\n", herfavourite);
    printf("My Friend2 is %s\n", myfriend2);
    printf("His Friend is %s\n", hisfriend);
    printf("My Friend3 is %s\n", myfriend3);
    printf("Her name again is %s\n", hernameagain);

    for (int i=0; i<=freeCount; i++)
    {
        printf("%d th FreeRelativePosition = %u\n",i,freePositions[i].relativeAddress );
        printf("%d th FreeSize             = %u\n",i,freePositions[i].size);
    }

    return 0;
}