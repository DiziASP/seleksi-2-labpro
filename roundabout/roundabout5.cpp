#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    unordered_map<int, vector<int>> adj_list;
    for (int i = 1; i <= N; i++){
        int u;
        cin >> u;
        adj_list[i].push_back(u);
    }
    /* Debugging : Print adjacency List */
    for (int i = 1; i <= N; i++)
    {
        cout << i << " : ";
        for (int j : adj_list[i])
            cout << j << " ";
        cout << endl;
    }
    cout << endl;

    int total_cycle = 0;
    int min_circle = 0, max_circle = 0;
    vector<bool> visited(N + 1, false);

    int currCycleSNode = 1;

    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            visited[i] = true;
            continue;
        }

        if(i == currCycleSNode){
            total_cycle++;
        }
        max_circle++;
        currCycleSNode = i;
    }

    return 0;
}