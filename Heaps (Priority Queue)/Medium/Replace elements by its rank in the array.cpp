// Link: https://practice.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int n)
    {
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>> > minHeap ;
        
        for(int i = 0 ; i < n ; i++)
        {
            int val = arr[i] ;
            
            minHeap.push( {val , i} ) ;
        }
            
        vector<int> ans(n , -1) ;
        
        int rank = 0  ;
        int prev = -1 ;
        
        while(!minHeap.empty() )
        {
            int val   = minHeap.top().first  ;
            int index = minHeap.top().second ;
            minHeap.pop() ;
            
            if(val == prev)
                ans[index] = rank ;
                
            else
            {
                rank++ ;
                
                ans[index] = rank ;
                
                prev = val ;
            }
        }
        
        return ans ;

    }

};

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N) [For the answer array or vector]
