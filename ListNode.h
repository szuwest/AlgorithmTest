#ifndef _LISTNODE_H
#define _LISTNODE_H

class ListNode {

public:
    ListNode(int data);
    ~ListNode();

public:
    int data;
    ListNode *next;

};

#endif