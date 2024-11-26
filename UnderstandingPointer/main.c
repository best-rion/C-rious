#include <stdio.h>
#define MaxLen 10

void localARRAY(char* arrayP,int size,int max_len)
{
    char localCopy[size][max_len];
    char c;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<max_len;j++)
        {
            if((c=*(arrayP+i*max_len+j))!='\0')
            {
                localCopy[i][j]=c;
            }else
            {
                localCopy[i][j]=c;
                break;
            }
        }
    }

    for(int i=0;i<size;i++)
    {
        printf("%s\n",localCopy[i]);
    }
}

void reverseARRAY(char* arrayP,int size,int max_len)
{
    char localCopy[size][max_len] ;
    char c;


    for(int i=0;i<size;i++)
    {
        for(int j=0;j<max_len;j++){
            if((c=*(arrayP + i * max_len +j))!='\0')
            {
                localCopy[i][j]=c;
            }else
            {
                localCopy[i][j]=c;
                break;
            }
        }
    }


    for(int i=0;i<size;i++)
    {
        for(int j=0;j<max_len;j++)
        {
            if( localCopy[i][j] != '\0' )
            {
                *(arrayP + (size-1-i) * max_len + j) = localCopy[i][j];
            }else
            {
                *(arrayP + (size-1-i) * max_len + j) = localCopy[i][j];
                break;
            }
        }
    }


    for(int i=0;i<size;i++)
    {
        printf("%s\n",localCopy[i]);
    }
}


int main()
{
    char  x[][MaxLen]={"Alieaf","sabifdfd","jack","teristin"};
    int x_size = sizeof(x)/sizeof(x[0]);
    reverseARRAY(&x[0][0],x_size,MaxLen);
    localARRAY(&x[0][0],x_size,MaxLen);

    return 0;
}
