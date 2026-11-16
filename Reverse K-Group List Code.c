/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if(!head || k == 1)
    return head;
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode *prevGroup = &dummy;
    while(1)
    {
        struct ListNode *kth = prevGroup;
        for(int i=0;i<k && kth;i++)
        {
            kth = kth->next;
        }
        if(!kth)
        break;
        struct ListNode *groupStart = prevGroup->next;
        struct ListNode *nextGroup = kth->next;
        struct ListNode *prev = nextGroup;
        struct ListNode *curr = groupStart;
        while(curr != nextGroup)
        {
            struct ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        prevGroup->next = kth;
        prevGroup = groupStart;
    }
    return dummy.next;
}
