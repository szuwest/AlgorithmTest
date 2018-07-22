#ifndef _BINODE_h
#define _BINODE_h

#ifdef __cplusplus
extern "C" {
#endif     

typedef struct BiNode {
    int data;
    struct BiNode *left;
    struct BiNode *right;
} BiNode, *PBiNode;

int isBalanceBiTree(PBiNode tree);
void previewBiTree(PBiNode tree);
void suffixViewBiTree(PBiNode tree);
void middleViewBiTree(PBiNode tree);

void testAVLTree();

#ifdef __cplusplus
}
#endif

#endif