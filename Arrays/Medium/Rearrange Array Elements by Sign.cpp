// LeetCode: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
// GFG: https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) 
    {
        int n = nums.size() ;

        vector<int> APos ;
        vector<int> BNeg ;

        for(int val : nums)
        {
            if(val >= 0)
                APos.push_back(val) ;

            else
                BNeg.push_back(val) ;
        }


        int indA = 0 ;
        int indB = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            if(i % 2 == 0)
            {
                nums[i] = APos[indA] ;
                indA++ ;
            }

            else
            {
                nums[i] = BNeg[indB] ;
                indB++ ;
            }
        }

        return nums ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N) 
