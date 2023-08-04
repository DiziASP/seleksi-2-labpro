#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareInterval(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> interval_asisten(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int L, R;
        cin >> L >> R;

        interval_asisten[i] = make_pair(L, R);
    }

    vector<int> overlapping(N + 1, 0);
    vector<int> dp(N + 1, 0);

    // Sort intervals by their start times
    sort(interval_asisten.begin() + 1, interval_asisten.end(), compareInterval);

    for (int i = 1; i <= N; i++)
    {
        int maxOverlapping = 0;

        // Find the maximum overlapping interval that ends before the current interval
        for (int j = 1; j < i; j++)
        {
            if (max(interval_asisten[j].first, interval_asisten[i].first) <= min(interval_asisten[j].second, interval_asisten[i].second))
            {
                maxOverlapping = max(maxOverlapping, dp[j]);
            }
        }

        // Update the maximum overlapping intervals including the current interval
        dp[i] = maxOverlapping + 1;

        // Update the overlapping count for each interval
        overlapping[i] = dp[i];
    }

    for (int i = 1; i <= N; i++)
    {
        cout << overlapping[i] << " ";
    }
    cout << endl;

    return 0;
}
