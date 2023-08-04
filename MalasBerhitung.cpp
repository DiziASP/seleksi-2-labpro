#include <bits/stdc++.h>

using namespace std;

long long c = 0;
void findUniqueCombinations(vector<int> &current, int target, int idx, int n)
{
    /* Basis*/
    if (target == 0)
    {
        c++;
        return;
    }

    /* Rekursi */
    for(int i = idx; i < n; i++){
        if(current[i] > target)
            break;
    
        findUniqueCombinations(current, target - current[i], i, n);
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    findUniqueCombinations(A, M, 0, A.size());
    cout << c % 1000000007 << endl;

    return 0;
}