#include <stdio.h>
#include <string.h>
#define CAPACITY 1024

char first = 1;

char heap[CAPACITY];

typedef struct
{
    unsigned int relativeAddress;
    unsigned int size;

} FreePosition;

FreePosition freePositions[8];

int freeCount = 0;

char* allocate(char string[])
{
    if (first)
    {
        first = 0;

        freePositions[0].relativeAddress = 0;
        freePositions[0].size = sizeof(heap);
    }

    unsigned int size = strlen(string) + 1;

    int freeIndex = freeCount;

    for (int i=freeCount; i>=0; i--)
    {
        if(freePositions[i].size >= size)
        {
            freeIndex = i;
            break;
        }
    }

    char* address = heap + freePositions[freeIndex].relativeAddress;

    strcpy(address, string);
    if ( *( heap + freePositions[freeIndex].relativeAddress + size ) == 0)
    {
        freePositions[freeIndex].relativeAddress += size;
        freePositions[freeIndex].size -= size;
    }
    else
    {
        for (int i=freeIndex; i<=freeCount; i++)
        {
            freePositions[i]=freePositions[i+1];
        }
        
        freeCount--;
    }

    return address;
}

void deallocate(char* address)
{
    int count=0;
    while( *(address+count) != 0)
    {
        *(address+count) = 0;
        count++;
    }

    if ( *(address-2) != 0)
    {
        freeCount++;

        freePositions[ freeCount ].relativeAddress = address - heap;
        freePositions[ freeCount ].size = count+1;
    }
    else
    {
        // Think about it later
    }
}



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