// LeetCode: https://leetcode.com/problems/is-graph-bipartite/description/
// GFG: https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// I have solved the question using both BFS and DFS traversals - any traversal you like would work just fine
// Make sure to use (0 or 1) coloring as then it will be very easy to toggle between Current-Color and New-Color
// Also, remember that the graph can have multiple connected components, so we need to start a traversal from all the nodes[0-based indexing]

class Solution {
private:

bool bfs(int source , vector<int> &visited , vector<vector<int>> &graph)
{
    queue<pair<int , int>> q ;

    q.push( {source , 1} ) ; // We push the (source , 1) inside the queue [Initial Color doesn't matter at all - choose 0 or 1]

    visited[source] = 1 ; // We mark the source with the Initial Color

    while(q.empty() == false)
    {
        // Take our the Current-Node and the Color associated with it
      
        int node  = q.front().first  ;
        int color = q.front().second ;
        q.pop() ;

        int newColor = !color ; // New-Color can be easily found out by !color

        for(int neigh : graph[node]) // Visit all it's neighbors using the Adjacency List given to us
        {
            if(visited[neigh] == -1) // If it's neighbor is yet not visited
            {
                visited[neigh] = newColor ; // Mark it as visited with the newColor

                q.push( {neigh , newColor} ) ; // Put it inside the queue
            }

            else if(visited[neigh] == color)  // If the Neighbor Node is marked with the same color of the Current Node
                return false ; // We directly return false
        }
    }

    return true ; // At the end, if we could successfully divide all the nodes into 2 seperate groups, we return true
}

// The DFS Code will look exactly similar as the BFS traversal ; the only difference being DFS goes Depth-wise instead of going Level or Step Wise
  
bool dfs(int node , int color , vector<int> &visited , vector<vector<int>> &graph)
{
    visited[node] = color ; // We mark the Current Node with the given Color

    int newColor = !color ; // New-Color will be !oldColor

    for(int neigh : graph[node]) // Traverse all the Neighbors
    {
        if(visited[neigh] == -1) // Still Not marked, call DFS() function
        {
            if(dfs(neigh , newColor , visited , graph) == false) // If DFS() returns false at any call, it means the division into 2-sets is not possible
                return false ; // So we also directly return false
        }

        else if(visited[neigh] == color) // If the Neighbor Node is visited with the Same Color of the Current Node, we should return false
            return false ;
    }

    return true ; // At the end, if we could divide all the neighbors into 2 Subsequent Sets, we return true
}

public:
    bool isBipartite(vector<vector<int>>& graph) 
    {
        // Graph is equal to adjacency list

        int n = graph.size() ;
        
        vector<int> visited(n , -1) ; // We use -1 in the visited array instead of our normal 0
        
        // Due to Multiple Connected Components, we need to run BFS / DFS from all the Nodes / Vertices
      
        for(int node = 0 ; node < n ; node++)
        {
            if(visited[node] == -1) // We ccall the traversal technique whenever we find any node as Not-Visited
            {
                // If any call returns us a false value, we should directly return false
              
                // if(bfs(node , visited , graph) == false)
                //     return false ;

                if(dfs(node , 0 , visited , graph) == false)
                    return false ;
            }
        }
        
        return true ; // Otherwise, we could divide them into 2-groups such that no group contain subsequent neighbors, so we return true
    }
};

// Time Complexity:  O(V + 2E) [V: Nodes ; E: Edges: 2E: Total Degree in an Undirected Graph]
// Space Complexity: O(V) [Visited Array ; Queue / Recursive Stack Space]
