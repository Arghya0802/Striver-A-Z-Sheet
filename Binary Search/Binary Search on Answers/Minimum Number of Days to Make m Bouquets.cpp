// LeetCode: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
// GFG: https://practice.geeksforgeeks.org/problems/minimum-days-to-make-m-bouquets/1?page=1&sortBy=accuracy&query=page1sortByaccuracy

class Solution {
    private:
    
    bool isPossible(long long int maxDays , int k , int noOfBouquets , vector<int> &bloomDay)
    {
        int cnt = 0 ;
        int totalCnt = 0 ;
        
        for(int days : bloomDay)
        {
            if(days <= maxDays)
                cnt += 1 ;
                
            else
                cnt = 0 ;
                
            if(cnt == k)
            {
                totalCnt += 1 ;
                
                cnt = 0 ;
            }
            
        }
        
        return totalCnt >= noOfBouquets ; 
    }
    
    public:
    int solve(int m , int k ,  vector<int> &bloomDay)
    {
        long long int totalFlowersReq = m * k ;
        
        if(totalFlowersReq > bloomDay.size() )
            return -1 ;
        
        int minElement = INT_MAX ;
        
        long long int totalDays = 0 ;
        
        for(int days : bloomDay)
        {
            minElement = min(minElement , days) ;
            
            totalDays += days ;
        }
        
        long long int low  = minElement ;
        long long int high = totalDays ;
        
        long long int ans = -1 ;
        
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;
            
            if(isPossible(mid , k , m , bloomDay) == true)
            {
                ans = mid ;
                
                high = mid - 1 ;
            }
            
            else
                low = mid + 1 ;
        }
        
        return (int) ans ;
    }
};

// Time Complexity:  O(N * Log S) [S is the sum of all array elements]
// Space Complexity: O(1)
