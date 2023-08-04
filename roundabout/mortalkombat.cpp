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

        for(auto i : adj[v]){
            if(!visited[i]){
                visited[i] = true;
                tracker.push(i);
            }
        }
    }
}

void addEdges(unordered_map<int, vector<int>> &adj, int src, int dest)
{
    adj[src].push_back(dest);
    adj[dest].push_back(src);
}


int main()
{
    int vertices, edges, K;
    cin >> vertices >> edges >> K;

    unordered_map<int, vector<int>> adj_list;

    for(int i = 1; i <= edges; i++){
        int u, v;
        cin >> u >> v;

        addEdges(adj_list, u, v);
    }

    

    return 0;
}