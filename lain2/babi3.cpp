#include <bits/stdc++.h>

using namespace std;

bool comp_pair(vector<int> a, vector<int> b)
{
    return a[0] < b[0];
}

int solve(vector<vector<int>> intervals, int start, int end)
{
    int count = 0;

    sort(intervals.begin(), intervals.end(), comp_pair);

    for(vector<int> each: intervals){
        if(each[0] <= end || 
            each[0] >= start ||
            each[1] >= start ||
            each[1] <= end)
            count++;
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> intervals(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    vector<int> conflicts;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> temp = intervals;
        temp.erase(temp.begin() + i);

        conflicts.push_back(solve(intervals, intervals[i][1], intervals[i][2]));
    }

    for (int each : conflicts)
    {
        cout << each << " ";
    }
    cout << endl;

    return 0;
}