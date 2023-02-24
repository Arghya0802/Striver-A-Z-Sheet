// Link: https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string &s) 
    { 
        string ans = "" ;
        string wd = "" ;
        
        s += '.' ;
        
        int n = s.size() ;
        
        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;
            
            if(ch != '.')
                wd += ch ;
                
            else
            {
                if(i < n - 1)
                    ans = '.' + wd + ans ;
                
                else
                    ans = wd + ans ;
                    
                wd = "" ;
            }
        }
        
        // ans.pop_back() ;
        
        return ans ;
    } 
};

// Time Complexity:  O(N)
// Space Complexity: O(N) [For ans string]
