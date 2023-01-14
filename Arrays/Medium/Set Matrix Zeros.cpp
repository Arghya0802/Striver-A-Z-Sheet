// Link: https://leetcode.com/problems/set-matrix-zeroes/description/

// Look for all the values whose cells which have value zero and store them inside a queue
// We can keep a track of the rows and columns we have already visited using a RowCheck[] and ColCheck[] vectors respectively

class Solution {
private:

void setRowZeros(int currCol , vector<vector<int>> &matrix) // We create a seperate function to set all the elements of that row as zero
{
    int m = matrix.size() ;

    for(int row = 0 ; row < m ; row++)
        matrix[row][currCol] = 0 ;

    return ;
}

void setColumnZeros(int currRow , vector<vector<int>> &matrix) // Similarly, we create a seperate function to mark all the elements of that row as zero
{
    int n = matrix[0].size() ;

    for(int col = 0 ; col < n ; col++)
        matrix[currRow][col] = 0 ;

    return ;
}

public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        queue<pair<int , int>> q ; // We use a queue to keep track of all the Rows & Columns whose cell has 0 value

        for(int row = 0 ; row < m ; row++)
        {
            for(int col = 0 ; col < n ; col++)
            {
                if(matrix[row][col] == 0)
                    q.push({row , col}) ;
            }
        }
        
        // RowCheck[] and ColCheck[] arrays are used to keep track of the rows and columns we have visited till now
        
        vector<int> rowCheck(m , 0) ;
        vector<int> colCheck(n , 0) ;

        while(q.empty() == false)
        {
            int currRow = q.front().first ;
            int currCol = q.front().second ;
            q.pop() ;

            // setMatrixZeros(currRow , currCol , matrix) ;

            if(!rowCheck[currRow]) // If we haven't yet visited the Current-Row, we can call SetColumnZeros() function
            {
                setColumnZeros(currRow , matrix) ;

                rowCheck[currRow] = 1 ; // Simultaneously, we mark the Row as visited
            }

            if(!colCheck[currCol]) // If we haven't yet visited the Current-Col, we can call setRowZeros() function
            {
                setRowZeros(currCol , matrix) ;

                colCheck[currCol] = 1 ; // And we mark the Column as visited
            }
        }

        return ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M + N) [Queue + RowCheck and ColCheck vectors respectively add upto to our external space]
