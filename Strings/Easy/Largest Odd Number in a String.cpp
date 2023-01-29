// LeetCode: https://leetcode.com/problems/largest-odd-number-in-string/description/
// GFG: https://practice.geeksforgeeks.org/problems/largest-odd-number-in-string/1

// The idea is very simple - make the entire string and whenever we find a odd value we store it in our ans variable
// This helps us to keep track of the Largest Odd Number we have visited till now
// We traverse from left to right -  we can do the other way round as well

class Solution {
public:
    string largestOddNumber(string &num) 
    {
        string maxOddNumber = "" ;

        string totalNumber = "" ;

        for(char ch : num)
        {
            int val = (int) (ch - '0') ;

            totalNumber += ch ;

            if(val % 2 == 1)
                maxOddNumber = totalNumber ;
        }

        return maxOddNumber ;
    }
};

// Time Complexity:  O(N)
// Space COmplexity: O(N) [For maxOddNumber string ]
