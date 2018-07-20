#include "ListTest.h"
#include <iostream>

void ListTest::test() {
    List *list = makeList();
    list->printList();
    std::cout<<"size="<<(list->getSize())<<std::endl;
    int index = list->indexOf(11);
    std::cout<<"11 is at index "<<(index)<<std::endl;

    // list->removeData(11);
    // list->printList();

    // list->insert(11, 5);
    // list->printList();

    // list->removeData(10);
    // list->remove(0);
    // list->printList();
    // std::cout<<"sort list"<<std::endl;
    // sortList(list);
    // list->sort();
    // mergeSort(list);
    // list->MergeSort();
    // list->printList();

    // list->reverse();
    // list->printList();

    ListNode *tail = list->getTail();
    tail->next = list->getNode(3);
    bool isCircle = hasCircleList(list->getHead());
    std::cout<<"is circle list "<<(isCircle?"true":"false")<<std::endl;
    int min = getMinInCircleList(list);
    std::cout<<"min="<<min<<std::endl;

    // List *list2 = new List();
    // list2->add(44);
    // list2->add(31);
    // list2->add(9);
    // list2->add(63);
    // list2->getTail()->next = list->getNode(5);
    // list2->printList();
    // // ListNode *node = isListInteract(list, list2);
    // ListNode *node = getIntersectionNode(list, list2);
    // if (node != 0) std::cout<<"interact node="<<(node->data)<<std::endl;
    // std::cout<<"isInter "<<(node!=0?"true":"false")<<std::endl;

}

List *ListTest::makeList() {
    List *list = new List();
    list->add(10);
    list->add(13);
    list->add(3);
    list->add(11);
    list->add(5);
    list->add(32);
    list->add(21);
    list->add(18);
    list->add(100);
    return list;
}

bool ListTest::hasCircleList(ListNode *head) {
    ListNode *p = head;
    ListNode *q = head;
    while (q != 0 && q->next != 0) {
        p = p->next;
        q = q->next->next;
        if (p == q) return true;
    }
    return false;
}

int ListTest::getMinInCircleList(List *circlList) {
    if (circlList == 0 || circlList->getHead() == 0) return -1;
    ListNode *minNode;
    ListNode *p = circlList->getHead();
    int min = p->data + 1;
    ListNode *slow = circlList->getHead();
    ListNode *fast = circlList->getHead();
    while (fast != 0 && fast->next != 0) {
        if (slow->data < min) {
            min = slow->data;
            minNode = slow;
        }
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    return min;
}

ListNode* ListTest::isListInteract(List *list1, List *list2) {
    if (list1 == 0 || list1->getHead() == 0 || list2 == 0 || list2->getHead() == 0) return 0;
    ListNode *p = list1->getHead();
    while(p != 0) {
        ListNode *q = list2->getHead();
        while(q != 0) {
            if (p == q) return p;
            q = q->next;
        }
        p = p->next;
    }
    
    return 0;
}

ListNode * ListTest::getIntersectionNode(List *list1, List *list2) {
    if (list1 == 0 || list1->getHead() == 0 || list2 == 0 || list2->getHead() == 0) return 0;

    int size1 = 0;
    ListNode *tmp = list1->getHead();
    while(tmp != 0) {
        tmp = tmp->next;
        size1++;
    }
    int size2= 0;
    tmp = list2->getHead();
    while(tmp != 0) {
        tmp = tmp->next;
        size2++;
    }

    ListNode *p1 = list1->getHead();
    ListNode *p2 = list2->getHead();
    if (size1>size2) {
        int i = 0;
        int distance = size1-size2;
        while(i<distance) {
            p1 = p1->next;
            i++;
        }
    } else {
        int distance = size2-size1;
        int i = 0;
        while(i<distance) {
            p2 = p2->next;
            i++;
        }
    }
    while(p1 != 0 && p2 != 0) {
        if (p1 == p2) return p1;
        p1 = p1->next;
        p2 = p2->next;
    }
    return 0;
}

void ListTest::sortList(List *list) {
    if (list == 0 || list->getHead() == 0) return;
    ListNode *p = list->getHead();
    int size = 0;
    bool flag = true;
    while(p!=0) {
        if (p->next != 0) {
            if (p->data > p->next->data) {
                int tmp = p->data;
                p->data = p->next->data;
                p->next->data = tmp;
                flag = false;
            }
        }
        p = p->next;
        size++;
    }
    size--;
    while(size>1 && !flag) {
        flag = true;
        int i = 0;
        p = list->getHead();
        while(i<size-1) {
            if (p->data > p->next->data) {
                int tmp = p->data;
                p->data = p->next->data;
                p->next->data = tmp;
                flag = false;
            }
            i++;
            p = p->next;
        }
        size--;
    }
}

void ListTest::reverseList(List *list) {

}

void frontBackSplit(ListNode *head, ListNode **nodeA, ListNode **nodeB) {
    if (head == 0) return;
    
    ListNode *p = head;
    ListNode *q = head->next;
    while (q != 0) {
        q = q->next;
        if (q != 0) {
            p = p->next;
            q = q->next;
        }
    }
    *nodeA = head;
    *nodeB = p->next;
    p->next = 0;
}

ListNode * sortedMerge2(ListNode *nodeA, ListNode *nodeB) {
    if (nodeA == 0) return nodeB;
    if (nodeB == 0) return nodeA;
    ListNode *result;
    if (nodeA->data <= nodeB->data) {
        result = nodeA;
        result->next = sortedMerge2(nodeA->next, nodeB);
    } else {
        result = nodeB;
        result->next = sortedMerge2(nodeA, nodeB->next);
    }
    return result;
}

void mergeSort2(ListNode **headRef) {
    ListNode *head = *headRef;
    if (head == 0) return;
    if (head->next == 0) return;

    ListNode *nodeA = 0, *nodeB = 0;
    frontBackSplit(head, &nodeA, &nodeB);
    mergeSort2(&nodeA);
    mergeSort2(&nodeB);

    *headRef = sortedMerge2(nodeA, nodeB);
}

void ListTest::mergeSort(List *list) {
    if (list == 0 || list->getHead() == 0) return;
    ListNode *head = list->getHead();
    mergeSort2(&head);
}