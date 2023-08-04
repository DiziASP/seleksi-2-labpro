#include <bits/stdc++.h>

using namespace std;

struct Interval
{
    int start,end;
    int asisten;
};

bool compareinterval(Interval a, Interval b)
{
    return a.start < b.start;
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<Interval> interval_asisten(N + 1);

    for (int i = 1; i <= N; i++)
    {
        int L, R;
        cin >> L >> R;

        interval_asisten[i] = {L, R, i};
    }

    vector<int> overlapping(N + 1, 0);
    sort(interval_asisten.begin(), interval_asisten.end(), compareinterval);

    for (int i = 1; i <= N; i++)
    {
        stack<Interval> currentAsistenOlp;
        vector<Interval> interval_asisten_lain = interval_asisten;

        /* Exclude value at Index i*/
        interval_asisten_lain.erase(interval_asisten_lain.begin() + i);

        for (int j = 1; j <= interval_asisten_lain.size() - 1; j++)
        {
            if (max(interval_asisten_lain[j].start, interval_asisten[i].start) <= min(interval_asisten_lain[j].end, interval_asisten[i].end))
            {
                currentAsistenOlp.push(interval_asisten_lain[j]);
            }
        }
        overlapping[i] = currentAsistenOlp.size();
    }


    for(int i = 1; i <= N; i++)
    {
        cout << overlapping[i] << endl;
    }
    return 0;
}