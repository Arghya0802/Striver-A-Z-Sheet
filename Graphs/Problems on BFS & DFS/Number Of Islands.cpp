// LeetCode: https://leetcode.com/problems/number-of-islands/
// GFG: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

// Just like The Number Of Provinces question, here also we need to find the Connected Components in the graph
// Here, Neighbors are defined as the Lands we can reach in all the 8-Directions from (i,j) provided (i,j) is also a piece of Land

// Both DFS and BFS traversals will work for this problem
void dfs(int currRow , int currCol , int m , int n , vector<vector<int>> &visited , vector<vector<char>> &mat)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
        return ;
        
    if(mat[currRow][currCol] == '0')
        return ;
        
    if(visited[currRow][currCol] == 1)
        return ;
        
    visited[currRow][currCol] = 1 ;
    
    int x[] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1} ;
    int y[] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1} ;
    
    for(int i = 0 ; i < 8 ; i++)
    {
        int dx = x[i] ;
        int dy = y[i] ;
        
        dfs(currRow + dx , currCol + dy , m , n , visited , mat) ;
    }
    
    return ;
}


void bfs(int row , int col , int m , int n , vector<vector<int>> &visited , vector<vector<char>> &mat)
{
    queue<pair<int , int>> q ;
    
    q.push( {row , col} ) ;
    
    int x[] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1} ;
    int y[] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1} ;
    
    while(q.empty() == false)
    {
        int currRow = q.front().first  ;
        int currCol = q.front().second ;
        q.pop() ;
        
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
            continue ;
            
        if(visited[currRow][currCol] == 1)
            continue ;
            
        if(mat[currRow][currCol] == '0')
            continue ;
            
        visited[currRow][currCol] = 1 ;
        
        for(int i = 0 ; i < 8 ; i++)
        {
            int newRow = currRow + x[i] ;
            int newCol = currCol + y[i] ;
            
            // if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n)
            q.push( {newRow , newCol} ) ;
        }
        
    }
    
    return ;
}

int numIslands(vector<vector<char>>& grid) 
{
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        vector<vector<int>> visited(m , vector<int> (n , 0) ) ;
        
        int ans = 0 ;
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(grid[row][col] == '0')
                    continue ;
                    
                // We run our Graph Traversals technique whenever we encounter any piece of land which is not visited yet
              
                if(visited[row][col] == 1 )
                    continue ;
                    
                // dfs(row , col , m , n , visited , grid) ;
                
                bfs(row , col , m , n , visited , grid) ;
                
                ans += 1 ;
                
            }
        }
        
        return ans ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
