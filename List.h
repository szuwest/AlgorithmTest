#include "ListNode.h"

class List {

public:
    List();
    ~List();

    ListNode *getHead();
    ListNode *getTail();
    void add(int data);
    int insert(int data, int index);

    int indexOf(int data);
    ListNode *getNode(int index);
    ListNode *get(int data);

    void remove(int index);
    void removeData(int data);

    void reverse();
    void printList();

    int getSize();
    void sort();
    void MergeSort();

private:
    ListNode* reverse2(ListNode *node, ListNode *newHead);
    ListNode* reverseList(ListNode *node);

    ListNode *head;
    int size;
};