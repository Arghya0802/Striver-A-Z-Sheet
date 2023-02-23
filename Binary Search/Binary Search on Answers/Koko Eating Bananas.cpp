// LeetCode: https://leetcode.com/problems/koko-eating-bananas/
// GFG: https://practice.geeksforgeeks.org/problems/koko-eating-bananas/1

class Solution {
private:

bool isPossible(long long int maxSpeed , int hours , vector<int> &piles)
{
    int n = piles.size() ;

    int cnt = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        if(piles[i] <= maxSpeed)
            cnt++ ;

        else
        {
            if(piles[i] % maxSpeed == 0)
                cnt += piles[i] / maxSpeed ;

            else 
                cnt += (piles[i] / maxSpeed) + 1 ;
        }
    }

    return cnt <= hours ;
}

public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int n = piles.size() ;

        long long int totalPiles = 0 ;

        for(int i = 0 ; i < n ; i++)
        {
            totalPiles += piles[i] ;
        }

        long long int low  = 1 ;
        long long int high = totalPiles ;

        long long int ans = -1 ;

        while(low <= high)
        {
            long long int mid = low + (high - low) / 2 ;

            if(isPossible(mid , h , piles) == true)
            {
                ans = mid ;

                high = mid - 1 ;
            }

            else
                low = mid + 1 ;
        }

        return ans ;   
    }
};

// Time Complexity:  O(N * LogN)
// Space Complexity: O(1)
