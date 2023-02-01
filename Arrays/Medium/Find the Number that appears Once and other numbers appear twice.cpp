// LeetCode: https://leetcode.com/problems/single-number/description/
// GFG: https://practice.geeksforgeeks.org/problems/element-appearing-once2552/1

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int XOR = 0 ;

        for(int val : nums)
            XOR ^= val ;

        return XOR ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
