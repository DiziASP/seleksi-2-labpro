#include <bits/stdc++.h>

using namespace std;

int calculateSmallestTotal(const vector<int> &nums, const vector<char> &ops, int currentIndex, int currentTotal, int currentNumIndex)
{
    if (currentIndex == ops.size())
    {
        return currentTotal;
    }

    int smallestTotal = numeric_limits<int>::max();

    // Recursive case:
    // Apply each operator to the remaining unvisited elements
    // and recursively calculate the smallest total.
    for (int i = currentNumIndex; i < nums.size(); i++)
    {
        int result = 0;

        if (ops[currentIndex] == '*')
        {
            result = calculateSmallestTotal(nums, ops, currentIndex + 1, currentTotal * nums[i], i + 1);
        }
        else if (ops[currentIndex] == '+')
        {
            result = calculateSmallestTotal(nums, ops, currentIndex + 1, currentTotal + nums[i], i + 1);
        }

        smallestTotal = min(smallestTotal, result);
    }

    return smallestTotal;
}

int main(){
    vector<int> nums(4);
    for(int i = 0; i < 4; i++){
        cin >> nums[i];
    }

    vector<char> ops(3);
    for(int i = 0; i < 3; i++){
        cin >> ops[i];
    }

    cout << calculateSmallestTotal(nums, ops, 0, nums[0], 1) << endl;
}