// LeetCode: https://leetcode.com/problems/rotting-oranges/description/
// GFG: https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1

class Solution {
private:

// isValid() checks if (row , col) is valid
bool isValid(int row , int col , int m , int n , vector<vector<int>> &vis , vector<vector<int>> &grid)
{
    if(row < 0 || row >= m || col < 0 || col >= n) // Out of grid[][] 
        return false ;

    if(vis[row][col] == 1) // Already visited
        return false ;

    if(grid[row][col] == 0 || grid[row][col] == 2) // We need to visit only Fresh-Oranges, that is, grid[i][j] == 1
        return false ;

    return true ;
}

public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        // As we are tyring to find the Min-Time, we need to travel levelwise, that's why we are using BFS
        int m = grid.size() ;
        int n = grid[0].size() ;

        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;

        queue<pair<int , pair<int , int>> > q ; // Stores the (time , (row , col) ) 
        int freshOranges = 0 ; // Counts the Number of Fresh Oranges in the Grid originally
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == 1)
                    freshOranges += 1 ;

                if(grid[row][col] == 2)
                {
                    q.push( {0 , {row , col} } ) ; // This is the inital configuration of the grid[][], thus time = 0

                    visited[row][col] = 1 ; // We mark them as visited while putting them inside queue
                }
            }
        }

        int ans = 0 ; // Contains the Final Time we require
        int cnt = 0 ; // Counts the Number of Fresh Oranges we have rotten till now
        
        // Used for traversal in all 4-directions
        int x[] = {-1 , 1 , 0 , 0} ;
        int y[] = {0 , 0 , -1 , 1} ;

        while(q.empty() == false)
        {
            int time = q.front().first ;
            int currRow = q.front().second.first ;
            int currCol = q.front().second.second ;
            q.pop() ;

            ans = max(ans , time) ; // Ans will always be the maximum between (ans , currTime)
            
            // We travel in all 4-directions from current cell
            for(int i = 0 ; i < 4 ; i++)
            {
                int nRow = currRow + x[i] ;
                int nCol = currCol + y[i] ;
  
                if(isValid(nRow , nCol , m , n , visited , grid) == true) // If the (newRow , newCol) is valid and not previously visited
                {
                    // (Time + 1) siginifies it's at the next level or step from Current Cell
                  
                    q.push( {time + 1 , {nRow , nCol} } ) ; // We push (time + 1 , (nRow , nCol) ) inside our queue
                    
                    visited[nRow][nCol] = 1 ; // Mark the cell as visited

                    cnt += 1 ; // Increases our counter by 1
                }

            }
        }
        
        // Before returning, we need to ensure that all the Fresh Oranges have been rotten
        return freshOranges == cnt ? ans : -1 ; 
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)  
