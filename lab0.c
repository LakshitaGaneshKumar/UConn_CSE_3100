#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");

    int i = 0;
    int sum = 0;

    while(i < 200) 
    {
        if(i % 2 == 0)
        {
            sum = sum + i;
        }

        i++;
    }

    printf("%d", sum);
    return 0;
}