// LeetCode: https://leetcode.com/problems/number-of-provinces/description/
// GFG: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
private:

 // Count Of Provinces simply means we need to find the Number of Connected Components in a Graph
  
 // We first build the Adjacency List using the Adjacency Matrix[][] given to us
void buildGraph(int n , vector<vector<int>> &mat , vector<int> adj[])
{
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            // In an Adjancency Matrix[][], an edge is signified by 1[Non-Weighted Graph is given]
            if(mat[row][col] == 1 && row != col) // We must ensure that we are not putting (1 , 1) (2 , 2) etc as neighbors 
            {
                adj[row + 1].push_back(col + 1) ;
                
                adj[col + 1].push_back(row + 1) ;
            }
        }
    }

    return ;
}

// We can use either of BFS or DFS Traversal Techniques to Count the Number of Connected Components
void bfs(int start , vector<int> &visited , vector<int> adj[])
{
    queue<int> q ;

    q.push(start) ;

    while(q.empty() == false)
    {
        int node = q.front() ;
        q.pop() ;

        if(visited[node] == 1)
            continue ;

        visited[node] = 1 ;

        for(int neigh : adj[node])
            q.push(neigh) ;
    }

    return ;
}

// Both the Traversal Technique will give us the exact same result
void dfs(int node , vector<int> &visited , vector<int> adj[])
{
    if(visited[node] == 1)
        return ;

    visited[node] = 1 ;

    for(int neigh : adj[node])
        dfs(neigh , visited , adj) ;

    return ;
}

public:
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size() ;

        vector<int> visited(n + 1 , 0) ; // Helps us to keep track of the number of nodes we have already visited 

        vector<int> adj[n + 1] ;

        buildGraph(n , isConnected , adj) ;

        int ans = 0 ;
        
        // We need to run a BFS or DFS from every Node as the Graph is disjointed 
        for(int node = 1 ; node <= n ; node++)
        {
            if(visited[node] == 0) // Whenever we find any Node which is not visited, we run BFS or DFS
            {
                // bfs(node , visited , adj) ;

                dfs(node , visited , adj) ;
                
                ans += 1 ; // We also increment ans by 1, signifying we have found One Connected Component in the graph
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(V + E)
// Space Complexity: O(V * E)
