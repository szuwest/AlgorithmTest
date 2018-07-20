#include "List.h"

class ListTest {
public:
    List *makeList();
    bool hasCircleList(ListNode *head);
    int getMinInCircleList(List *circlList);
    ListNode* isListInteract(List *list1, List *list2);
    ListNode * getIntersectionNode(List *list1, List *list2);

    void sortList(List *list);
    void mergeSort(List *list);
    void reverseList(List *list);

    void test();
};