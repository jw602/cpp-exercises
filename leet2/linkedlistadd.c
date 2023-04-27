#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int printList(struct ListNode* l1) {
    if(l1) {
        printf("Next Element: %d\n", l1->val);
        printList(l1->next);
    }
    return 0;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* l3 = malloc(sizeof(struct ListNode));
    struct ListNode* head = l3;
    int carry = 0;
    while(l1 || l2 || carry) {
        int val1 = 0, val2 = 0;
        val1 = l1 ? l1->val : 0;
        val2 = l2 ? l2->val : 0;
        l3->next = malloc(sizeof(struct ListNode));
        l3 = l3->next;
        l3->val = (val1 + val2 + carry) % 10;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        l3->next = NULL;
        carry = (val1 + val2 + carry) / 10;
    }
    return head->next;
}

struct ListNode* fillList(struct ListNode* l1, int nums[]) {
    return NULL;
}

int main(int argc, char *argv[]) {
    struct ListNode* l1 = malloc(sizeof(struct ListNode));
    struct ListNode* l2 = malloc(sizeof(struct ListNode));
    struct ListNode* head1 = l1;
    struct ListNode* head2 = l2;
    l1->val = 2;
    l2->val = 5;
    l1->next = malloc(sizeof(struct ListNode));
    l2->next = malloc(sizeof(struct ListNode));
    l1 = l1->next;
    l2 = l2->next;
    l1->val = 4;
    l2->val = 6;
    l1->next = malloc(sizeof(struct ListNode));
    l2->next = malloc(sizeof(struct ListNode));
    l1 = l1->next;
    l2 = l2->next;
    l1->val = 3;
    l2->val = 4;

    struct ListNode* l3 = addTwoNumbers(head1, head2);
    printList(l3);
    
    return 0;
}