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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* newNode = new ListNode();
        ListNode* store = newNode;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                newNode->next = new ListNode(l1->val);
                newNode = newNode->next;
                l1 = l1->next;
            } else {
                newNode->next = new ListNode(l2->val);
                newNode = newNode->next;
                l2 = l2->next;
            }
        }
        
        while (l1) {
            newNode->next = new ListNode(l1->val);
            newNode = newNode->next;
            l1 = l1->next;
        }
        while (l2) {
            newNode->next = new ListNode(l2->val);
            newNode = newNode->next;
            l2 = l2->next;
        }
        return store->next;
    }
};