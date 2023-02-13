// Link: https://practice.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

// We need to alter the links of 0,1 and 2. We can do it in O(1) Space
// If a LinkedList contains only 0 or 1 or 2. We directly return the head as there's no point in sorting

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) 
    {
        if(head == NULL || head -> next == NULL)
            return head ;
         
        Node *zeroStart = new Node(-1) ;
        Node *zero = zeroStart ;
        
        Node *oneStart = new Node(-2) ;
        Node *one = oneStart ;
        
        Node *twoStart = new Node(-3) ;
        Node *two = twoStart ;
        
        Node *p = head ;
        
        int totalCnt = 0 ;
        int cnt0 = 0 ;
        int cnt1 = 0 ;
        int cnt2 = 0 ;
        
        while(p != NULL)
        {
            totalCnt++ ;
            
            if(p -> data == 0)
            {
                cnt0++ ;
                zero -> next = p ;
                zero = p ;
            }
            
            else if(p -> data == 1)
            {
                cnt1++ ;
                one -> next = p ;
                one = p ;
            }
            
            else
            {
                cnt2++ ;
                two -> next = p ;
                two = p ;
            }
            
            p = p -> next ;
        }
         
        if(totalCnt == cnt0 || totalCnt == cnt1 || totalCnt == cnt2)
            return head ;
        
        if(cnt0 > 0 && cnt1 > 0 && cnt2 > 0)
        {
            zero -> next = oneStart -> next ;
            one -> next = twoStart -> next ;
            
            two -> next = NULL ;
            
            return zeroStart -> next ;
        }
        
        else if(cnt0 > 0 && cnt1 > 0 && cnt2 == 0)
        {
            zero -> next = oneStart -> next ;
            one -> next = NULL ;
            
            return zeroStart -> next ;
        }
        
        else if(cnt0 > 0 && cnt1 == 0 && cnt2 > 0)
        {
            zero -> next = twoStart -> next ;
            two -> next = NULL ;
            
            return zeroStart -> next ;
        }
        
        else if(cnt0 == 0 && cnt1 > 0 && cnt2 > 0)
        {
            one -> next = twoStart -> next ;
            two -> next = NULL ;
            
            return oneStart -> next ;
        }
        
        // else if(cnt0 > 0 && cnt1 == 0 && cnt2 == 0)
        // {
        //     zero -> next = NULL ;
            
        //     return zeroStart -> next ;
        // }
        
        // else if(cnt0 == 0 && cnt1 > 0 && cnt2 == 0)
        // {
        //     one -> next = NULL ;
            
        //     return oneStart -> next ;
        // }
        
        // else
        // {
        //     two -> next = NULL ;
            
        //     return twoStart -> next ;
        // }
        
        return NULL ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
