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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* newHead=new ListNode(-1,head);
        ListNode* temp=newHead;
        while(n--) temp=temp->next;
        ListNode* newTemp=newHead;
        while(temp->next){
            temp=temp->next;
            newTemp=newTemp->next;
        }
        newTemp->next=newTemp->next->next;
        return newHead->next;
    }
};