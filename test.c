/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


void Path(struct TreeNode* root, char* p, char* buffer, int* index, char** s) {

    if (root->right == NULL && root->left == NULL) {
        p += sprintf(p, "->%d", root->val);
        int n = strlen(buffer);
        char* st = (char*)malloc(sizeof(char) * (n + 1));
        strcpy(st, buffer);
        s[*index] = st;
        (*index)++;
        return;
    } else {
        p += sprintf(p, "->%d", root->val);
        if (root->left != NULL) {
            Path(root->left, p, buffer, index, s);
        }
        if (root->right != NULL) {
            Path(root->right, p, buffer, index, s);
        }
    }
}

char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    char buffer[10000];
    char* p = buffer;
    p += sprintf(p, "%d", root->val);
    char** s = (char**)malloc(sizeof(char*) * 100);
    int* index = (int*)malloc(sizeof(int));
    *index = 0;

    if (root->left == NULL && root->right == NULL) {
        sprintf(p, "\0");
        int n = strlen(buffer);
        char* st = (char*)malloc(sizeof(char) * (n + 1));
        strcpy(st, buffer);
        s[*index] = st;
        (*index)++;
    } else {
        if (root->left != NULL) {
            Path(root->left, p, buffer, index, s);
        }
        if (root->right != NULL) {
            Path(root->right, p, buffer, index, s);
        }
    }

    *returnSize = *index;
    free(index);
    return s;
}