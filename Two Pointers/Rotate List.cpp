/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == NULL)
            return head;
        
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            len ++;
            temp = temp -> next;
        }
        
        k %= len;
        if (k == 0)
            return head;
        
        temp = head;
        for (int i = 0; i < len - k - 1; i ++)
            temp = temp -> next;
        
        ListNode* temp2 = head;
        head = temp -> next;
        temp -> next = NULL;
        temp = head;
        
        while (temp -> next != NULL)
            temp = temp -> next;
        temp -> next = temp2;
        return head;
    }
};
