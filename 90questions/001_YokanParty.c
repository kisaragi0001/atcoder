#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y) (((x) < (y)) ? (x) : (y))

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
    int n = fast_input();
    int L = fast_input();
    int k = fast_input();

    int *a = (int *)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        a[i] = fast_input();
    }

    int left = -1, right = L + 1;
    int count = 0;
    int prev = 0;
    while (right - left > 1)
    {
        int mid = (left + right) / 2;
        count = 0;
        prev = 0;
        for (int i = 0; i < n; i++)
        {
            if ((a[i] - prev) >= mid)
            {
                count++;
                prev = a[i];
            }
        }
        if ((L - prev) >= mid)
            count++;
        if (count >= k + 1)
            left = mid;
        else
            right = mid;
    }

    printf("%d\n", left);

    return 0;
}