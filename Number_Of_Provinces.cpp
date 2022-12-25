// LeetCode: https://leetcode.com/problems/number-of-provinces/
// GFG: https://practice.geeksforgeeks.org/problems/number-of-provinces/1

class Solution {
private:

// We are building the Adjancency List for every Node so that we can count the Number of Connected Components in the graph
void buildGraph(int n , vector<vector<int>> &mat , vector<int> adj[])
{
    for(int row = 0 ; row < n ; row++)
    {
        for(int col = 0 ; col < n ; col++)
        {
            if(mat[row][col] == 1 && row != col)
            {
                adj[row + 1].push_back(col + 1) ;
                
                adj[col + 1].push_back(row + 1) ;
            }
        }
    }

    return ;
}

// We can solve the question using both BFS and DFS Traversals
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
    int findCircleNum(vector<vector<int>>& isConnected) // isConnected[][] is given to us as Adjacency Matrix
    {
        int n = isConnected.size() ;

        vector<int> visited(n + 1 , 0) ;

        vector<int> adj[n + 1] ; // Stores our Adjacency List

        buildGraph(n , isConnected , adj) ;

        int ans = 0 ;
        
        // We run a traversal from all the vertices from (1 till N)
        for(int node = 1 ; node <= n ; node++)
        {
            if(visited[node] == 0) 
            {
                // bfs(node , visited , adj) ;

                dfs(node , visited , adj) ;
                
                ans += 1 ; // Every time we traverse for a node, it means we have came acroos a Connected Component of the graph
            }
        }

        return ans ;
    }
};

// Time Complexity:  O(M * N)
// Space Complexity: O(M * N)
