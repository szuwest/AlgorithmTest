#include "DoubleList.h"
#include <stdlib.h>
#include <stdio.h>

DListNode* makeDoubleList() {
    DListNode *head = (DListNode *)malloc(sizeof(DListNode));
    head->data = 10;
    head->nextNode = NULL;
    head->preNode = NULL;

    return head;
}

void printDListNode(DListNode *head) {
    DListNode *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->nextNode;
    }
    printf("\n");
}

void dList_addDNode(DListNode *head, int data) {
    if (head == NULL) return;
    DListNode *p = head;
    while (p->nextNode != NULL) {
        p = p->nextNode;
    }
    DListNode *node = (DListNode *)malloc(sizeof(DListNode));
    node->data = data;
    p->nextNode = node;
    node->preNode = p;
    node->nextNode = NULL;
}

void dList_deleteNode(DListNode **head, int data){
    if (head == NULL) return;
    if ((*head)->data == data) {
        DListNode *next = (*head)->nextNode;
        next->preNode = NULL;
        *head = next;
        return;
    }
    DListNode *p = *head;
    while(p != NULL) {
        if (p->data == data) {
            p->preNode->nextNode = p->nextNode;
            p->nextNode->preNode = p->preNode;
            break;
        }
        p = p->nextNode;
    }
}

void dList_insertNode(DListNode *head, int data, int index) {
    if (head == NULL) return;
    DListNode *p = head;
    int i = 0;
    while (p != NULL) {
        if (i == index) {
            break;
        }
        p = p->nextNode;
        i++;
    }
    if (p != NULL) {
        DListNode *node = (DListNode *)malloc(sizeof(DListNode));
        node->data = data;
        node->nextNode = p->nextNode;
        node->preNode = p;
        p->nextNode = node;
        node->nextNode->preNode = node;
    }
}

void dList_reverseList(DListNode **head){
    if (head == NULL) return;
    DListNode *cur = *head;
    DListNode *pre = NULL;
    while (cur != NULL) {
        DListNode *next = cur->nextNode;
        cur->preNode = cur->nextNode;
        cur->nextNode = pre;
        pre = cur;
        cur = next;
    }
    *head = pre;
}

DListNode *lastNode(DListNode *head) {
    if (head == NULL) return head;
    DListNode *p = head;
    while (p->nextNode != NULL) {
        p = p->nextNode;
    }
    return p;
}

void swipeNode(DListNode **node1, DListNode **node2) {
    // DListNode *p = *node1, *q = *node2;
    // if (p->preNode != NULL) {
    //     p->preNode->nextNode = *node2;
    // }
    // (*node1)->preNode = (*node2)->preNode;
    // DListNode *next1 = (*node1)->nextNode;
    // DListNode *next2 = (*node2)->nextNode;
    
}

void _dList_quickSort_(DListNode *start, DListNode *end) {
    if (start == NULL || end == NULL) return;
    if (start == end) return;
    // DListNode *value = *start;
    int value = (start)->data;
    DListNode *p = start, *q = end;
    while (p != q) {
        while (q != p && (q->data) > value) {
            q = q->preNode;
        }
        if (p != q) {
            // swipeNode(&p, &q);
            // int tmp = p->data;
            p->data = q->data;
            // q->data = tmp;
            p = p->nextNode;
        }
        while (p != q && (p->data) <= value) {
            p = p->nextNode;
        }
        if (p != q) {
            // int tmp = q->data;
            q->data = p->data;
            // p->data = tmp;
            q = q->preNode;
        }
    }
    q->data = value;

    if (p != start) {
        _dList_quickSort_(start,p->preNode);
    }
    if (q != end) {
        _dList_quickSort_(q->nextNode, end);
    }
}

void dList_quickSort(DListNode **head) {
    if (head == NULL || (*head)->nextNode == NULL) return;
    DListNode *tail = lastNode(*head);
    _dList_quickSort_(*head, tail);
}

DListNode *dList_splitList(DListNode *head) {
    if (head == NULL || head->nextNode == NULL)
        return head;
    DListNode *slow = head, *fast = head->nextNode;
    while (fast != NULL && fast->nextNode != NULL) {
        slow = slow->nextNode;
        fast = fast->nextNode->nextNode;
    }
    DListNode *newNode = slow->nextNode;
    slow->nextNode = NULL;
    newNode->preNode = NULL;
    return newNode;
}

DListNode *dList_merge_list(DListNode *head1, DListNode *head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    DListNode *result = NULL;
    if (head1->data <= head2->data) {
        result = head1;
        DListNode* next = dList_merge_list(head1->nextNode, head2);
        result->nextNode = next;
        next->preNode = result;
    } else {
        result = head2;
        DListNode *next = dList_merge_list(head1, head2->nextNode);
        result->nextNode = next;
        next->preNode = next;
    }
    return result;
}

void dList_mergeSort(DListNode **head){
    if (head == NULL || (*head)->nextNode == NULL ) return;

    DListNode *node = dList_splitList(*head);
    dList_mergeSort(head);
    dList_mergeSort(&node);
    *head = dList_merge_list(*head, node);
}

void testDoubleList() {
    DListNode *head = makeDoubleList();
    dList_addDNode(head, 32);
    dList_addDNode(head, 3);
    dList_addDNode(head, 21);
    dList_addDNode(head, 5);

    dList_addDNode(head, 9);
    dList_addDNode(head, 15);
    dList_addDNode(head, 22);

    printDListNode(head);
    dList_insertNode(head,50,3);
    printDListNode(head);
    // dList_deleteNode(&head, 21);
    // printDListNode(head);
    // dList_deleteNode(&head, 5);
    // printDListNode(head);
    // dList_reverseList(&head);
    // printDListNode(head);

    // dList_mergeSort(&head);
    dList_quickSort(&head);
    printDListNode(head);
}