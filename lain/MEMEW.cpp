#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Custom lower_bound implementation
int lower_bound_custom(vector<int> &arr, int left, int right, int target)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

// Custom upper_bound implementation
int upper_bound_custom(vector<int> &arr, int left, int right, int target)
{
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int main()
{
    int b, q;
    cin >> b >> q;

    vector<int> a(b);
    for (int i = 0; i < b; i++)
    {
        cin >> a[i];
    }

    vector<int> res;
    for (int k = 0; k < q; k++)
    {
        int l, r;
        cin >> l >> r;

        sort(a.begin(), a.end());
        int count = 0;

        for (int i = 0; i < b - 1; i++)
        {
            int low = lower_bound_custom(a, i + 1, b, l / a[i] + (l % a[i] != 0));
            int high = upper_bound_custom(a, i + 1, b, r / a[i]);

            count += max(0, high - low);
        }

        res.push_back(count);
    }

    for (int h : res)
    {
        cout << h << endl;
    }

    return 0;
}