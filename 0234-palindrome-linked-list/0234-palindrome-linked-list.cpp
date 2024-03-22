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
    ListNode* midFinder(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
    ListNode* reverseList(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* newHead=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* mid=midFinder(head);
        ListNode* reverseHead = reverseList(mid);
        while(reverseHead){
            if(head->val!=reverseHead->val) return false;
            reverseHead=reverseHead->next;
            head=head->next;
        }
        return true;
    }
};