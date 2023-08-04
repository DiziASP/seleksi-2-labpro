#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, cup;
    cin >> n >> cup;

    vector<int> arrPos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arrPos[i];
    }

    sort(arrPos.begin(), arrPos.end());

    /* Initial minimum distance */
    int start = 0, end = arrPos[n - 1] - arrPos[0], min_distance = -1;

    while (start <= end)
    {
        int mid = ((end - start) / 2) + start;
        int prevVal = arrPos[0], countCup = 1;

        for (int i = 1; i < n; i++)
        {
            if (arrPos[i] - prevVal >= mid)
            {
                countCup++;
                prevVal = arrPos[i];
                if (countCup == cup)
                {
                    min_distance = mid;
                    break;
                }
            }
        }

        if (countCup < cup)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    cout << min_distance << endl;
    return 0;
}