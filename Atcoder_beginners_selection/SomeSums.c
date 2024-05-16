#include <stdio.h>

int main()
{
    int n, a, b;
    int sum = 0;
    int judge;
    scanf("%d %d %d", &n, &a, &b);

    for (int i = 1; i <= n; i++)
    {
        judge = 0;
        judge += i / 10000;
        judge += (i % 10000) / 1000;
        judge += (i % 1000) / 100;
        judge += (i % 100) / 10;
        judge += i % 10;

        if (a <= judge && b >= judge)
            sum += i;
    }

    printf("%d\n", sum);

    return 0;
}