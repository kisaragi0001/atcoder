#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000  // 十分大きなスタックサイズを定義

typedef struct {
    int sequence[MAX];
    int length;
    int open_count;
    int close_count;
} StackItem;

void print_sequence(int sequence[], int length) {
    for (int i = 0; i < length; i++) {
        printf("%d", sequence[i]);
    }
    printf("\n");
}

void generate_all_sequences(int n) {
    StackItem stack[MAX];
    int top = -1;

    // 初期スタックのプッシュ
    top++;
    stack[top].sequence[0] = 0;
    stack[top].length = 1;
    stack[top].open_count = 1;
    stack[top].close_count = 0;

    while (top >= 0) {
        StackItem current = stack[top];
        top--;

        if (current.open_count == n && current.close_count == n) {
            print_sequence(current.sequence, current.length);
            continue;
        }

        if (current.open_count < n) {
            top++;
            stack[top] = current;  // 現在の状態をコピー
            stack[top].sequence[current.length] = 0;
            stack[top].length = current.length + 1;
            stack[top].open_count = current.open_count + 1;
        }

        if (current.close_count < current.open_count) {
            top++;
            stack[top] = current;  // 現在の状態をコピー
            stack[top].sequence[current.length] = 1;
            stack[top].length = current.length + 1;
            stack[top].close_count = current.close_count + 1;
        }
    }
}

int main() {
    int n = 3;  // 例としてn = 3を使用
    generate_all_sequences(n);
    return 0;
}
