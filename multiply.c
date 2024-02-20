#include <stdio.h>
#include <stdlib.h>

int multiply(int a) 
{
    int b = rand();

    int res = 0;

    while (b > 0) {
        if (b % 2 == 1) {
            res += a;
        }
        a += 1;
        b -= 1;
    }

    return res;
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: ./multiply num");
        return -1;
    } else {
        int num = atoi(argv[1]);
        printf("%d", multiply(num));
        return 0;
    }
}