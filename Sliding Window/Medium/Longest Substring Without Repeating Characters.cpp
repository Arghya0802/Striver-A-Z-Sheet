// LeetCode: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// GFG: https://practice.geeksforgeeks.org/problems/length-of-the-longest-substring3036/1

class Solution {
public:
    int lengthOfLongestSubstring(string &s) 
    {
        int n = s.size() ;

        unordered_map<char , int> map ;

        int cnt = 0 ;
        int end = 0 ;
        int ans = 0 ;

        for(int start = 0 ; start < n ; start++)
        {
            char current = s[start] ;
            map[current] += 1 ;
            
            cnt = map[current] ;

            while( (end <= start) && (cnt > 1) )
            {
                char discard = s[end] ;

                map[discard] -= 1 ;

                cnt = map[current] ;

                if(map[discard] == 0)
                    map.erase(discard) ;

                end++ ;
            }

            int currLen = start - end + 1 ;

            ans = max(ans , currLen) ;
        }

        return ans ;
    }
};

// For GFG question, we need to use Frequency Array of size 26 as all the characters are in LowerCase 
// For LeetCode problem, we have English Letters Digits and Special Characters thats why we need to use Map

// Time Complexity:  O(N)
// Space Complexity: O(N)
