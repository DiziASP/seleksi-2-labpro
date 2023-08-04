#include <bits/stdc++.h>

using namespace std;

void addEdges(unordered_map<int, unordered_set<int>> &adj, int u, int v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}

void dfs(unordered_map<int, unordered_set<int>> &adj, vector<bool> &visited, int u, int parent, bool &isCyclic)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(adj, visited, v, u, isCyclic);
        
        if (v != parent)
            isCyclic = true;
    }
}

pair<int, int> findCircles(const vector<int> &arr, int n)
{
    unordered_map<int, unordered_set<int>> adj_list;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++)
        /* Create Graph for representing connection between Node 1..N */
        addEdges(adj_list, i, arr[i]);

    /* Debugging : Print adjacency List */
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int j : adj_list[i])
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    
    /* Initial Value of Circles Pair*/
    int max_circle = 0;
    int total_cycle = 0;

    for (int i = 1; i <= n; i++)
    {
        /* Check if there is a cycle in the graph */
        if(!visited[i])
        {
            bool isCyclic = false;
            dfs(adj_list, visited, i, -1, isCyclic);
            

            if(isCyclic)
            {
                total_cycle++;
            }
            max_circle++;
        }
    }

    /* If there is no cycle, then minimum circle is 1*/
    int min_circle;

    if(total_cycle == 0)
        min_circle = 1;
    else{
        /* If there is a cycle, then minimum circle is total_cycle */
        min_circle = max_circle - total_cycle;
    }

    return make_pair(min_circle, max_circle);
    
}

int main()
{
    int N;
    cin >> N;

    vector<int> arr(N+1);

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }

    pair<int, int> result = findCircles(arr, N);
    cout << "Minimum Circle: " << result.first << "\nMaximum Circle: " << result.second << endl;

    return 0;
}
