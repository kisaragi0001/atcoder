#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int *a = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    int Alice = 0;
    int Bob = 0;
    int turn = 0;
    for (int i = 0; i < n; i++)
    {
        int max = 0;
        int index = -1;
        for (int j = 0; j < n; j++)
        {
            if (a[j] > max)
            {
                max = a[j];
                index = j;
            }
        }
        a[index] = 0;
        if (turn == 0)
        {
            Alice += max;
            turn = 1;
        }
        else
        {
            Bob += max;
            turn = 0;
        }
    }

    printf("%d\n", Alice - Bob);

    return 0;
}