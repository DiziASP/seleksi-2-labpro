#include <bits/stdc++.h>

using namespace std;


int main() {
    int b, q;
    cin >> b >> q;

    vector<int> a(b);
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
    }

    vector<int> res;
    for (int k = 0; k < q; k++){
        int l, r;
        cin >> l >> r;

        int n = a.size();
        long long count = 0;

        sort(a.begin(), a.end()); // Sort the array

        for (int i = 0; i < n - 1; i++)
        {
            int low = lower_bound(a.begin() + i + 1, a.end(), l / a[i] + (l % a[i] != 0)) - a.begin(); // Find the lower bound where l >= a[i] * a[j] or l/a[i] >= a[j]
            int high = upper_bound(a.begin() + i + 1, a.end(), r / a[i]) - a.begin();                  // Find the upper bound where r <= a[i] * a[j] or r/a[i] <= a[j]

            count += max(0, high - low); // Add range of number to count
        }

        res.push_back(count);
    }

    for (int r : res)
    {
        cout << r << endl;
    }

    return 0;
}