#include <bits/stdc++.h>

using namespace std;

int pair_mul(vector<int> nums, int l, int r)
{
    int count = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; nums[i] * nums[i] <= r; i++)
    {
        int upper = upper_bound(nums.begin() + i + 1, nums.end(), r / nums[i]) - nums.begin();

        int j;
        for (j = i + 1; nums[i] * nums[j] < l; j++);

        count += max(0, upper-j);
    }

    return count;
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
    vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;

        ans.push_back(pair_mul(A, l, r));
    }

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    
    return 0;
}