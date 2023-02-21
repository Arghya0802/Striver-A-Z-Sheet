// Link: https://practice.geeksforgeeks.org/problems/rotation4723/1

// Similar to finding the Minimum Number in a Sorted and Rotated Array
// Instead of finding the Minimum Element, we will just find the index of that Minimum Element
// That will indicate how many times the array has been rotated

class Solution{
private:

int minimum_in_sorted_rotated_array(int nums[] , int n)
{
    int low  = 0 ;
    int high = n - 1 ;
    
    while(low <= high)
    {
        int mid = low + (high - low) / 2 ;
        
        if(mid == 0)
        {
            if(nums[mid] < nums[mid + 1])
                return mid ;
                
            else
                return mid + 1 ;
        }
        
        else if(mid == n - 1)
        {
            if(nums[mid] < nums[mid - 1])
                return mid ;
                
            else
                return mid - 1 ;
        }
        
        else if(nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1])
            return mid ;
            
        else if(nums[low] > nums[mid])
            high = mid - 1 ;
            
        else if(nums[mid] > nums[high])
            low = mid + 1 ;
            
        else if(nums[low] <= nums[mid] && nums[mid] <= nums[high])
            high = mid - 1 ;
            
        else
            low = mid + 1 ;
    }
    
    return -1 ;
}

public:	
	int findKRotation(int arr[], int n) 
	{
	    if(n == 1)
	        return 0 ;
	        
	    int minIndex = minimum_in_sorted_rotated_array(arr , n) ;
	    
	    return (minIndex - 0) ;
	}

};

// Time Complexity:  O(Log N)
// Space Complexity: O(1)
