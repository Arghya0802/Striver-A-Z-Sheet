// Link: https://leetcode.com/problems/search-insert-position/description/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int n = nums.size() ;

        int low  = 0 ;    
        int high = n - 1 ;

        int ans = -1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(nums[mid] == target)
                return mid ;

            else if(nums[mid] > target)
            {
                ans = mid ;

                high = mid - 1 ;
            }

            else   
                low = mid + 1 ;
        }

        return ans == -1 ? n : ans ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
