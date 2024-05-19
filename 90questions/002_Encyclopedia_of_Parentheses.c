#include <stdio.h>
#include <stdlib.h>


void generate_sequences(int n, int open, int close, char *sequence, int index)
{
    if (index == 2 * n) {
        sequence[index] = '\0';
        fwrite(sequence, 1, 2 * n, stdout);
        putchar('\n');
        return;
    }

    if (open < n) {
        sequence[index] = '(';
        generate_sequences(n, open + 1, close, sequence, index + 1);
    }

    if (close < open) {
        sequence[index] = ')';
        generate_sequences(n, open, close + 1, sequence, index + 1);
    }
}

void generate_all_sequences(int n)
{
    char *sequence = (char *)malloc(2 * n + 1);
    generate_sequences(n, 0, 0, sequence, 0);
    free(sequence);
}


int main()
{
    int n;
    scanf("%d", &n);
    if (n % 2 != 0)
        return 0;
    n /= 2;
    generate_all_sequences(n);
    return 0;
}