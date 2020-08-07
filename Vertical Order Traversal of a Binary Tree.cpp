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
    map <int,vector<pair<int,int> > > omap;
    void vertical(TreeNode* root,int X,int Y)
    {
        if(!root) return;
        
        omap[X].push_back(make_pair(-Y,root->val));
        vertical(root->left,X-1,Y-1);
        vertical(root->right,X+1,Y-1);
        
    }
    //main function
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        int X=0;
        int Y=0;
        vector<vector<int>> final_out;
        vertical(root,X,Y);
        for( auto temp:omap)
        {
            sort(temp.second.begin(),temp.second.end());
            vector<int> out;
            for(auto val:temp.second)
            {
                out.push_back(val.second);
            }
            
            final_out.push_back(out);
        }
        return final_out;
        
    }
};
