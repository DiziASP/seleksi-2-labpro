#include <bits/stdc++.h>

using namespace std;

int placeKElements(vector<int> &arr, int k)
{
    sort(arr.begin(), arr.end());
    int left = 0, right = arr[arr.size() - 1] - arr[0], ans = -1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        int lastPlaced = arr[0], placedCount = 1;
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - lastPlaced >= mid)
            {
                placedCount++;
                lastPlaced = arr[i];
                if (placedCount == k)
                {
                    ans = mid;
                    break;
                }
            }
        }
        if (placedCount < k)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 4, 3, 2, 1, 8, 10, 12, 100000000};
    int k = 4;
    cout << placeKElements(arr, k) << endl; // Output: 3
    return 0;
}