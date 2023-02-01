// LeetCode: https://leetcode.com/problems/merge-intervals/description/
// GFG: https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size() ;

        sort(intervals.begin() , intervals.end() ) ;

        int start = intervals[0][0] ;
        int end = intervals[0][1] ;
        
        vector<vector<int>> ans ;
    
        for(int i = 1 ; i < n ; i++)
        {
            int newStart = intervals[i][0] ;
            int newEnd = intervals[i][1] ;

            if(newStart >= start && newStart <= end)
            {
                start = min(start , newStart) ;
                end = max(end , newEnd) ;
            }

            else
            {
                ans.push_back( {start , end} ) ;

                start = newStart ;

                end = newEnd ;
            }

        }

        ans.push_back( {start , end} ) ;

        return ans ;    
    }
};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N) [For ans[][] vector]
