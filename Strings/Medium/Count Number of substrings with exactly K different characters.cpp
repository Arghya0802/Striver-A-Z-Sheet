// Link: https://practice.geeksforgeeks.org/problems/count-number-of-substrings4528/1

class Solution
{
    private:
    
    long long int countGoodSubstrings(string &s , int k)
    {
        int n = s.size() ;
        
        vector<int> freq(26 , 0) ;
        
        int index = 0 ;
        int disCnt = 0 ;
        int end = 0 ;
        
        long long int totalCnt = 0 ;
        
        for(int start = 0 ; start < n ; start++)
        {
            char newAccept = s[start] ;
            
            index = (int) (newAccept - 'a') ;
            
            if(freq[index] == 0)
                disCnt += 1 ;
                
            freq[index] += 1 ;
            
            while( (end <= start) && disCnt > k)
            {
                char discard = s[end] ;
                
                index = (int) (discard - 'a') ;
                
                freq[index] -= 1 ;
                
                if(freq[index] == 0)
                    disCnt-- ;
                    
                end++ ;
            }
            
            totalCnt += start - end + 1 ;
        }
        
        return totalCnt ;
    }
    
    public:
    long long int substrCount (string &s , int k) 
    {
        long long int ans1 = countGoodSubstrings(s , k - 1) ;
        long long int ans2 = countGoodSubstrings(s , k) ;
        
        return ans2 - ans1 ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
