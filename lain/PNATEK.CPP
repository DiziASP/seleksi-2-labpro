#include <bits/stdc++.h>
using namespace std;

int main()
{
    int b, q;
    cin >> b >> q;

    vector<int> a(b);
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
    }

    vector<vector<int>> lower(b, vector<int>(b));
    vector<vector<int>> upper(b, vector<int>(b));

    for (int i = 0; i < b; i++)
    {
        for (int j = i + 1; j < b; j++)
        {
            if (a[i] != 0)
            {
                lower[i][j] = (a[i] == 0) ? 0 : ((a[j] / a[i]) + ((a[j] % a[i]) != 0));
                upper[i][j] = a[j] / a[i];
            }
            else
            {
                lower[i][j] = 1;
                upper[i][j] = INT_MAX;
            }
        }
    }

    vector<int> res;
    for (int k = 0; k < q; k++)
    {
        int l, r;
        cin >> l >> r;

        int n = a.size();
        long long count = 0;

        for (int i = 0; i < n - 1; i++)
        {
            int low = lower[i][n - 1];  // Get the precomputed lower bound
            int high = upper[i][n - 1]; // Get the precomputed upper bound

            count += max(0, high - low + 1); // Add range of numbers to count (+1 for inclusive range)
        }

        res.push_back(count);
    }

    for (int r : res)
    {
        cout << r << endl;
    }

    return 0;
}