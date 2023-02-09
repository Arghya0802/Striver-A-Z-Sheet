// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/description/

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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans ;    

        if(root == NULL)
            return ans ;

        queue<TreeNode *> q ;

        q.push(root) ;

        while(!q.empty() )
        {
            int size = q.size() ;
            vector<int> level ;

            while(size--)
            {
                TreeNode *curr = q.front() ;
                q.pop() ;

                level.push_back(curr -> val) ;

                if(curr -> left != NULL)
                    q.push(curr -> left) ;

                if(curr -> right != NULL)
                    q.push(curr -> right) ;    
            }

            ans.push_back(level) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
