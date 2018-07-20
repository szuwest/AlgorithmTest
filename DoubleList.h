#ifndef _DOUBLE_LIST_H
#define _DOUBLE_LIST_H

#ifdef __cplusplus
extern "C" {
#endif  

typedef struct _DoubleListNode {
    int data;
    struct _DoubleListNode *preNode;
    struct _DoubleListNode *nextNode;
}DListNode, *PDNode;

DListNode* makeDoubleList();

void dList_addDNode(DListNode *head, int data);

void dList_deleteNode(DListNode **head, int data);

void dList_reverseList(DListNode **head);

void dList_quickSort(DListNode **head);

void dList_mergeSort(DListNode **head);

void testDoubleList();

#ifdef __cplusplus
}
#endif

#endif