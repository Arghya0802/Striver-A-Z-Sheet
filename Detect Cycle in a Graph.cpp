// Link: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Both BFS and DFS Traversals will work in this problem

bool BFS(int source , vector<int> &vis , vector<int> adj[])
{
    queue<pair<int , int>> q ; // Our queue will always contain (Node , Parent)
    
    q.push( {source , -1} ) ; // Initial Node has No Parent that's why -1
    vis[source] = 1 ; // We mark the Source Node as visited
    
    while(q.empty() == false)
    {
        int size = q.size() ;
        
        for(int i = 0 ; i < size ; i++)
        {
            int node = q.front().first ;
            int parent = q.front().second ;
            q.pop() ;
            
            for(int neigh : adj[node]) // We traverse on the neighbors of the Current Node using Adjacency List
            {
                if(vis[neigh] == 0) // If it's not visited, we visit the Neighbor and put it into the queue
                {
                    vis[neigh] = 1 ;
                    q.push( {neigh , node} ) ;
                }
                
                else if(parent != neigh) // Else if it's Marked as visited but it's not Parent Node, it means we have cycle in our graph
                    return true ;
            }
        }
    }
    
    return false ;
}

// Similar to BFS, we need to have Current Node as well as Parent into our DFS() function

bool dfs(int node , int parent , vector<int> &vis , vector<int> adj[]) 
{
    vis[node] = 1 ; // We mark the Current Node as visited 
    
    bool ans = false ; // Will store the final ans by taking with OR with DFS() calls
    
    for(int neigh : adj[node])
    { 
        // If the Neighbor is not visited, we visit it and call our DFS function
        if(vis[neigh] == 0)
            ans = ans || dfs(neigh , node , vis , adj) ;
            
        else if(parent != neigh) // Else If it's already visited but Parent Node and Neighbor differs
            return true ; // It means we have encountered Cycle
    }
    
    return ans ;
}

// As the graph has multiple Connected Components, that's why need to run a DFS /  BFS for every Node / Vertex

bool isCycle(int V, vector<int> adj[]) 
{
        vector<int> visited(V , 0) ;
        
        for(int node = 0 ; node < V ; node++)
        {
            if(visited[node] == 0)
            {
                // bool check = BFS(node , visited , adj) ;
                
                bool check = dfs(node , -1 , visited , adj) ;
                if(check == true) // If any of the Traversals returns us true, it means the graph has cycles so we return true directly
                    return true ;
            }
        }
        
        return false ;
}

// Time Complexity:  O(N + 2E) [ N: Number of Vertices and E: Number of Edges ]
// Space Complexity: O(N) [ Recursive Stack Space for DFS and Queue Space for BFS ]
