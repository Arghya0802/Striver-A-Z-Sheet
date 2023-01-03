// LeetCode:
// GFG:

class Solution {
private:

// This question can be solved by both types of Traversals - BFS & DFS
  
void dfs(int currRow , int currCol , int m , int n , int oldColor , int newColor , vector<vector<int>> &image)
{
    if(currRow < 0 || currRow >= m || currCol < 0 || currCol >= n) // If we reach on any Invalid Cell, we return back
        return ;

    if(image[currRow][currCol] != oldColor) // If Current Cell's color is not equal to source cells color, then also we return back
        return ;

    image[currRow][currCol] = newColor ; // We color the (row , col) with newColor
     
    // We travese in all 4-Directions using x[] and y[]
    int x[] = {-1 , 1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , 1} ;

    for(int i = 0 ; i < 4 ; i++)
        dfs(currRow + x[i] , currCol + y[i] , m , n , oldColor , newColor , image) ;
  
  return ;
}

// isValid() function is specifically for BFS Traversal only
  
bool isValid(int row , int col , int m , int n , int oldColor , vector<vector<int>> &image)
{
    if(row < 0 || row >= m || col < 0 || col >= n) // Likewise, it checks the coordinates (row , col) to be valid or not
        return false ;

    if(image[row][col] != oldColor) // Also, it returns false if Source Color don't match with Current Color 
        return false ;

    return true ;
}

void bfs(int startRow , int startCol , int m , int n , int oldColor , int newColor , vector<vector<int>> &image)
{
    queue<pair<int , int>> q ; // For BFS, we use a queue Data Structure and travel likewise in Normal BFS
    
    q.push( {startRow , startCol} ) ;
    image[startRow][startCol] = newColor ;

    int x[] = {-1 , 1 , 0 , 0} ;
    int y[] = {0 , 0 , -1 , 1} ;

    while(q.empty() == false)
    {
        int currRow = q.front().first ;
        int currCol = q.front().second ;
        q.pop() ;

        for(int i = 0 ; i < 4 ; i++)
        {
            int nRow = currRow + x[i] ;
            int nCol = currCol + y[i] ;

            if(isValid(nRow , nCol , m , n , oldColor , image) == true) // If isValid() returns true, we then mark the Cell with newColor
            {
                image[nRow][nCol] = newColor ;
                q.push({nRow , nCol}) ;
            }
        }

    }

    return ;
}

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size() ;
        int n = image[0].size() ;

        int oldColor = image[sr][sc] ;
        
        if(oldColor == color)
            return image ;

        // dfs(sr , sc , m , n , oldColor , color , image) ;
        
        bfs(sr , sc , m , n , oldColor , color , image) ;
        
        return image ; // At the end, we return image[] matrix modified with newColors from (sr , sc)
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
