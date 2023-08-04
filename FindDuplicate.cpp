#include <bits/stdc++.h>

using namespace std;

int find_duplicate(vector<int> arr)
{
    int res = 0;

    for (int i = 0; i < arr.size(); i++){
        res ^= arr[i] ^ i; // gotcha fam!
    }

    return res;
}

int main()
{
    int n;
    cin >> n;

    vector<int> nums(n + 1);
    for (int i = 0; i < n + 1; i++){
        cin >> nums[i];
    }

    cout << find_duplicate(nums) << endl;

    return 0;
}