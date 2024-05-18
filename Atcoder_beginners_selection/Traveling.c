#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int t;
    int x;
    int y;
} Traveling;

int main()
{
    int n;
    scanf("%d", &n);
    Traveling *TL = (Traveling *)malloc(n * sizeof(Traveling));
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &TL[i].t, &TL[i].x, &TL[i].y);

    int nx = 0;
    int ny = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = count; j < TL[i].t; j++)
        {
            if (nx == TL[i].x && ny == TL[i].y)
            {
                if ((TL[i].t - j) % 2 == 0)
                    break;
                j = TL[i].t;
                nx += 1;
            }
            else if (nx != TL[i].x)
            {
                if (abs(nx - TL[i].x) <= (TL[i].t - j))
                {
                    j += abs(nx - TL[i].x) - 1;
                    nx = TL[i].x;
                }
                else
                    break;
            }
            else
            {
                if (abs(ny - TL[i].y) <= (TL[i].t - j))
                {
                    j += abs(ny - TL[i].y) - 1;
                    ny = TL[i].y;
                }
                else
                    break;
            }
        }

        if (!(nx == TL[i].x && ny == TL[i].y))
        {
            printf("No\n");
            return 0;
        }
        count = TL[i].t;
    }
    printf("Yes\n");
    return 0;
}