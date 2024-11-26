#include <stdio.h>
#define FloatLength 20

int main()
{
    double base=2.718281828;
    float argument, ans=0,  multiplier;
    int digit, multiple_of_10=1;

    printf("Give Argument : \n");
    scanf("%f", &argument);

    for(int i=0 ; i < FloatLength ; i++)
    {
        digit = 0;
        while( base <= argument )
        {
            argument /= base;
            digit++;
        }
        printf("%02d th digit = %d\n", i, digit);
        ans += (double) digit / multiple_of_10;

        multiplier = 1.0;
        for(int j=0 ; j < 10 ; j++)
        {
            multiplier *= argument;
        }
        argument = multiplier;
        multiple_of_10 *= 10;
    }

    printf("The answer is %0.15f", ans);
    return 0;
}
