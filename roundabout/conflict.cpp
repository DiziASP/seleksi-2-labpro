#include <bits/stdc++.h>

using namespace std;

bool compareinterval(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int N,M;
    cin >> N >> M;

    vector<pair<int,int>> interval_asisten(N+1);
    
    for(int i = 1; i <= N; i++){
        int L, R;
        cin >> L >> R;

        interval_asisten[i] = make_pair(L, R);
    }

    vector<int> overlapping(N+1, 0);
    for(int i = 1; i <= N; i++){
        stack<pair<int, int>> currentAsistenOlp;
        vector<pair<int,int>> interval_asisten_lain = interval_asisten;

        /* Exclude value at Index i*/
        interval_asisten_lain.erase(interval_asisten_lain.begin() + i);

        sort(interval_asisten_lain.begin(), interval_asisten_lain.end(), compareinterval);

        for (int j = 1; j <= interval_asisten_lain.size()-1; j++)
        {
            if (max(interval_asisten_lain[j].first, interval_asisten[i].first) <= min(interval_asisten_lain[j].second, interval_asisten[i].second))
            {
                currentAsistenOlp.push(interval_asisten_lain[j]);
            }
        }
        overlapping[i] = currentAsistenOlp.size();
    }

    for(int i = 1; i <= N; i++){
        cout << overlapping[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}