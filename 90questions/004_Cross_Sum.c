#include <stdio.h>
#include <string.h>


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
    int H = fast_input();
    int W = fast_input();
    int sum_W[H];
    for (int i = 0; i < H; i++)
        sum_W[i] = 0;
    int sum_H[W];
    for (int i = 0; i < W; i++)
        sum_H[i] = 0;
    int array[H][W];
    
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            int x = fast_input();
            sum_W[i] += x;
            sum_H[j] += x;
            array[i][j] = x;
        }
    }
    int size = 12 * W + 1;
    char buffer[size];
    for (int i = 0; i < H; i++)
    {
        memset(buffer, 0, sizeof(char) * size);
        char *p = buffer;
        for (int j = 0; j < W; j++)
            p += sprintf(p, "%d ", sum_W[i] + sum_H[j] - array[i][j]);
        *p = '\n';
        p++;
        *p = '\0';
        fwrite(buffer, sizeof(char), strlen(buffer), stdout);
    }

    return 0;
}