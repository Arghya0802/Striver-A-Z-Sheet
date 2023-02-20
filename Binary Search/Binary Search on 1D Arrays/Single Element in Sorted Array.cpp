// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/description/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size() ;

        if(n == 1)
            return nums[0] ;
        
        int low  = 0 ;
        int high = n - 1 ;

        while(low <= high)
        {
            int mid = low + (high - low) / 2 ;

            if(mid == n - 1)
            {
                if(nums[mid] != nums[mid - 1])
                    return nums[mid] ;

                else
                    high = mid - 1 ;
            }

            else if(mid == 0)
            {
                if(nums[mid] != nums[mid + 1])
                    return nums[mid] ;

                else
                    low = mid + 1 ;
            }

            else if(nums[mid] == nums[mid - 1])
            {
                int leftSide  = mid - low - 1 ;
                int rightSide = high - mid ;

                if(leftSide % 2 == 1)
                    high = mid - 2 ;

                else
                    low = mid + 1 ;
            }

            else if(nums[mid] == nums[mid + 1])
            {
                int leftSide  = mid - low ;
                int rightSide = high - mid - 1 ;

                if(rightSide % 2 == 1)
                    low = mid + 2 ;

                else
                    high = mid - 1 ;
            }

            else
                return nums[mid] ;
        }

        return -1 ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
