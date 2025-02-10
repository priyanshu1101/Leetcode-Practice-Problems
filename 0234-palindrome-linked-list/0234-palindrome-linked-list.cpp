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
    string number(ListNode* head){
        string ans="";
        while(head){
            ans+=head->val+'0';
            head=head->next;
        }
        return ans;
    }
    bool isPalindrome(ListNode* head) {
        string getNumber = number(head);
        string revNumber = getNumber;
        reverse(revNumber.begin(),revNumber.end());
        return  revNumber==getNumber;
    }
};