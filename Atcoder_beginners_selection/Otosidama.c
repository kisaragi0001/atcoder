#include <stdio.h>

int main()
{
    int n, y;
    scanf("%d %d", &n, &y);

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int k = n - i - j;
            if (k * 10000 + j * 5000 + i * 1000 == y)
            {
                printf("%d %d %d\n",k,j,i);
                return 0;
            }
            
        }
        
    }

    printf("-1 -1 -1\n");
    return 0;
}