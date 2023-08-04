#include <bits/stdc++.h>
using namespace std;

int smallest_result = INT_MAX;

int apply_operator(int a, char op, int b)
{
    if (op == '+')
        return a + b;
    else if (op == '*')
        return a * b;
    return 0;
}

int calculate_result(vector<int> numbers, vector<char> operators, int idx, int level, int current_result)
{
    if(level == operators.size())
    {
        return current_result;
    }

    int res = INT_MAX;
    
    for (int i = idx; i < numbers.size(); i++)
    {
        if(i == idx)
            continue;
        int new_result = apply_operator(current_result, operators[level], numbers[i+1]);
        res = min(res, calculate_result(numbers, operators, i, level + 1, new_result));
    }

    return res;
}

int main()
{
    vector<int> numbers(4);
    vector<char> operators(3);
    for (int i = 0; i < 4; i++)
    {
        cin >> numbers[i];
    }
    for (int i = 0; i < 3; i++)
    {
        cin >> operators[i];
    }

    cout << calculate_result(numbers, operators, 0, 0, numbers[0]) << endl;

    return 0;
}
