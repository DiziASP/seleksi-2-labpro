#include <bits/stdc++.h>

using namespace std;

int pair_mul(vector<int> nums, int l, int r)
{
    int count = 0;

    for (int i = 0; i < nums.size()-1; i++)
    {
        for(int j = i + 1; j < nums.size(); j++){
            if(nums[i] * nums[j] <= r && nums[i] * nums[j] >= l)
                count++;
        }
    }

    return count % 1000000007;
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
        // cout << pair_mul(A, l, r) << endl;
        ans.push_back(pair_mul(A, l, r));
    }

    for (int each : ans)
        cout << each << endl;

    return 0;
}
