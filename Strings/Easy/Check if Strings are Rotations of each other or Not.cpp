// GFG: https://practice.geeksforgeeks.org/problems/check-if-strings-are-rotations-of-each-other-or-not-1587115620/1
// LeetCode: https://leetcode.com/problems/rotate-string/

class Solution
{
    bool rotateString(string &s , string &target)
    {
        int n = target.size() ;
        
        int i = 0 ;
        int j = 0 ;
        
        while(i < n && j < n)
        {
            if(s[i] == target[j])
                j++ ;
                
            i++ ;
        }
        
        if(i == n && j == n)
            return true ;
        
        string subString = target.substr(j) ;
        
        for(int ind = 0 ; ind < subString.size() ; ind++)
        {
            if(s[ind] != subString[ind])
                return false ;
        }
        
        return true ;
    }
    
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1 ,string &s2)
    {
        if(s1.size() != s2.size() )
            return false ;
        
        bool checkS1 = rotateString(s1 , s2) ;
        
        if(checkS1 == true)
            return checkS1 ;
        
        bool checkS2 = rotateString(s2 , s1) ;
        
        return checkS2 ;
    }
};

// Time Complexity:  O(2 * N)
// Space Complexity: O(K) [To calculate subString string which we assume to have an average length of K]
