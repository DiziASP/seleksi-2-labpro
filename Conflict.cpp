#include <bits/stdc++.h>

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;

    
    vector<pair<int,int>> asisten(N+1);
    
    for (int i = 1; i <= N; i++){
        int L, R;
        cin >> L >> R;
        asisten[i] = make_pair(L, R);
    }

    /* Split left bound and the right bound */
    vector<int> leftBounds(N + 1);
    vector<int> rightBounds(N + 1);
    for (int j = 1; j <= N; j++)
    {
        leftBounds[j] = asisten[j].first;
        rightBounds[j] = asisten[j].second;
    }
    sort(leftBounds.begin(), leftBounds.end());
    sort(rightBounds.begin(), rightBounds.end());

    /* Binary search on left and right bounds */
    for(int i = 1; i <= N; i++){
        int L = asisten[i].first, R = asisten[i].second;
        int low = 1, high = N;

        /* Finding Lower Bound and Upper Bound */
        int upperBound_at_L, lowerBound_at_R;
        upperBound_at_L = upper_bound(leftBounds.begin(), leftBounds.end(), R) - leftBounds.begin();
        lowerBound_at_R = lower_bound(rightBounds.begin(), rightBounds.end(), L) - rightBounds.begin();

        /* Finding the number of overlaps */
        cout << (upperBound_at_L - lowerBound_at_R ) - 1<< " ";
    }
    
    return 0;
}