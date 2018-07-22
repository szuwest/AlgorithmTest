#ifndef _CNODE_h
#define _CNODE_h

#ifdef __cplusplus
extern "C" {
#endif    

typedef struct _Node{
    int data;
    struct _Node *next;
}Node, *PNode;

void sortSingleList(Node **head);
void test_Single_List();

#ifdef __cplusplus
}
#endif

#endif