/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to easily handle edge cases (like empty lists)
    struct ListNode dummy;
    dummy.next = NULL;
    
    // Tail pointer used to build the new list
    struct ListNode *tail = &dummy;

    // Traverse both lists as long as neither is empty
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        // Move the tail forward
        tail = tail->next;
    }

    // Attach any remaining nodes from list1 or list2
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the actual head of the merged list, which is right after the dummy node
    return dummy.next;
}