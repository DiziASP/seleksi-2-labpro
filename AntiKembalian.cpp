#include <bits/stdc++.h>

using namespace std;

bool subsetSum(vector<int> &nums, int target, int index, int sum){
    if (sum == target){
        return true;
    }

    if (index >= nums.size() || sum > target){
        return false;
    }

    if (subsetSum(nums, target, index + 1, sum + nums[index])){
        return true;
    }

    if (subsetSum(nums, target, index + 1, sum)){
        return true;
    }

    return false;
}

bool anti_kembalian(vector<int> &nums, int target){
    return subsetSum(nums, target, 0, 0);
}

int main()
{
    int m, n;
    std::cin >> m >> n;

    vector<int> money(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> money[i];
    }

    bool hasil = anti_kembalian(money, m);
    cout << (hasil? "YA" : "TIDAK") << endl;

    return 0;
}