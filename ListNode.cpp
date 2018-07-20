#include "ListNode.h"
ListNode::ListNode(int data) {
    this->data = data;
    this->next = 0;
}

ListNode::~ListNode(){
    this->next = 0;
}

void frontBackSplitList(ListNode *head, ListNode **node1, ListNode **node2) {
    if (head == 0) return;
    ListNode *slow = head;
    ListNode *fast = head->next;
    while (fast !=0 && fast->next != 0) {
        slow = slow->next;
        fast = fast->next->next;
    }
    *node1 = head;
    *node2 = slow->next;
    slow->next = 0;
}

ListNode* sorted_list_merge(ListNode *head1, ListNode *head2) {
    if (head1 == 0) return head2;
    if (head2 == 0) return head1;
    ListNode *result = 0;
    if (head1->data <= head2->data) {
        result = head1;
        result->next =  sorted_list_merge(head1->next, head2);
    } else {
        result = head2;
        result->next = sorted_list_merge(head1, head2->next);
    }
    return result;
}

void merge_sort_list(ListNode **node) {
    if (node == 0 || (*node)->next == 0) return;
    ListNode *left = 0, *right = 0;
    frontBackSplitList(*node, &left, &right);
    merge_sort_list(&left);
    merge_sort_list(&right);
    ListNode *newHead = sorted_list_merge(left, right);
    *node = newHead;
}

void iteractive_reverse_list(ListNode **head) {
    if (head == 0) return;
    ListNode *pre, *cur, *next;
    pre = 0;
    cur = *head;
    while (cur != 0) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    *head = pre;
}

ListNode * _recursive_reverse_list(ListNode *node, ListNode **newHead) {
    if (node == 0) return node;
    ListNode *next = node->next;
    if (next == 0) {
        *newHead = node;
    } else {
        ListNode *tmp = _recursive_reverse_list(next, newHead);
        if (tmp != 0) {
            tmp->next = node;
        }
    }
    return node;
}

void recursive_reverse_list(ListNode **head) {
    if (head == 0 || (*head)->next == 0) return;
    ListNode *newHead = 0;
    _recursive_reverse_list(*head, &newHead);
    *head = newHead;
}