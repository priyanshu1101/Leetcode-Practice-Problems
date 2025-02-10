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
    int getLength(ListNode* head){
        int length=0;
        while(head){
            length++;
            head=head->next;
        }
        return length;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || !head->next || k==0) return head;
        int length=getLength(head);
        k = k%length;
        ListNode* dummy=new ListNode(-1,head);
        ListNode* temp=dummy;
        while(k--){
            dummy=dummy->next;
        }
        while(dummy->next){
            dummy=dummy->next;
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;
        temp=newHead;
        while(temp->next){
            temp=temp->next;
        }
        temp->next=head;
        return newHead;
    }
};