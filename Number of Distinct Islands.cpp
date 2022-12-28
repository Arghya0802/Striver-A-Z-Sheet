// GFG: https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1
// LeetCode: Premimum question

// The only catch in the question is how we can keep track of the Different types of Islands we are visitng
// We can do so by keeping track of the (startRow , startCol) and the difference between (currRow - startRow, currCol - startCol) and storing them inside a vector
// We can use a set<vector<pair<int , int>> > st to keep track of such patterns and at the end we return the size of the set

// Although BFS and DFS both should work, BFS somehow isn't working so we should use DFS() for this particular problem
void dfs(int currRow , int currCol , int startRow , int startCol , int m , int n , vector<vector<int>> &vis , vector<vector<int>> &grid , vector<pair<int , int>> &vec)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) // (Row , Col) should be within the boundaries of the Matrix
        return ;
        
    if(grid[currRow][currCol] == 0) // We need neighboring Lands not Sea
        return ;
        
    if(vis[currRow][currCol] == 1) // We should visit a cell only once
        return ;
    
    vis[currRow][currCol] = 1 ; // We mark the cell as visited
    
    // (dRow , dCol) will serve as the difference between Current-Cell and the Starting Cell
    // If we have encountered any such pattern before, our set will store only a copy of it
  
    int dRow = currRow - startRow ;
    int dCol = currCol - startCol ;
    
    vec.push_back( {dRow , dCol} ) ; // We put (dRow , dCol) into our vector
    
    int x[] = {-1 , +1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , +1} ;
    
    for(int i = 0 ; i < 4 ; i++)
    {
        int nRow = currRow + x[i] ;
        int nCol = currCol + y[i] ;
        
        dfs(nRow , nCol , startRow , startCol , m , n , vis , grid , vec) ;
    }
    
    return ;
}

int countDistinctIslands(vector<vector<int>>& grid) 
{
        int m = grid.size() ;
        int n = grid[0].size() ;
        
        vector<vector<int>> visited(m , vector<int> (n , 0) ) ; // Visited[][] matrix
        
        // unordered_set<pair<int , int>> set ;
        
        // unordered_set<vector<pair<int , int>> > q ;
        
        // set<pair< pair<int , int> , vector<pair<int , int>>> > set ;
        
        // set<vector<pair<int , int>> > set ;
        
        set<vector<pair<int , int >> > st ; // Our Set will store a vector<pair<int , int>> 
        
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                // Whenever we encounter any land which has not been visited yet, we run our DFS() algorithm
              
                if( (grid[row][col] == 1) && (visited[row][col] == 0) )
                {
                    vector<pair<int , int>> vec ;
                    
                    // BFS(row , col , m , n , visited , grid , vec) ;
                    
                    dfs(row , col , row , col , m , n , visited , grid , vec) ;
                    
                    st.insert(vec) ;
                }
                
            }
        }
        
        return st.size() ;
 }

// Time Complexity:  O(M * N Log(M * N)) [We are using a set which uses an extra O(Log N) Time ]
// Space Complexity: O(M * N)
