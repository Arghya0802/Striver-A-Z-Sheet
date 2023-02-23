// GFG: https://practice.geeksforgeeks.org/problems/square-root/1

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long int low  = 1 ;
        long long int high = x ;
        long long int ans = 0 ;
        
        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;
            
            if(mid * mid == x)
                return mid ;
                
            else if(mid * mid < x)
            {
                ans = mid ;
                
                low = mid + 1 ;
            }
                
            else
                high = mid - 1 ;
        }
        
        return ans ;
    }
};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
