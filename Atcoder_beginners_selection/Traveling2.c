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
    int t = 0;
    for (int i = 0; i < n; i++)
    {
        int judge = (TL[i].t - t) - (abs(TL[i].x - nx) + abs(TL[i].y - ny));
        if (judge < 0 || judge % 2 != 0)
        {
            printf("No\n");
            return 0;
        }
        nx = TL[i].x;
        ny = TL[i].y;
        t = TL[i].t;

    }
    printf("Yes\n");
    return 0;
}