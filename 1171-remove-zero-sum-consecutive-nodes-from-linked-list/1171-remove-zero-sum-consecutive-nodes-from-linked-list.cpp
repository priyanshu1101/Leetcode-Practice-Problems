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
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int,ListNode*> mp;
        head=new ListNode(0,head);
        ListNode* curr=head;
        int sum=0;
        while(curr!=NULL){
            sum+=curr->val;
            if(mp[sum]==NULL){
                mp[sum]=curr;
                curr=curr->next;
            }
            else{
                mp[sum]->next=curr->next;
                curr=curr->next;
                mp.erase(mp.begin(),mp.end());
                curr=head;
            }
        }
        return head->next;
    }
};