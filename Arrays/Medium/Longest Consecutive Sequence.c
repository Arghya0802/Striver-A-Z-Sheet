// LeetCode: https://leetcode.com/problems/longest-consecutive-sequence/description/
// GFG: https://practice.geeksforgeeks.org/problems/longest-consecutive-subsequence2449/1

class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size() ;

        if(n == 0)
            return 0 ;
        
        unordered_set<int> set ;

        for(int i = 0 ; i < n ; i++)
        {
            int val = nums[i] ;

            set.insert(val) ;
        }

        int maxCnt = 1 ;

        for(int i = 0 ; i < n ; i++)
        {
            int val = nums[i] ;

            if(set.find(val - 1) == set.end() )
            {
                int cnt = 1 ;

                while(!set.empty() && set.find(val + 1) != set.end() )
                {
                    cnt++ ;

                    set.erase(val + 1) ;

                    val += 1 ;
                }

                maxCnt = max(maxCnt , cnt) ;
            }
        }
        
        return maxCnt ;
    }   
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
