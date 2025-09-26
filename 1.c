//merge two sorted linkedlist

#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list
struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* newNode(int val) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

// Function to merge two sorted linked lists (iterative version)
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // dummy node to simplify
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }

    // attach the remaining nodes
    if (list1) tail->next = list1;
    else tail->next = list2;

    return dummy.next;
}

// Utility function to create linked list from array
struct ListNode* createList(int arr[], int n) {
    if (n == 0) return NULL;
    struct ListNode* head = newNode(arr[0]);
    struct ListNode* curr = head;
    for (int i = 1; i < n; i++) {
        curr->next = newNode(arr[i]);
        curr = curr->next;
    }
    return head;
}

// Utility function to print linked list
void printList(struct ListNode* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};

    struct ListNode* list1 = createList(arr1, 3);
    struct ListNode* list2 = createList(arr2, 3);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* merged = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(merged);

    return 0;
}
