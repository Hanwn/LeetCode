/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x){
        ListNode* dummy1 = new ListNode(0);
        ListNode* curr1 = dummy1;
        ListNode* dummy2 = new ListNode(0);
        ListNode* curr2 = dummy2;
        ListNode* curr = head;
        while(curr){
            if(curr->val < x){
                curr1->next = new ListNode(curr->val);
                curr1 = curr1->next;
                curr1->next = nullptr;
            }else{
                curr2->next = new ListNode(curr->val);
                curr2 = curr2->next;
                curr2->next = nullptr;
            }
            curr = curr->next;
        }
        curr1->next = dummy2->next;
        return dummy1->next;
    }
};
