#include "BiNode.h"
#include <stdio.h>
#include <stdlib.h>
#include <queue>

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

void levelViewBiTree(PBiNode tree) {
    if (tree == NULL) return;
    std::queue<PBiNode> _queue;
    _queue.push(tree);
    int count = 1;
    while(!_queue.empty()) {
        PBiNode node = _queue.front();
        _queue.pop();
        count--;
        printf("%d ", node->data);
        if (node->left != NULL) _queue.push(node->left);
        if (node->right != NULL) _queue.push(node->right);

        if (count <= 0) {
            printf("\n");
            count = _queue.size();
        }
    }
}

void testAVLTree() {
    PBiNode root = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node1 = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node2 = (PBiNode)malloc(sizeof(BiNode));
    PBiNode node3 = (PBiNode)malloc(sizeof(BiNode));
    root->left = node1;
    root->data = 1;
    root->right = node2;

    node1->data = 2;
    node1->left = node3;
    node1->right = NULL;

    node2->data = 3;
    node2->left = NULL;
    node2->right = NULL;

    node3->data = 4;
    node3->left = NULL;
    node3->right = NULL;

    printf("\n前序遍历\n");
    previewBiTree(root);

    printf("\n后续遍历\n");
    suffixViewBiTree(root);

    printf("\n中序遍历\n");
    middleViewBiTree(root);

    printf("\n层序遍历\n");
    levelViewBiTree(root);
    printf("\n");
    int isBalance = 1;
    isBalance = isBalanceBiTree(root);
    printf("isBalance=%s\n",(isBalance?"true":"false"));

    PBiNode node4 = (PBiNode)malloc(sizeof(BiNode));
    node4->data = 5;
    node4->left = NULL;
    node4->right = NULL;
    // node2->left = node4;
    node3->left = node4;

    printf("\n前序遍历\n");
    previewBiTree(root);

    printf("\n后续遍历\n");
    suffixViewBiTree(root);

    printf("\n中序遍历\n");
    middleViewBiTree(root);

    printf("\n层序遍历\n");
    levelViewBiTree(root);
    printf("\n");
    isBalance = 1;
    isBalance = isBalanceBiTree(root);
    printf("isBalance=%s\n",(isBalance?"true":"false"));

    free(root);
    free(node1);
    free(node2);
    free(node3);
    free(node4);
}