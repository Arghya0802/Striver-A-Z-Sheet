// Link: https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1

// The problem asks us to return all the Number of Connected Components in a Graph
// We can solve this using either DFS or BFS Traversals

// Recursive function to traverse any connected component at once
void dfs(int currRow , int currCol , int m , int n , vector<vector<int>> &visited , vector<vector<char>> &mat)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) // We first need to check whether it's an Valid Index or not
        return ;
        
    if(mat[currRow][currCol] == '0') // Then we need to check if that Part is covered with Land or Water
        return ;
        
    if(visited[currRow][currCol] == 1) // Lastly, we need to ensure that we shouldn't visit an already visited Land
        return ;
        
    visited[currRow][currCol] = 1 ; // We mark it as visited
    
    // X[] and Y[] arrays help us to traverse in all 8-Directions
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

// Simlar to DFS, we can use BFS Traversal as well
void bfs(int row , int col , int m , int n , vector<vector<int>> &visited , vector<vector<char>> &mat)
{
    queue<pair<int , int>> q ; // We need to use a Queue that's the differnece
    
    q.push( {row , col} ) ;
    
    int x[] = {-1 , 1 , 0 , 0 , -1 , -1 , 1 , 1} ;
    int y[] = {0 , 0 , -1 , 1 , -1 , 1 , -1 , 1} ;
    
    while(q.empty() == false)
    {
        int currRow = q.front().first  ;
        int currCol = q.front().second ;
        q.pop() ;
        
        // We check whether Row and Col Indices are valid or not
        if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n)
            continue ;
            
        // We then check if we have already visited this cell or not
        if(visited[currRow][currCol] == 1)
            continue ;
            
        // Lastly, we check if it's an Land or Water
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
                    
                if(visited[row][col] == 1 )
                    continue ;
                    
                // Everytime BFS or DFS Traversals are called, it signals that we have encountered one more connected component in the graph
              
                // dfs(row , col , m , n , visited , grid) ;
                
                bfs(row , col , m , n , visited , grid) ;
                
                ans += 1 ; // That's why we increment ans by 1
                
            }
        }
        
        return ans ;
}

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
