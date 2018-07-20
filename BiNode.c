#include "BiNode.h"
#include <stdio.h>


int getBiTreeDepth(PBiNode tree, int *balance) {
    if (tree == NULL) return 0;
    if (tree->left == NULL && tree->right == NULL) return 1;
    int leftD = getBiTreeDepth(tree->left, balance);
    int rightD = getBiTreeDepth(tree->right, balance);
    int tmp = leftD - rightD;
    if (tmp < -1 || tmp > 1) *balance = 0;
    return leftD > rightD ? leftD+1:rightD+1;
}

int isBalanceBiTree(PBiNode tree) {
    int balance = 1;
    int depth = getBiTreeDepth(tree, &balance);
    printf("depth=%d\n", depth);
    return balance == 1?1:0;
}

void middleViewBiTree(PBiNode tree) {
    if (tree == NULL) return;
    if (tree->left != NULL) middleViewBiTree(tree->left);
    printf("%d ", tree->data);
    middleViewBiTree(tree->right);

}

void suffixViewBiTree(PBiNode tree) {
    if (tree == NULL) return;
    suffixViewBiTree(tree->left);
    suffixViewBiTree(tree->right);
    printf("%d ", tree->data);
}

void previewBiTree(PBiNode tree) {
    if (tree == NULL) return;
    printf("%d ", tree->data);
    previewBiTree(tree->left);
    previewBiTree(tree->right);
}
