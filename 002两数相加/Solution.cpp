//solution 1:
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int count1 = 0;
        int count2 = 0;
        while(p1!=NULL){
            count1++;
            p1 = p1->next;
        }
        while(p2!=NULL){
            count2++;
            p2 = p2->next;
        }
        
        if(count1>count2){
            p1 = l1;
            p2 = l2;
            while(p2!=NULL){
                p1->val = p1->val+p2->val;
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = l1;
            while(p1->next!=NULL){
                if(p1->val>9){
                    p1->val -= 10;
                    p1->next->val++;
                    p1 = p1->next;
                }else{
                    p1 = p1->next;
                }
            }
            if(p1->val>9){
                p1->val -= 10;
                p1->next = new ListNode(1);
            }
            return l1;
        }else{
            p1 = l1;
            p2 = l2;
            while(p1!=NULL){
                p2->val = p1->val+p2->val;
                p2 = p2->next;
                p1 = p1->next;
            }
            p2 = l2;
            while(p2->next!=NULL){
                if(p2->val>9){
                    p2->val -= 10;
                    p2->next->val++;
                    p2 = p2->next;
                }else{
                    p2 = p2->next;
                }
            }
            if(p2->val>9){
                p2->val -= 10;
                p2->next = new ListNode(1);
            }
            return l2;
        }
        
    }
};


//solution 2:
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode preHead(0),*p = &preHead;
	int extra = 0;
	while(l1||l2||extra){
	    int sum = (l1?l1->val:0)+(l2?l2->val:0) + extra;
	    extra = sum /10;
	    p->next = new ListNode(sum%10);
	    p = p->next;
	    l1 = l1?l1->next:l1;
	    l2 = l2?l2->next:l2;
	}
	return preHead.next;
    }
};
