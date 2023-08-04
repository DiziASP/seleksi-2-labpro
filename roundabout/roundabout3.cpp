#include <bits/stdc++.h>

using namespace std;

void dfs(unordered_map<int, unordered_set<int>> &adj, vector<bool> &visited, int u, int parent, bool &isCyclic)
{
    visited[u] = true;

    for (int v : adj[u])
    {
        if (!visited[v])
            dfs(adj, visited, v, u, isCyclic);

        if (v != parent){
            isCyclic = true;
        }  
    }
}

void addEdges(unordered_map<int, unordered_set<int>> &adj, int u, int v)
{
    adj[u].insert(v);
    adj[v].insert(u);
}

pair<int,int> findCircles(const vector<int> &arr, int n){

    /* Initial Value */
    int min_circle = 0, max_circle = 0;

    unordered_map<int, unordered_set<int>> adj_list;
    vector<bool> visited(n + 1, false);

    for (int i = 1; i <= n; i++){
        /* Create Graph for representing connection between Node 1..N */
        addEdges(adj_list, i, arr[i]);
    }

    /* Debugging : Print adjacency List */
    for (int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for (int j : adj_list[i])
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    /** Maximum Circle is the total of Connected Components
     * Minimum Circle is the total of Connected Components - total of Connected Components that is not a cycle
     */
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

    /* If total Connected Components that is a cycle equal to total connected components, then its already a full circle */
    cout << "Total Cycle : " << total_cycle << endl;
    if(total_cycle == max_circle){
        min_circle = max_circle;
    }
    else if(total_cycle == 0){/* If there is no cycle, minimum is 1, maximum is the total components*/
        min_circle = 1;
        max_circle = max_circle;
    }    
    
    /* Else, the minimum circle is the total of cycle + 1 */
    else{
        min_circle = total_cycle + 1;
    }
        

    return make_pair(min_circle, max_circle);
}

int main(){
    int N;
    cin >> N;

    vector<int> arr(N + 1);

    for (int i = 1; i <= N; i++)
        cin >> arr[i];
    
    pair<int, int> ans = findCircles(arr, N);

    cout << ans.first << " " << ans.second << endl;
}