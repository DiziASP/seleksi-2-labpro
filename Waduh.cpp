#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> ch(26, 0);
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);

        for (int j = 0; j < s.length(); j++)
        {
            if(s[j] == 'w' || s[j] == 'a' || s[j] == 'd' || s[j] == 'u' || s[j] == 'h')
                ch[s[j] - 'a']++;
        }
    }
    vector<int> waduh;

    waduh.push_back(ch['w' - 'a']);
    waduh.push_back(ch['a' - 'a']);
    waduh.push_back(ch['d' - 'a']);
    waduh.push_back(ch['u' - 'a']);
    waduh.push_back(ch['h' - 'a']);

    sort(waduh.begin(), waduh.end());

    cout << waduh[0] << endl;
    return 0;
}