#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *d = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &d[i]);
    }
    int count = 0;
    int min = 1000;
    int std = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (min > d[j] && std < d[j])
                min = d[j];
        }
        if (min > std && min != 1000)
            count++;
        std = min;
        min = 1000;
    }

    printf("%d\n", count);
    return 0;
}