// Link: https://practice.geeksforgeeks.org/problems/the-painters-partition-problem1535/1

class Solution
{
    private:
    
    bool isPossible(long long int maxCapacity , int noOfPainters , int n , int arr[])
    {
        long long int currCapacity = 0 ;
        
        int cnt = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(currCapacity + arr[i] <= maxCapacity)
                currCapacity += arr[i] ;
                
            else
            {
                cnt += 1 ;
                
                currCapacity = arr[i] ;
            }
        }
        
        if(currCapacity <= maxCapacity)
            cnt += 1 ;
            
        return cnt <= noOfPainters ;
    }
    
    public:
    long long minTime(int arr[] , int n , int k)
    {
        long long int totalArea = 0 ;
        int maxBoard = 0 ;
        
        for(int i = 0 ; i < n ; i++)
        {
            totalArea += arr[i] ;
            
            maxBoard = max(maxBoard , arr[i]) ;
        }
            
        long long int low  = maxBoard  ;
        long long int high = totalArea ;
        
        long long int ans = -1 ;
        
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;
            
            if(isPossible(mid , k , n , arr) == true)
            {
                ans = mid ;
                
                high = mid - 1 ;
            }
            
            else
                low = mid + 1 ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(N * Log K) [K is the search space between maxVal in arr[] and sum of all elements of arr[] ]
// Space Complexity: O(1)
