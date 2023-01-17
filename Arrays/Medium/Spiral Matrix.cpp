// Link: https://leetcode.com/problems/spiral-matrix/description/

// The idea is very simple - we need to move in this manner:
// a) Left to Right in startRow
// b) Top to Down in startCol
// c) Right to Left in endRow
// d) Down to Top in startCol
// After every iteration, we need to increment the values of (startRow, startCol) by 1 and decrement the values of (endRow , endCol) by 1 respectively
// We need to break whenever our count becomes equal to (M * N)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        int total = m * n ;
        int cnt = 0 ;

        vector<int> ans(total) ;

        int startRow = 0 ; // startRow is initally set as 0
        int endRow = m - 1 ; // endRow is intially set as Last Row

        int startCol = 0 ; // startCol is initally set as 0
        int endCol = n - 1 ; // endCol is initally set as Last Col

        while(cnt < total)
        {
            for(int col = startCol ; col <= endCol ; col++) // We first traverse over startRow
            {
                if(cnt == total)
                    break ;

                ans[cnt] = matrix[startRow][col] ;
                cnt += 1 ;
            }

            startRow += 1 ; // Increment startRow by 1

            for(int row = startRow ; row <= endRow ; row++) // Next we traverse over endCol
            {
                if(cnt == total)
                    break ;

                ans[cnt] = matrix[row][endCol] ;
                cnt += 1 ;
            }

            endCol -= 1 ; // Decrement endCol by 1

            for(int col = endCol ; col >= startCol ; col--) // Next we traverse over endRow
            {
                if(cnt == total)
                    break ;

                ans[cnt] = matrix[endRow][col] ;
                cnt += 1 ;
            }

            endRow -= 1 ; // Decrement endRow by 1

            for(int row = endRow ; row >= startRow ; row--) // Lastly, we traverse over startCol
            {
                if(cnt == total)
                    break ;

                ans[cnt] = matrix[row][startCol] ;
                cnt += 1 ;
            }

            startCol += 1 ; // Increment startCol by 1
        }

        return ans ;
    }
};

// Time Complexity:  O(M * N) 
// Space Complexity: I(M * N) [ Our ans[][] vector takes M * N ]
