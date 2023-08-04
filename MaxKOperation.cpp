#include <bits/stdc++.h>

using namespace std;

/* Global Variables */
unordered_map<int, unordered_set<int>> adj_list;
int currentTrav = 0;

/* Functions */
void dfs(int u, vector<int> &visited, vector<int> &low, vector<int> &parent, int& bridges){
    visited[u] = low[u] = currentTrav;
    currentTrav++;

    for (int node : adj_list[u])
    {
        if(visited[node] == -1){
            parent[node] = u;
            dfs(node, visited, low, parent, bridges);
            low[u] = min(low[u], low[node]);
            if(low[node] > visited[u])
                bridges++;
        }
        else if(node != parent[u])
            low[u] = min(low[u], visited[node]);     
    }
}

int totalBridges(int vertices, int edges){
    int bridges = 0;
    vector<int> visited(vertices + 1, -1), low(vertices + 1, -1), parent(vertices + 1, -1);

    for (int i = 1; i <= vertices; i++)
    {
        if(visited[i] == -1){
            dfs(i, visited, low, parent, bridges);
        }
    }

    return bridges;
}

int main()
{
    int N,M,K;
    cin >> N >> M >> K;

    for (int i = 1; i <= M; i++){
        int u,v;
        cin >> u >> v;
        adj_list[u].insert(v);
        adj_list[v].insert(u);
    }

    vector<bool> visited(N + 1, false);

    /* Find the number of bridges */
    int bridges = totalBridges(N, M);

    /* Find total edge that can be removed so the current graph bridge = K */

    cout << max(0, bridges-K) << endl;

    return 0;
}