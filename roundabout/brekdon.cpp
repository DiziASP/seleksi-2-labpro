#include <bits/stdc++.h>
using namespace std;

/**
 * Depth First Search
 */
void dfs(int v, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{
    visited[v] = true;

    for (auto i : adj[v])
    {
        if (!visited[i])
        {
            dfs(i, visited, adj);
        }
    }
}

void addEdges(unordered_map<int, vector<int>> &adj, int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}

int totalConnectedComponents(unordered_map<int, vector<int>> &adj, int vertices)
{
    vector<bool> visited(vertices + 1, false);

    int count = 0;

    for (int v = 1; v <= vertices; v++)
    {
        if (!visited[v])
        {
            dfs(v, visited, adj);
            count++;
        }
    }

    return count;
}

int main()
{
    int vertices, edges, K;
    cin >> vertices >> edges >> K;

    unordered_map<int, vector<int>> adj_list;

    for(int i = 0; i < edges; i++){
        int src, dest;
        cin >> src >> dest;

        addEdges(adj_list, src, dest);
    }

    /* Find maximum total edges that can be removed so the total component will be maximum */
    int initialComponents = totalConnectedComponents(adj_list, vertices);
    return 0;
}