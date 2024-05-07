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
    void listModifier(ListNode* head,int &carry){
        if(!head) return;
        listModifier(head->next,carry);
        head->val=(head->val*2)+carry;
        carry=head->val/10;
        head->val=head->val%10;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry=0;
        listModifier(head,carry);
        return carry==0? head:new ListNode(carry,head);
    }
};