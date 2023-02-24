// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/description/

class Solution {
public:
    int maxDepth(string &s) 
    {
        int n = s.size() ;
        
        stack<char> st ;

        int maxCnt = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;

            if(ch >= '0' && ch <= '9')
                continue ;

            if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
                continue ;
            
            if(ch == '(')
                st.push('(') ;

            else
            {
                int size = st.size() ;

                maxCnt = max(maxCnt , size ) ;

                st.pop() ;
            }
        }

        return maxCnt ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
