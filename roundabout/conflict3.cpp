#include <bits/stdc++.h>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;

    vector<Interval> interval_asisten(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int L, R;
        cin >> L >> R;

        interval_asisten[i] = {L, R, i};
    }

    vector<int> overlapping(N + 1, 0);
    return 0;
}