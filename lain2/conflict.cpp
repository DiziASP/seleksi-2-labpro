#include <bits/stdc++.h>

using namespace std;

bool compareinterval(pair<int,int> a, pair<int,int> b){
    
    return a.first < b.first;
}

bool conflict(pair<int,int> a, pair<int,int> b){
    if(a.first <= b.first && b.first <= a.second){
        return true;
    }
    if(a.first <= b.second && b.second <= a.second){
        return true;
    }
    if(b.first <= a.first && a.first <= b.second){
        return true;
    }
    if(b.first <= a.second && a.second <= b.second){
        return true;
    }
    return false;
} 

int main(){
    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> interval_asisten;
    for(int i = 0; i < n; i++){
        int l, r;
        cin >> l >> r;

        interval_asisten.push_back(make_pair(l, r));
    }

    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        int count = 0;

    }

}