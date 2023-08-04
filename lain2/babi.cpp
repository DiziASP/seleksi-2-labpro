#include <bits/stdc++.h>

using namespace std;

bool comp_pair(vector<int> a, vector<int> b)
{
    return a[2] < b[2];
}

int solve(vector<vector<int>> intervals, int asisten)
{
    int count = 0;

    sort(intervals.begin(), intervals.end(), comp_pair);
    int initialEnd = INT_MIN;

    for(vector<int> each: intervals){
        if(each[0] == asisten)
            continue;

        if(each[1] > initialEnd)
            initialEnd = each[2];
        else
            count++;
    }

    /* Demi allah gue gatau ya allah ya rabb */
    return count;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> intervals(n, vector<int>(3, 0));
    for (int i = 0; i < n; i++)
    {   
        intervals[i][0] = i;
        cin >> intervals[i][1] >> intervals[i][2];
    }
    
    vector<int> conflicts;
    for(int i = 0; i < n; i++){
        conflicts.push_back(solve(intervals, i));
    }

    for(int each: conflicts){
        cout << each << " ";
    }
    cout << endl;

    return 0;
}