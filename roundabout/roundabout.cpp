#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;

    unordered_map<int,int> kultus(N+1);
    for(int i = 1; i < N+1; i++){
        cin >> kultus[i];
    }

    int maxLingkaran = 0;
    int minLingkaran = 1;


    for(int i = 1; i <= N; i++){
        int j = kultus[i];

        if(j-i < 0){
            maxLingkaran++;
        }
    }

    cout << minLingkaran << " " << maxLingkaran << endl;

    return 0;
}