#include <bits/stdc++.h>

using namespace std;

/* Functions for Graph */
void addEdge(unordered_map<int, unordered_set<int>> &adj_list, int u, int v)
{
    adj_list[u].insert(v);
    adj_list[v].insert(u);
}

void dfs(unordered_map<int, unordered_set<int>> &adj_list, vector<bool> &visited, vector<int> &parent, int u, int &total_cycle, vector<int> &time_visited, int &timer)
{
    visited[u] = true;
    time_visited[u] = timer++;

    for (auto v : adj_list[u]){
        if (!visited[v]){
            parent[v] = u;
            dfs(adj_list, visited, parent, v, total_cycle, time_visited, timer);
        }

        else if (parent[u] != v && time_visited[v] < time_visited[u]){
            total_cycle++;
        }
    }
}

void jojo_aja_kesel_ngerjain_soal_ini(unordered_map<int, unordered_set<int>> &adj_list, int N)
{
    vector<bool> visited(N + 1, false);
    vector<int> time_visited(N + 1, -1);
    vector<int> parent(N + 1, -1);

    int connected_comp = 0, total_cycle = 0, timer = 0;
    for (int i = 1; i <= N; i++){
        if (!visited[i]){
            dfs(adj_list, visited, parent, i, total_cycle, time_visited, timer);
            connected_comp++;
        }
    }

    /* *** Handle Edge case *** */
    if (total_cycle == 0)
    {
        cout << 1 << " " << connected_comp << endl;
    }
    else if (total_cycle < connected_comp)
    {
        cout << total_cycle + 1 << " " << connected_comp << endl;
    }
    else
    {
        cout << total_cycle << " " << connected_comp << endl;
    }
}

int main(){
    int N;
    cin >> N;

    unordered_map<int, unordered_set<int>> adj_list;
    for (int i = 1; i <= N; i++)
    {
        int u;
        cin >> u;
        addEdge(adj_list, i, u);
    }

    jojo_aja_kesel_ngerjain_soal_ini(adj_list, N);
    return 0;
}