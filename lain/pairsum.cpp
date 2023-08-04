#include <bits/stdc++.h>

using namespace std;

int lowerbound(vector<int> &arr, int it, int target)
{
    int end = arr.size();
    while (it < end)
    {
        int mid = it + (end - it) / 2;
        if (arr[mid] < target)
        {
            it = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return it;
}

int upperbound(vector<int> &arr, int it, int target)
{   
    int end = arr.size();
    while (it < end)
    {
        int mid = it + (end - it) / 2;
        if (arr[mid] <= target)
        {
            it = mid + 1;
        }
        else
        {
            end = mid;
        }
    }
    return it;
}

int main() {
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
            int low = lowerbound(a, i + 1,  l / a[i] + (l % a[i] != 0));
            int high = upperbound(a, i + 1, r / a[i]);

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