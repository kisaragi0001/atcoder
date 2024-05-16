#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int count = 0;
    if (a / 100 == 1)
    {
        count++;
    }
    if (a / 10 % 10 == 1)
    {
        count++;
    }
    if (a % 10 == 1)
    {
        count++;
    }
    printf("%d\n", count);
    return 0;
}