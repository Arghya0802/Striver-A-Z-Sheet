// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans ;

        if(root == NULL)
            return ans ;

        int noOflevels = 0 ;

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

                if(curr -> left)
                    q.push(curr -> left) ;

                if(curr -> right)
                    q.push(curr -> right) ;
            }

            if(noOflevels % 2 == 1)
                reverse(level.begin() , level.end() ) ;

            ans.push_back(level) ;

            noOflevels++ ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
