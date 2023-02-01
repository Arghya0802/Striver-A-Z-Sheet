// Link :https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
private:

int buyAndSell(int currIndex , int n , int canBuy , int transCount , vector<int> &prices , vector<vector<vector<int>>> &dp)
{
    if(transCount == 1)
        return 0 ;
        
    if(currIndex >= n)
        return 0 ;
    
    if(dp[currIndex][canBuy][transCount] != -1)
        return dp[currIndex][canBuy][transCount] ;

    int ans = 0 ;

    if(canBuy == 1)
    {
        int idle = buyAndSell(currIndex + 1 , n , canBuy , transCount , prices , dp) ;

        int buy = buyAndSell(currIndex + 1 , n , !canBuy , transCount , prices , dp) - prices[currIndex] ;

        ans = max(idle , buy) ;
    }

    else
    {
        int idle = buyAndSell(currIndex + 1 , n , canBuy , transCount , prices , dp) ;

        int sell = buyAndSell(currIndex + 1 , n , !canBuy , transCount + 1 , prices , dp) + prices[currIndex] ;

        ans = max(idle , sell) ;
    }

    return dp[currIndex][canBuy][transCount] = ans ;
}

public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size() ;

        vector<vector<vector<int>>> dp(n + 1 , vector<vector<int>> (2 , vector<int> (2 , -1) ) ) ;

        int ans = buyAndSell(0 , n , 1 , 0 , prices , dp) ;

        return ans ;    
    }
};

// Time Complexity:  O(N * 2 * 2) [TransCount = 1 ; CanBuy = 1 ]
// Space Complexity: O(N * 2 * 2) [TransCount = 1 ; CanBuy = 1 ]
