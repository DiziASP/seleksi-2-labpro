#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    unordered_map<int, vector<int>> adj;
    unordered_map<int, pair<int,int>> asisten;

    for(int i = 1; i <= N; i++){
        int l,r;
        cin >> l >> r;

        asisten[i] = {l,r};
        for(int j = l; j <= r; j++){
            adj[j].push_back(i);
        }
    }

    vector<int> asisten_bentrok(N+1, 0);

    for(int i = 1; i <= N; i++){
        int l = asisten[i].first;
        int r = asisten[i].second;

        unordered_set<int> visited;

        for(int j = l; j <= r; j++){
            for(int each: adj[j]){
                if(visited.find(each) == visited.end()){
                    asisten_bentrok[i]++;
                    visited.insert(each);
                }
            }
        }
    }

    for(int i = 1; i <= N; i++){
        cout << asisten_bentrok[i] << " ";
    }
    cout << endl;

    

    return 0;
}