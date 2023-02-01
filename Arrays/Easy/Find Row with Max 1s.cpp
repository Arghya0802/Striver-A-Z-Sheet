// GFG: https://practice.geeksforgeeks.org/problems/row-with-max-1s0023/1

class Solution{
private:

int findFirstPosition(int n , vector<int> &nums)
{
    int low = 0 ;
    int high = n - 1 ;
    
    int ans = -1 ;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;
        
        if(nums[mid] == 1)
        {
            ans = mid ;
            
            high = mid - 1 ;
        }
        
        else
            low = mid + 1 ;
    }
    
    return ans ;
}

public:
	int rowWithMax1s(vector<vector<int> > &arr, int m , int n) 
	{
	    int ansIndex = -1 ;
	    int maxCnt = 0 ;
	    
	    for(int row = 0 ; row < m ; row++)
	    {
	        int colIndex = findFirstPosition(n , arr[row]) ;
	        
	        int cnt = n - colIndex ;
	        
	        if(colIndex == -1)
	            cnt = 0 ;
	           
	       // cout << cnt << endl ;
	        
	        if(maxCnt < cnt)
	        {
	            maxCnt = cnt ;
	            
	            ansIndex = row ;
	        }
	    }
	    
	    return ansIndex ;
	}

};

// Time Complexity:  O(M * Log N)
// Space Complexity: O(1)
