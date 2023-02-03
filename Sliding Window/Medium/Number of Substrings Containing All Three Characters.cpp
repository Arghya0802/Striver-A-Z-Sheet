// LeetCode: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
// GFG: https://practice.geeksforgeeks.org/problems/count-substring/1?page=1&sortBy=newest&query=page1sortBynewest

class Solution {
public:
    int numberOfSubstrings(string &s) 
    {
        long long int n = s.size() ;

        int cntA = 0 ;
        int cntB = 0 ;
        int cntC = 0 ;

        int end = 0 ;
        
        long long int totalCnt = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            if(s[start] == 'a')
                cntA++ ;

            else if(s[start] == 'b')
                cntB++ ;

            else
                cntC++ ;

            while( (end <= start) && (cntA >= 1 && cntB >= 1 && cntC >= 1) )
            {
                if(s[end] == 'a')
                    cntA-- ;

                else if(s[end] == 'b')
                    cntB-- ;

                else
                    cntC-- ;

                end++ ;
            }

            totalCnt += (start - end + 1) ;
        }

        long long int totalSubArrays = (n * (n + 1) ) / 2 ;

        return totalSubArrays - totalCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
