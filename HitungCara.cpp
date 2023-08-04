#include <bits/stdc++.h>

using namespace std;


int main()
{
    
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> arr(N+1, vector<int>(K+1, 0));

    /* Initial Base Case for K = 0*/
    for (int i = 1; i <= N; i++)
    {
        arr[i][0] = M;
    }

    /* Recursion for remaining DP array */
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= K; j++)
        {
            if (i == j)
            {
                arr[i][j] = arr[i - 1][j];
            }
            else
            {
                arr[i][j] = (1LL * arr[i - 1][j - 1] * (M - 1) + arr[i - 1][j]) % 998244353;
            }
        }
    }

    cout << arr[N][K] % 998244353 << endl;

    return 0;
}