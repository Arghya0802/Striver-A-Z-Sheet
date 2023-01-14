// Link: https://leetcode.com/problems/set-matrix-zeroes/description/

// Look for all the values whose cells which have value zero and store them inside a queue

class Solution {
private:

void setMatrixZeros(int currRow , int currCol , vector<vector<int>> &matrix)
{
    int m = matrix.size() ;
    int n = matrix[0].size() ;

    for(int row = 0 ; row < m ; row++)
        matrix[row][currCol] = 0 ;


    for(int col = 0 ; col < n ; col++)
        matrix[currRow][col] = 0 ;
    
    return ;
}

public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        queue<pair<int , int>> q ;    

        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(matrix[row][col] == 0)
                    q.push({row , col}) ;
            }
        }

        while(q.empty() == false)
        {
            int currRow = q.front().first ;
            int currCol = q.front().second ;
            q.pop() ;

            setMatrixZeros(currRow , currCol , matrix) ;
        }

        return ;
    }
};

// TIme Complexity:  O(M * N * K) [Considering the cell has K elements whose value is zero]
// Space Complexity: O(1)
