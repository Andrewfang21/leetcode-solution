/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int pathSum(TreeNode* node, int &curr) {
        if (node == NULL)
            return 0;
        
        int left = pathSum(node -> left, curr);
        int right = pathSum(node -> right, curr);
        int sum = max(max(left, right) + node -> val, node -> val);
        curr = max(sum, max(curr, left + right + node -> val));
        
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        pathSum(root, res);
        
        return res;
    }   
};
