// Link: https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// DFS Traversal simply means recursive way of traversing all the nodes / vertices of a graph

// Recursive Function which traverses all the Nodes in the Graph
void dfs(int node , vector<int> &visited , vector<int> adj[] , vector<int> &ans)
{
    if(visited[node] == 1) // If a Node is already visited, we simply return back
        return ;
        
    visited[node] = 1 ; // Otherwise, we mark the Node as Visited
    
    ans.push_back(node) ; // We push that Node into our ans[] vector
    
    for(int neigh : adj[node]) // We visit all it's neighbors using the Adjacency List
        dfs(neigh , visited , adj , ans) ; // We must remember we are TRAVERSING DEPTH WISE 
        
    return ;
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) 
{
        vector<int> visited(V , 0) ;
    
        vector<int> ans ;
    
        dfs(0 , visited , adj , ans) ;
    
        return ans ;
}

// Time Complexity:  O(V + E) [ V --> Number of Vertices / Nodes ; E --> Number of Edges]
// Space Complexity: O(V)
