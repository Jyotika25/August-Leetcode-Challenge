/*
Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).
*/

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
//helper function to count number of paths
    int pathSum_vdoutRoot(TreeNode *root , int sum){
        if(root == nullptr) return 0;
        
        int result = 0;
        
        if(root->val == sum)    result++;
        result += pathSum_vdoutRoot(root->left ,sum-root->val);
        result += pathSum_vdoutRoot(root->right ,sum-root->val);
        
        return result;
    }
    //given function template
    int pathSum(TreeNode* root, int sum) {
        if(root == nullptr) return 0;
        
        return pathSum(root->left,sum) + pathSum_vdoutRoot(root, sum) + pathSum(root->right , sum);
    }
};
