#include <stdio.h>
#include <stdlib.h>

#define N 100010

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

typedef struct
{
    int d;
    int *connect;
    int c_num;
    int index_c;
    int parent;
} Tree;

Tree init_Tree()
{
    Tree tree;
    tree.d = 0;
    tree.connect = NULL;
    tree.c_num = 0;
    tree.index_c = 0;
    tree.parent = -1;
    return tree;
}

typedef struct
{
    int a;
    int b;
} Edge;

int search(Tree *tree, int n, int start)
{
    int stack[n];
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        tree[i].d = __INT_MAX__;
        tree[i].index_c = 0;
        tree[i].parent = -1;
    }

    tree[start].d = 0;
    tree[start].parent = start;
    stack[index++] = start;
    int max_d_id = start;
    int score = 0;
    while (1)
    {
        if (index == 0)
            break;
        
        int min_d = stack[--index];
        

        for (int i = 0; i < tree[min_d].c_num; i++)
        {
            int root = tree[min_d].connect[tree[min_d].index_c];
            if (root == tree[min_d].parent)
            {
                tree[min_d].index_c++;
                continue;
            }
            tree[root].d = tree[min_d].d + 1;
            tree[root].parent = min_d;
            tree[min_d].index_c++;
            stack[index++] = root;
            if (tree[root].d > score)
            {
                score = tree[root].d;
                max_d_id = root;
            }
        }
    }
    
    return max_d_id;
}

int main()
{
    int n = fast_input();
    Tree *tree = (Tree *)malloc(n * sizeof(Tree));
    Edge *edge = (Edge *)malloc((n - 1) * sizeof(Edge));
    int table[N];
    for (int i = 0; i < N; i++)
        table[i] = -1;
    
    int index_t = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int A = fast_input();
        int B = fast_input();

        if (table[A] == -1)
        {
            table[A] = index_t;
            tree[index_t] = init_Tree();
            index_t++;
        }
        if (table[B] == -1)
        {
            table[B] = index_t;
            tree[index_t] = init_Tree();
            index_t++;
        }

        tree[table[A]].c_num++;
        tree[table[B]].c_num++;
        edge[i].a = table[A];
        edge[i].b = table[B];
    }

    for (int i = 0; i < n; i++)
        tree[i].connect = (int *)malloc(tree[i].c_num * sizeof(int));

    for (int i = 0; i < n - 1; i++)
    {
        int A = edge[i].a;
        int B = edge[i].b;

        tree[A].connect[tree[A].index_c++] = B;
        tree[B].connect[tree[B].index_c++] = A;
    }
    
    free(edge);

    int u = search(tree, n, 0);
    int v = search(tree, n, u);

    printf("%d\n", tree[v].d + 1);

    for (int i = 0; i < n; i++)
        free(tree[i].connect);
    free(tree);
    

    return 0;
}
