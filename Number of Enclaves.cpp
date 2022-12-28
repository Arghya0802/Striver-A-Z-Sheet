// GFG: https://practice.geeksforgeeks.org/problems/number-of-enclaves/1
// LeetCode: https://leetcode.com/problems/number-of-enclaves/description/

bool isValid(int row , int col , int m , int n , vector<vector<int>> &vis , vector<vector<int>> &grid)
{
    if(row < 0 || row >= m || col < 0 || col >= n) // (Row , Col) should be within the dimmensions of the matrix 
        return false ;
        
    if(grid[row][col] == 0) // Shouldn't be Sea 
        return false ;
        
    if(vis[row][col] == 1) // Shouldn't have been visited yet
        return false ;
        
    return true ;
}

// We could have used BFS as well but to ensure parity, I have used Multi-Source BFS in this question

void bfs(queue<pair<int , int>> &q , vector<vector<int>> &vis , vector<vector<int>> &grid)
{
    // As we are doing Multi-Source BFS, we already have our queue ready with pairs of (row , col)
  
    int m = grid.size() ;
    int n = grid[0].size() ;
    
    // X[] and Y[] arrays help us to travel in all 4-Directions
    int x[] = {-1 , +1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , +1} ;
    
    while(q.empty() == false)
    {
        int currRow = q.front().first ;
        int currCol = q.front().second ;
        q.pop() ;
        
        for(int i = 0 ; i < 4 ; i++)
        {
            int nRow = currRow + x[i] ;
            int nCol = currCol + y[i] ;
            
            if(isValid(nRow , nCol , m , n , vis , grid) == true) // We put (nRow , nCol) inside our queue only if they are valid
            {
                vis[nRow][nCol] = 1 ;
                
                q.push( {nRow , nCol} ) ;
            }
        }
        
    }
    
    return ;
}

int numberOfEnclaves(vector<vector<int>> &grid) 
{
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;
        
        queue<pair<int , int>> q ;
        
        int boundRows[] = {0 , m - 1} ;
        int boundCols[] = {0 , n - 1} ;
        
        // We traverse for First-Row and Last-Row seperately but they can be done at once
        for(int i = 0 ; i < 2 ; i++)
        {
            int row = boundRows[i] ;
            
            for(int col = 0 ; col < n ; col++)
            {
                if( (visited[row][col] == 0) && (grid[row][col] == 1) ) // We put only those cells which are land and hasn't yet been visted yet
                {
                    q.push( {row , col} ) ;
                    
                    visited[row][col] = 1 ;
                }
            }
        }
        
        // Similarly, we traverse for First Column and Last Column seperately but they can be done simultaneously
        for(int i = 0 ; i < 2 ; i++)
        {
            int col = boundCols[i] ;
            
            for(int row = 0 ; row < m ; row++)
            {
                if( (visited[row][col] == 0) && (grid[row][col] == 1) ) // We only put those cells which are land and hasn't been visited yet
                {
                    q.push( {row , col} ) ;
                    
                    visited[row][col] = 1 ;
                }
            }
        }
        
        bfs(q , visited , grid) ; // We traverse all the Connected Components using Multi-Source BFS
        
        int ans = 0 ;
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if((grid[row][col] == 1) && (visited[row][col] == 0) ) // At the end, the number of lands still remaining unvisited is our answer
                    ans += 1 ;
            }
        }
        
        return ans ;
}

// Time Complexity:  O(M * N * 4) [Due to travelling in all 4-directions]
// Space Complexity: O(M * N)
