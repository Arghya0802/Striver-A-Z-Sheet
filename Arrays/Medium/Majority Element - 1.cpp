// LeetCode: https://leetcode.com/problems/majority-element/description/
// GFG: https://practice.geeksforgeeks.org/problems/majority-element-1587115620/1

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int majorEle = 0 ;
        int cnt = 0 ;

        for(int val : nums)
        {
            if(cnt == 0)
                majorEle = val ;

            if(majorEle == val)
                cnt++ ;
            else
                cnt-- ;
        }

        int freqCnt = 0 ;

        for(int val : nums)
        {
            if(val == majorEle)
                freqCnt++ ;
        }

        int size = nums.size() ;

        if(freqCnt >= size / 2)
            return majorEle ;

        return -1 ;    
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
