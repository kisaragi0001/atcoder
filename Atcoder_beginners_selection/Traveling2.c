#include <stdio.h>
#include <stdlib.h>

static inline int fast_input()
{
    int n = 0;
    int c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        n = 10 * n + (c - '0');
        c = getchar();
    }
    return n;

}

int main()
{
    int n;
    int t = 0, nx = 0, ny = 0;
    n = fast_input();

    for (int i = 0; i < n; i++)
    {
        int t2 = fast_input();

        int x = fast_input();

        int y = fast_input();

        int judge = (t2 - t) - (abs(nx - x) + abs(ny - y));
        if (judge < 0 || judge % 2 != 0)
        {
            printf("No\n");
            return 0;
        }

        t = t2;
        nx = x;
        ny = y;
    }
    printf("Yes\n");
    return 0;
}