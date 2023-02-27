// Link: https://leetcode.com/problems/maximum-erasure-value/description/

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) 
    {
        int n = nums.size() ;

        unordered_map<int , int> map ;

        int end = 0 ;
        int ans = 0 ;

        int cntSum = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            int newAccept = nums[start] ;

            map[newAccept] += 1 ;

            int cnt = map[newAccept] ;

            cntSum += newAccept ;

            while( (end <= start) && cnt > 1)
            {
                int discard = nums[end] ;
                map[discard] -= 1 ;

                cntSum -= discard ;

                if(discard == newAccept)
                    cnt -= 1 ;

                if(map[discard] == 0)
                    map.erase(discard) ;

                end++ ;
            }

            ans = max(ans , cntSum) ;
        }    

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
