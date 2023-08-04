#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    vector<int> res;
    for(int i = 0; i < N; i++){
        int ctr = 0;
        for(int j = i+1; j < N; j++){
            if (abs(A[i] - A[j]) <= M)
            {
                ctr++;
            }
            else{
                break;
            }
        }

        if(ctr+1 >= res.size()){
            res.clear();
            
            for(int j = i; j <= i + ctr; j++){
                res.push_back(A[j]);
            }
        }
    }

    cout << res.size() << endl;

    for(int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}