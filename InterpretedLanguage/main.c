#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    FILE *filePtr;
    filePtr = fopen("file.rion", "r");
    char content[100];
    fscanf(filePtr,"%99[^\n]", content);

    // Logic part
    char* display = "display";
    char* index = content;

    while( strstr(index, display) != NULL )
    {
        index = strstr(index, display);

        index+=strlen(display);

        int numOfTimes = 0;

        int power = 0;

        if (*index == '[')
        {
            index+=1;
            while( *index != ']' )
            {
                power++;
                index++;
            }

            index-=power;

            for(int i=power-1; i>=0; i--)
            {
                numOfTimes += (int) pow(10, i)*( (*index) - '0' );
                index++;
            }
        }

        if (numOfTimes == 0)
        {
            numOfTimes = 1;
        }


        while (*index != '"')
        {
            index++;
        }
        index+=1;

        char displayable[20]={0};
        
        int iter=0;
        while(*index != '"')
        {
            displayable[iter] = *index;
            index++;
            iter++;
        }

        for (int i=0; i<numOfTimes; i++)
        {
            printf("%s\n", displayable);
        }
    } 

    return 0;
}