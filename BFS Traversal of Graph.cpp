// Link: https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// For BFS Traversal, we visit all the Neighbors of a Node level-wise
vector<int> bfsOfGraph(int V, vector<int> adj[]) 
{
        vector<int> visited(V , 0) ; // Visited[] array is always required in any Graph Traversal
        
        vector<int> ans ; // Will store our final BFS Traversal[]
        
        queue<int> q ; // Queue Data Struture is required to perfrom BFS
        
        q.push(0) ; // We push the our First Vertex(0) inside our Queue
        
        while(q.empty() == false) // We keep on traversing until my Queue doesn't become empty
        {
            int node = q.front() ; // We take the Front Element from the Queue
            q.pop() ;
            
            if(visited[node] == 1) // If that Node / Vertex is already visited, we move on
                continue ;
              
            visited[node] = 1 ; // Otherwise we mark that Node / Vertex as visited inside our Visited[] array
            ans.push_back(node) ; // We push that node into our ans[] vector
            
            for(int neigh : adj[node]) // We visit all it's Neighbors and push them inside our Queue using the Adjacency List given to us
                q.push(neigh) ;
        }
        
        return ans ;
}

// Time Complexity:  O(V + E) [ V -> Number of Vertices or Nodes ; E -> Number of Edges]
// Space Complexity: O(V) [The Queue Data Structure we are using]
