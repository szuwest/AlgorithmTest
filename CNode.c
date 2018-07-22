#include <stdlib.h>
#include <stdio.h>
#include "CNode.h"

PNode _getMiddleNode(PNode head) {
    if (head ==  NULL || head->next == NULL) return head;
    Node *fast = head->next, *slow = head;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}

PNode _mergeSortedList(PNode head1, PNode head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;
    Node *newHead = NULL;
    Node *p1 = head1;
    Node *p2 = head2;
    if (head1->data > head2->data) {
        newHead = head2;
        p2 = head2->next;
    } else {
        newHead = head1;
        p1 = head1->next;
    }
    Node *cur = newHead;
    while (p1 != NULL && p2 != NULL) {
        if (p1->data < p2->data) {
            cur->next = p1;
            p1 = p1->next;
        } else {
            cur->next = p2;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    if (p1 != NULL) cur->next = p1;
    if (p2 != NULL) cur->next = p2;

    return newHead;
}

void sortSingleList(Node  **head) {
    if (head == NULL || (*head) == NULL || (*head)->next == NULL) return;
    Node *midNode = _getMiddleNode(*head);
    Node *restNode = midNode->next;
    midNode->next = NULL;
    sortSingleList(head);
    sortSingleList(&restNode);
    *head = _mergeSortedList(*head, restNode);
}

/* Function to print nodes in a given linked list */
void _printSList(Node *node)
{
    while(node!=NULL)
    {
    printf("%d ", node->data);
    node = node->next;
    }
}
 
/* Function to insert a node at the beginging of the linked list */
void _pushCNode(Node** head_ref, int new_data)
{
    /* allocate node */
    Node* new_node =
                (Node*) malloc(sizeof(Node));
    
    /* put in the data */
    new_node->data = new_data;
    
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
    
    /* move the head to point to the new node */
    (*head_ref) = new_node;
} 

void test_Single_List() {
    Node* a = NULL;
 
    /* Let us create a unsorted linked lists to test the functions
    Created lists shall be a: 2->3->20->5->10->15 */
    _pushCNode(&a, 15);
    _pushCNode(&a, 10);
    _pushCNode(&a, 5); 
    _pushCNode(&a, 20);
    _pushCNode(&a, 3);
    _pushCNode(&a, 8); 
    _pushCNode(&a, 10); 
    _pushCNode(&a, 30); 

    printf("List is: \n");
    _printSList(a);  
    /* Sort the above created Linked List */
    sortSingleList(&a);
    
    printf("\nSorted Linked List is: \n");
    _printSList(a);         
 
}