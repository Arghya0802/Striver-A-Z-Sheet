// Link: https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

class Solution
{
    private:
    
    Node *reverseLinkedList(Node *head)
    {
        Node *curr = head ;
        Node *prev = NULL ;
        Node *last = NULL ;
        
        while(curr != NULL)
        {
            last = prev ;
            prev = curr ;
            curr = curr -> next ;
            
            prev -> next = last ;
        }
        
        return prev ;
    }
    
    public:
    Node* addOne(Node *head) 
    {
        Node *reversed = reverseLinkedList(head) ;
        
        Node *p = reversed ;
        
        Node *dummy = new Node(-1) ;
        Node *tail = dummy ;
        
        int carry = 1 ;
        
        while(p != NULL || carry > 0)
        {
            int sum = carry ;
            
            if(p != NULL)
                sum += p -> data ;
            
            carry = sum / 10 ;
            
            Node *newNode = new Node(sum % 10) ;
            
            tail -> next = newNode ;
            tail = newNode ;
            
            if(p != NULL)
                p = p -> next ;
        }
        
        return reverseLinkedList(dummy -> next) ;
    }
};

// Time Complexity:  O(N)
// Space Complexity: O(N)
