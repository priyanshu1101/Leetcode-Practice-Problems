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
            }
            else{
                ListNode* start = mp[sum];
                ListNode* temp=start->next;
                int tempsum=sum;
                while(temp!=curr->next){
                    tempsum+=temp->val;
                    mp.erase(tempsum);
                    temp=temp->next;
                }
                start->next=curr->next;
            }
            curr=curr->next;
        }
        return head->next;
    }
};