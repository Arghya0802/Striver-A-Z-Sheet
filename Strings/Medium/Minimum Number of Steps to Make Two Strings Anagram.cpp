// Link: https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/description/

// The question looks very difficult on the outlook but is very simple
// We have to change characters from T such that T and S become Anagarm of each other
// This can be acheived by changing the characters which appear in S but not in T
// Even if they appear, freqS > freqT for that particular character
// We keep adding such differences in our ans variable and in the end return ans
class Solution {
public:
    int minSteps(string &s, string &t) 
    {
        vector<int> freqS(26 , 0) ; // Stores the Frequency of each character in S
        vector<int> freqT(26 , 0) ; // Stores the Frequency of each character in T

        int n = s.size() ;
        
        // We calculate the Frequency Array of S and T respecitvely
      
        for(int i = 0 ; i < n ; i++)
        {
            char ch = s[i] ;

            int index = (int) (ch - 'a') ;

            freqS[index] += 1 ;
        }

        for(int i = 0 ; i < n ; i++)
        {
            char ch = t[i] ;

            int index = (int) (ch - 'a') ;

            freqT[index] += 1 ;
        }

        int ans = 0 ;

        for(int i = 0 ; i < 26 ; i++)
        {
            if(freqS[i] == 0)
                continue ;
            
            // We only consider count of those characters of S whose frequency is greater than or equal to count of same character in T
            if(freqS[i] >= freqT[i])
                ans += freqS[i] - freqT[i] ;
        }

        return ans ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
