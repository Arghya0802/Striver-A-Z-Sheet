// GFG: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1
// LeetCode: https://leetcode.com/problems/01-matrix/description/

// Both the questions are slight variation of each other, I will be discussing GFG one

// IsValid() checks the validity of (row , col) like we have always done in BFS traversals

bool isValid(int row , int col , int m , int n , vector<vector<int>> &vis)
{
        if(row < 0 || row >= m || col < 0 || col >= n)
            return false ;
            
        if(vis[row][col] == 1)
            return false ;
            
        return true ;
}

vector<vector<int>>nearest(vector<vector<int>> &grid)
{
      // As we are trying to find the minDistance of any cell to a cell containing 1, we have to use BFS
      // This is because BFS ensures we travel to the same distance or steps at once[levelwise]
  
	    int m = grid.size() ;
	    int n = grid[0].size() ;
	    
	    vector<vector<int>> visited(m , vector<int> (n , 0) ) ;
	    vector<vector<int>> ans(m , vector<int> (n , -1) ) ;
	    
	    queue<pair<int , pair<int , int>> > q ; // Queue stores (distance , (row , cell) ) everytime
	    
      // We need to store all the cells which initally contain 1 as we generally do in a Multi-Source BFS
  
	    for(int row = 0 ; row < m ; row++)
	    {
	        for(int col = 0 ; col < n ; col++)
	        {
	            if(grid[row][col] == 1)
	            {
	                q.push( {0 , {row , col} } ) ;
	                visited[row][col] = 1 ; // We simultaneously mark the Cells as visited
	            }
	        }
	    }
	    
      // We travel in Up, Down, Left, Right directions from any cell
	    int x[] = {-1 , 1 , 0 , 0} ;
	    int y[] = {0 , 0 , -1 , 1} ;
	    
	    while(q.empty() == false)
	    {
	        int dist = q.front().first ;
	        int currRow = q.front().second.first ;
	        int currCol = q.front().second.second ;
	        q.pop() ;
	        
	        ans[currRow][currCol] = dist ; // We update our ans[][] matrix with the Current-Distance
	        
	        for(int i = 0 ; i < 4 ; i++)
	        {
	            int nRow = currRow + x[i] ;
	            int nCol = currCol + y[i] ;
	            
	            if(isValid(nRow , nCol , m , n , visited) == true) // If (New-Row , New-Col) is valid and is not visited before we put it inside our queue
	            {
	                q.push( {dist + 1 , {nRow , nCol} } ) ; // Since this is at the Next Level or Step, we put (Dist + 1 ) into our Queue
	                
	                visited[nRow][nCol] = 1 ;
	            }
	        }
	    }
	    
	    return ans ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
