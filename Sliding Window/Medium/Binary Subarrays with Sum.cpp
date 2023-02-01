// LeetCode: https://leetcode.com/problems/binary-subarrays-with-sum/description/
// GFG: https://practice.geeksforgeeks.org/problems/binary-subarray-with-sum/1

class Solution {
private:

int countGoodSubarrays(vector<int> &nums , int k)
{
    int n = nums.size() ;

    int totalCnt = 0 ;
    
    int sum = 0 ;
    int end = 0 ;

    for(int start = 0 ; start < n ; start++)
    {
        sum += nums[start] ;

        while( (end <= start) && (sum > k) )
        {
            sum -= nums[end] ;

            end++ ;
        }

        totalCnt += (start - end + 1) ;
    }

    return totalCnt ;
}

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) 
    {
        int ans1 = countGoodSubarrays(nums , goal) ;
        int ans2 = countGoodSubarrays(nums , goal - 1) ;

        return (ans1 - ans2) ;      
    }
};

// Tome Complexity:  O(2 * N)
// Space Complexity: O(1)
