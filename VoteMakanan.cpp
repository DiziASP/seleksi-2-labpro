#include <bits/stdc++.h>

using namespace std;

char check_majority(vector<char> arr){
    char res = ' ';
    int count = 0;

    for (char c : arr)
    {
        if (count == 0)
        {
            res = c;
            count = 1;
        }

        else if (c == res)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    return res;
}
int main()
{
    int n;
    std::cin >> n;

    vector<char> ans(n);
    for (int i = 0; i < n; i++)
    {
        char c;
        std::cin >> c;
        ans[i] = c;
    }

    char res = check_majority(ans);
    cout << res << endl;

    return 0;
}