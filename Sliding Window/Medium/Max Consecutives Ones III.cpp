// LeetCode: https://leetcode.com/problems/max-consecutive-ones-iii/description/
// GFG: https://practice.geeksforgeeks.org/problems/maximum-consecutive-ones/1

// Classic Sliding Window question of Variable Size Length
// Our invalid condition will be when our cnt becomes greater than K

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n = nums.size() ;

        int ans = 0 ; // Stores the Length of the Longest Subarray containing all 1s by flipping atmost K 0s
        int end = 0 ; // End pointer stays at the end and helps in releasing elements

        int cnt = 0 ; // Keeps track of the number of 0s we have flipped till now

        for(int start = 0 ; start < n ; start++) // Start pointer traverses over the entire array nums[]
        {
            if(nums[start] == 0) // If we encounter 0, we increment cnt by 1
                cnt++ ;

            while( (end <= start) && (cnt > k) ) // If the number of 0s flipped becomes greater than K, we have come across an invalid window so we need to release elements
            {
                if(nums[end] == 0) // If nums[end] is 0, we decrement cnt by 1
                    cnt-- ;

                end++ ; // End moves by 1 after each iteration
            }

            int currLen = start - end + 1 ; // The Length of Current valid Subarray can be calculated by (start - end + 1)

            ans = max(ans , currLen) ; // We store the maximum length inside our ans variable
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
