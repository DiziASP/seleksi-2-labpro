#include <bits/stdc++.h>
using namespace std;

/**
 * Depth First Search
 */
void dfs(int v, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
{
    stack<int> tracker;
    tracker.push(v);

    while (!tracker.empty())
    {
        v = tracker.top();
        tracker.pop();

        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                tracker.push(i);
            }
        }
    }
}

void dfs2(int v, vector<bool> &visited, unordered_map<int, vector<int>> &adj)
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

/**
 * Find connected components
 */
int totalConnectedComponent(unordered_map<int, vector<int>> &adj, int vertices)
{
    vector<bool> visited(vertices + 1, false);

    int count = 0;

    for (int v = 1; v <= vertices; v++)
    {
        if (!visited[v])
        {
            dfs2(v, visited, adj);
            count++;
        }
    }

    return count;
}

void maxRemovedEdge(unordered_map<int, vector<int>> &adj, int vertices, int edges, int totalConnectedComponents)
{
    int CC = 0;

    vector<bool> visited(vertices + 1, false);

    for (int u = 1; u <= vertices; u++)
    {

        if (!visited[u])
        {
            CC++;
            dfs(u, visited, adj);

            if (CC <= totalConnectedComponents)
            {
                cout << edges - (vertices + totalConnectedComponents) << endl;
            }
        }
    }
}

int main()
{
    int vertices = 4, edges = 3, maxK = 2;
    cin >> vertices >> edges >> maxK;

    unordered_map<int, vector<int>> adj_list;

    for (int i = 1; i <= edges; i++)
    {
        int u, v;
        cin >> u >> v;

        addEdges(adj_list, u, v);
    }

    // /* Find maximum total edges that can be removed so the total component will be maximum */
    int initialComponents = totalConnectedComponent(adj_list, vertices);
    cout << "total: " << initialComponents << endl;
    maxRemovedEdge(adj_list, vertices, edges, initialComponents + maxK + 1);
    return 0;
}