#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, n;
    cin >> x >> n;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
    }

    vector<int> res(x + 1, INT_MAX);
    res[0] = 0;

    for (int i = 1; i <= x; i++)
    {
        for (int each : coins)
        {
            if (each <= i && res[i - each] != INT_MAX)
            {
                res[i] = min(res[i], res[i - each] + 1);
            }
        }
    }

    if (res[x] == INT_MAX )
        cout << -1 << endl;
    
    else 
        cout << res[x] << endl;

    return 0;
}