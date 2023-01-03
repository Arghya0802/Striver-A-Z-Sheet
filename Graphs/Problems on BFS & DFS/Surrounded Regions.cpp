// LeetCode: https://leetcode.com/problems/surrounded-regions/description/
// GFG: https://practice.geeksforgeeks.org/problems/replace-os-with-xs0052/1

// In DFS Traversal, make sure to mark the nodes as visited or else it will result in Stack Overflow
class Solution {
private:

void dfs(int currRow , int currCol , int m , int n , vector<vector<int>> &vis , vector<vector<char>> &board)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) // Coordinates should be valid
        return ;

    if(vis[currRow][currCol] == 1) // We shouldn't have visited the cell before
        return ;

    if(board[currRow][currCol] == 'X') // The Cell should contain 'O' 
        return ;

    vis[currRow][currCol] = 1 ; // We mark the Cell as visited
    
    // We travel in all 4-directions using X[] and Y[] arrays
  
    int x[] = {-1 , 1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , 1} ;

    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = currRow + x[i] ;
        int nCol = currCol + y[i] ;

        dfs(nRow , nCol , m , n , vis , board) ;

    }

    return ;    
}

public:
    // The only catch in the question is that we need to find out the Connected Components of 'O' starting from boundaries and not from everywhere
  
    void solve(vector<vector<char>>& board) 
    {
        int m = board.size() ;
        int n = board[0].size() ;
        
        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;

        for(int col = 0 ; col < n ; col++)
        {
            if(board[0][col] == 'O' && visited[0][col] == 0) // First Row Check
                dfs(0 , col , m , n , visited , board) ;
            
            if(board[m - 1][col] == 'O' && visited[m - 1][col] == 0) // Last Row Check
                dfs(m - 1 , col , m , n , visited , board) ;
        }

        for(int row = 0 ; row < m ; row++) 
        {
            if(board[row][0] == 'O' && visited[row][0] == 0) // First Column Check
                dfs(row , 0 , m , n , visited , board) ;

            if(board[row][n - 1] == 'O' && visited[row][n - 1] == 0) // Last Column Check
                dfs(row , n - 1 , m , n , visited , board) ;
        }
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(visited[row][col] == 0 && board[row][col] == 'O') // At the end, if we have found any cell still unvisited and contains 'O' we mark them with 'X'
                    board[row][col] = 'X' ;
            }
        }

        return ;    
    }
};

// Time Complexity:  O(M * N * 4) [We travel in all 4-directions everytime]
// Space Complexity: O(M * N) [Visited array + Recursive Stack Space]
