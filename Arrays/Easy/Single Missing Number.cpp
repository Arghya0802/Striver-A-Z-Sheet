// Link : https://leetcode.com/problems/single-number/description/

// As we know XOR of two equal values will always be 0, so we use XOR to find the Single Missing Number
// XOR is applicable because all other elements occur exactly twice except one.
// In any other scenario, we need to use other solutions

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
