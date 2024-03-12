/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=que.front();
                que.pop();
                if(temp==NULL) ans+="N ";
                else{
                    ans+=to_string(temp->val)+" ";
                    que.push(temp->left);
                    que.push(temp->right);
                }
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    int getNumber(string &data){
        int number=0;
        if(data[0]=='N'){
            number=1001;
            data=data.substr(2,data.length()-2);
            return number;
        }
        int neg=1;
        if(data[0]=='-'){
            neg=-1;
            data=data.substr(1,data.length()-1);
        }
        int skip=1;
        for(char ch:data){
            if(ch==' ') break;
            number=number*10+(ch-'0');
            skip++;
        }
        data=data.substr(skip,data.length()-skip);
        return neg*number;
    }
    TreeNode* deserialize(string data) {
        if(data[0]=='N') return NULL;
        TreeNode* head=new TreeNode(getNumber(data),NULL,NULL);
        queue<TreeNode*> que;
        que.push(head);
        while(!que.empty() && data.length()>0){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* temp=que.front();
                que.pop();
                int number=getNumber(data);
                if(data.length()>0 && number!=1001){
                    temp->left=new TreeNode(number,NULL,NULL);
                    que.push(temp->left);
                }
                number=getNumber(data);
                if(data.length()>0 && number!=1001){
                    temp->right=new TreeNode(number,NULL,NULL);
                    que.push(temp->right);
                }
            }
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));