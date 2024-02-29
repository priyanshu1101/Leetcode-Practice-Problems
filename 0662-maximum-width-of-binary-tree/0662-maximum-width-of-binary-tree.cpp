/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root)
            return 0;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (!q.empty()) {
            int size = q.size();
            int start, end;
            int mmin = q.front().second;
            for (int j = 0; j < size; j++) {
                long long i = q.front().second - mmin;
                TreeNode* temp = q.front().first;
                q.pop();
                if (j == 0)
                    start = i;
                if (j == size - 1)
                    end = i;
                if (temp->left)
                    q.push({temp->left, i * 2 + 1});
                if (temp->right)
                    q.push({temp->right, (i * 2) + 2});
            }
            maxWidth = max(maxWidth, end - start + 1);
        }
        return maxWidth;
    }
};