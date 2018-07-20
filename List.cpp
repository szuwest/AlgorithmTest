#include "List.h"
#include <iostream>

List::List() {
    head = 0;
    size = 0;
}

List::~List() {
    if (head != 0) {
        ListNode *p = head;
        while(p != 0) {
            ListNode *q = p->next;
            delete p;
            p = q;
        }
    }
}

ListNode *List::getHead() {
    return head;
}

ListNode *List::getTail() {
    if (head == 0) return 0;
    ListNode *p = head;
    while(p->next != 0) {
        p = p->next;
    }
    return p;
}

void List::add(int data) {
    if (head == 0) {
        head = new ListNode(data);
    } else {
        ListNode *p = head;
        while(p->next != 0) {
            p = p->next;
        }
        p->next = new ListNode(data);
    }
    size++;
}

int List::insert(int data, int index) {
    if (index < 0 || index > size) return -1;
    int i = 0;
    if (head == 0) {
        head = new ListNode(data);
    } else {
        ListNode *p = new ListNode(data);
        if (index == 0) {
            p->next = head;
            head = p;
        } else {
            ListNode *q = head;
            while(i<index-1) {
                q = q->next;
                i++;
            }
            p->next = q->next;
            q->next = p;
        }
    }
    size++;
    return 0;
}

int List::indexOf(int data) {
    int i = 0;
    ListNode *p = head;
    while(p != 0) {
        if (p->data == data) return i;
        i++;
        p = p->next;
    }
    return -1;
}

ListNode *List::getNode(int index) {
    int i = 0;
    ListNode *p = head;
    while(p != 0) {
        if (index == i) return p;
        i++;
        p = p->next;
    }
    return 0;
}

ListNode *List::get(int data) {
    int i = 0;
    ListNode *p = head;
    while(p != 0) {
        if (p->data == data) return p;
        i++;
        p = p->next;
    }
    return 0;
}

void List::remove(int index) {
    if (index < 0 || index > size-1) return;
    if (index == 0) {
        ListNode *q = head;
        head = head->next;
        delete q;
    } else {
        int i = 0;
        ListNode *p = head;
        while(p != 0) {
            if (index-1 == i){
                ListNode *q = p->next;
                p->next = q->next;
                delete q;
                break;
            };
            i++;
            p = p->next;
        }
    }
    size--;
}

// void List::removeData(int data) {
//     ListNode *node = get(data);
//     if (node != 0) {
//         ListNode *p = node->next;
//         node->data = p->data;
//         node->next = p->next;
//         delete p;
//         size--;
//     }
// }

void List::removeData(int data) {
    ListNode *preNode = 0;
    ListNode *p = head;
    while(p != 0) {
        if (p->data == data) {
            if (preNode == 0) {
                ListNode *q = head;
                head = head->next;
                delete q;
            } else {
                preNode->next = p->next;
                delete p;
            }
            size--;
            break;
        } else {
            preNode = p;
            p = p->next;           
        }
    }
}

ListNode* List::reverse2(ListNode *node, ListNode *newHead) {
    if (node != 0 && node->next != 0) {
        ListNode *lastNode = reverse2(node->next, newHead);
        lastNode->next = node;
        return node;
    } else {
        newHead->next = node;
        return node;
    }
}

ListNode* List::reverseList(ListNode *node) {
    ListNode *pre = 0;
    ListNode *cur = node;
    ListNode *next = cur->next;
    cur->next = pre;
    pre = cur;
    cur = next;
    next = cur->next;
    while(cur != 0) {
        cur->next = pre;
        pre = cur;
        cur = next;
        if (cur != 0) 
            next = cur->next;
    }
    return pre;
}

void List::reverse() {
    ListNode p(0);
    ListNode *q = reverse2(head, &p);
    q->next = 0;
    head = p.next;

    // head = reverseList(head);
}

void List::printList() {
    ListNode *p = head;
    while(p != 0) {
        std::cout<<p->data<<" ";
        p = p->next;
    }
    std::cout<<std::endl;
}

int List::getSize() {
    return size;
}

void List::sort() {
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    int i = 0;
    
    while(i<size) {
        ListNode *pre = newHead;
        ListNode *cur = pre->next;
        int j = 0;
        bool flag = false;
        while(j<size-i-1) {
            ListNode *next = cur->next;
            if (cur->data > next->data) {
                pre->next = next;
                cur->next = next->next;
                next->next = cur;
                flag = true;
                pre = pre->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
            j++;
        }
        i++;
        if (!flag) {
            break;
        }
    }

    head = newHead->next;
    delete newHead;
}

void FrontBackSplit(ListNode *head, ListNode **nodeA, ListNode **nodeB) {
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

ListNode * SortedMerge2(ListNode *nodeA, ListNode *nodeB) {
    if (nodeA == 0) return nodeB;
    if (nodeB == 0) return nodeA;
    ListNode *result;
    if (nodeA->data <= nodeB->data) {
        result = nodeA;
        result->next = SortedMerge2(nodeA->next, nodeB);
    } else {
        result = nodeB;
        result->next = SortedMerge2(nodeA, nodeB->next);
    }
    return result;
}

ListNode * sortedMerge(ListNode *nodeA, ListNode *nodeB) {
    if (nodeA == 0) return nodeB;
    if (nodeB == 0) return nodeA;
    ListNode *head = 0;
    ListNode *p = nodeA;
    ListNode *q = nodeB;
    if (nodeA->data > nodeB->data) {
        head = nodeB;
        q = nodeB->next;
    }
    else {
        head = nodeA;
        p = nodeA->next;
    }
    ListNode *cur = head;
    while (p != 0 && q != 0) {
        if (p->data < q->data) {
            cur->next = p;
            cur = p;
            p = p->next;
        } else {
            cur->next = q;
            cur = q;
            q = q->next;
        }
    }
    if (p != 0) cur->next = p;
    else if (q != 0) cur->next = q;

    return head;
}

void MergeSort2(ListNode **headRef) {
    ListNode *head = *headRef;
    if (head == 0) return;
    if (head->next == 0) return;

    ListNode *nodeA = 0, *nodeB = 0;
    FrontBackSplit(head, &nodeA, &nodeB);
    MergeSort2(&nodeA);
    MergeSort2(&nodeB);

    *headRef = sortedMerge(nodeA, nodeB);
}

void List::MergeSort() {
    MergeSort2(&head);
}