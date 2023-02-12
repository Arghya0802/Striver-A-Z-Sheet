// Link: https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1

class Solution{
public:
    Node* divide(int N , Node *head)
    {
        if(head == NULL || head -> next == NULL)
            return head ;
            
        Node *evenHead = new Node(-2) ;
        Node *oddHead  = new Node(-1) ;
        
        Node *even = evenHead ;
        Node *odd  = oddHead ;
        
        Node *p = head ;
        
        while(p != NULL)
        {
            int val = p -> data ;
            
            if(val % 2 == 0)
            {
                even -> next = p ;
                even = p ;
            }
            
            else
            {
                odd -> next = p ;
                odd = p ;
            }
            
            p = p -> next ;
        }
        
        if(odd -> data != -1 && even -> data != -2)
        {
            even -> next = oddHead -> next ;
            odd -> next = NULL ;
            
            return evenHead -> next ;
        }
        
        else
        {
            if(odd -> data == -1)
            {
                even -> next = NULL ;
                
                return evenHead -> next ;
            }
            
            else if(even -> data == -2)
            {
                return oddHead -> next ;
            }
        }
        
        return NULL ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(1)
