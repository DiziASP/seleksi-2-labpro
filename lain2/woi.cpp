#include <bits/stdc++.h>


using namespace std;

int pair_mul(vector<int> nums, int l, int r)
{
    int count = 0;
    sort(nums.begin(), nums.end());

    for (int i = 0; nums[i] * nums[i] <= r; i++)
    {
        int low = lower_bound(nums.begin() + i + 1, nums.end(), l / nums[i] + (l % nums[i] != 0)) - nums.begin();
        int high = upper_bound(nums.begin() + i + 1, nums.end(), r / nums[i]) - nums.begin();

        count += max(0, high - low);
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
    // vector<int> ans;
    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << pair_mul(A, l, r) << endl;
        // ans.push_back(pair_mul(A, l, r));
    }

    // for (int each: ans)
    //     cout << each << endl;
    
    return 0;
}
