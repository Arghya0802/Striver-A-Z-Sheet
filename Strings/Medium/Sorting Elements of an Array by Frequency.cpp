// Link: https://practice.geeksforgeeks.org/problems/sorting-elements-of-an-array-by-frequency/0

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

static bool cmp(pair<int , int> &A , pair<int , int> &B)
{
    if(A.second > B.second)
        return true ;
        
    else if(A.second == B.second && A.first < B.first)
        return true ;
        
    else
        return false ;
}

vector<int> Sort_Array_Frequency(vector<int> &nums , int n)
{
    unordered_map<int , int> map ;
    
    for(int val : nums)
        map[val] += 1 ;
        
    vector<pair<int , int>> vec ;
    
    for(auto &x : map)
    {
        int val = x.first  ;
        int freq = x.second ;
        
        vec.push_back( {val , freq} ) ;
    }
    
    sort(vec.begin() , vec.end() , cmp) ;
    
    vector<int> ans ;
    
    for(pair<int , int> &curr : vec)
    {
        int val  = curr.first  ;
        int freq = curr.second ;
        
        while(freq--)
            ans.push_back(val) ;
    }
        
    return ans ;
}

int main()
{
	int t ;
	cin >> t ;
	
	while(t--)
	{
	    int n ;
	    cin >> n ;
	    
	    vector<int> nums(n) ;
	    
	    for(int i = 0 ; i < n ; i++)
	        cin >> nums[i] ;
	        
	    vector<int> ans = Sort_Array_Frequency(nums , n) ;
	    
	    for(int i = 0 ; i < n ; i++)
	        cout << ans[i] << " " ;
	        
	    cout << endl ;
	}
	
	return 0;
}

// Time Complexity:  O(N * Log N)
// Space Complexity: O(N)
