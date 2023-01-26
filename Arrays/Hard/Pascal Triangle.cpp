// LeetCode: https://leetcode.com/problems/pascals-triangle/description/
// GFG: https://practice.geeksforgeeks.org/problems/pascal-triangle0652/1

// Both GFG and LeetCode have a bit different - LeetCode asks us to return the entire Pascal Triangle in the form of a 2D vector
// GFG asks us to return the LastRow only and since it's constraints are a bit higher we need to take MOD of every value

class Solution 
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans ; // We declare our ans[][]

        ans.push_back({1}) ; // First Row contains only 1

        if(numRows == 1)
            return ans ;

        ans.push_back({1,1}) ; // Second Row contains (1,1)
        
        // Our logic runs for rows >= 2 till rows < numRows 
      
        for(int row = 2 ; row < numRows ; row++)
        {
            // We need prevRow and its size to calculate CurrentRow
          
            vector<int> prev = ans[row - 1] ;
            int n = prev.size() ;

            vector<int> currRow(n + 1) ; // CurrentRow[] will always have one element more than prevRow[]

            currRow[0] = prev[0] ; // First Element will always be same for both prevRow[] and currentRow[]

            for(int i = 0 ; i < n - 1 ; i++) // Loop runs from i = 0 till N - 1 [N is the size of prevRow[] vector]
                currRow[i + 1] = prev[i] + prev[i + 1] ; // currRow[i + 1] is equal to sum of prevRow[i] and prevRow[i + 1]

            currRow[n] = prev[n - 1] ; // Last element of prevRow[n - 1] and currentRow[n] are same 
            
            ans.push_back(currRow) ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N ^ 2)
// Space Complexity: O(N ^ 2)
