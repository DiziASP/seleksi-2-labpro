#include <bits/stdc++.h>

using namespace std;

long long findUniqueCombinations(vector<int> &current, int idx, int currentSum, int target)
{
    /* Basis*/
    if (currentSum == target)
    {
        return 1;
    }

    if (currentSum > target || idx == current.size())
        return 0;

    /* Rekursi */
    long long count = 0;

    count += findUniqueCombinations(current, idx, currentSum + current[idx], target); /* current[idx] ikut kedalam rekursi */
    count += findUniqueCombinations(current, idx + 1, currentSum, target);            /* current[idx] tidak ikut kedalam rekursi */

    return count;
}

int main(){
    int N,M;
    cin >> N >> M;

    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    cout << findUniqueCombinations(A, 0, 0, M) % 1000000007 << endl;

    return 0;
}