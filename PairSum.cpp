#include <bits/stdc++.h>

using namespace std;

void pair_mul(vector<int> &nums, vector<pair<int, int>> &query)
{
    for (auto q : query) //---> O(q)
    {
        int l = q.first;
        int r = q.second;
        int count = 0;
        for (int i = 0; nums[i] * nums[i] <= r; i++) //--> O(b)
        {
            int upper = upper_bound(nums.begin() + i + 1, nums.end(), r / nums[i]) - nums.begin();
            int lower = lower_bound(nums.begin() + i + 1, nums.end(), l / nums[i] + (l % nums[i] != 0)) - nums.begin();

            count += max(0, upper - lower);
        }
        cout << count << endl;
    }
}

int main()
{
    int b, q;
    cin >> b >> q;

    vector<int> A(b);
    for (int i = 0; i < b; i++)
    {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    vector<pair<int, int>> query;

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        query.push_back(make_pair(l, r));
    }

    pair_mul(A, query);

    return 0;
}
