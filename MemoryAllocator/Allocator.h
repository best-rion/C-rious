#ifndef _STDIO_H
    #include <stdio.h>
#endif

#ifndef _STRING_H
    #include <string.h>
#endif

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
