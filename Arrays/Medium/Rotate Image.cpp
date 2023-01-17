// Link: https://leetcode.com/problems/rotate-image/description/

// To Rotate the Matrix by 90 degrees, we have to do 2 things:-
// a) Transpose the given matrix
// b) Reverse every row
// In this way we can get our Matrix Rotated by 90 Degrees

class Solution {
private:

void reverseEveryRow(vector<int> &nums) // This function is used to reverse the Rows of the given matrix
{
    int low = 0 ;
    int high = nums.size() - 1 ;

    while(low <= high)
    {
        swap(nums[low] , nums[high]) ;

        low += 1 ;

        high -= 1 ;
    }

    return ;
}

public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int m = matrix.size() ;
        int n = matrix[0].size() ;

        // Transpose the matrix
        for(int row = 0 ; row < m ; row++)
        {
            for(int col = row ; col < n ; col++) // To tranpose the matrix, we use this logic and swap the corresponding elements
            {
                swap(matrix[row][col] , matrix[col][row]) ;
            }
        }
        
        // Lastly, we reverse Every Row to Rotate our Matrix by 90 degrees
        for(int row = 0 ; row < m ; row++)
            reverseEveryRow(matrix[row]) ;
      
        return ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(1) [We do the Rotation of Matrix in place ]
