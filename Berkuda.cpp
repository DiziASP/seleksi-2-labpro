#include <bits/stdc++.h>

using namespace std;

bool isValidMove(int x, int y, int n)
{
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

int minMoves(int n, pair<int, int> origin, pair<int, int> destination)
{
    vector<vector<bool>> board(n, vector<bool>(n, false));
    vector<pair<int, int>> possible_moves = {
        {1 ,2}, {1,-2},
        {-1, 2}, {-1,-2},
        {2, 1}, {2, -1},
        {-2, 1}, {-2, -1}
    };
    queue<pair<int, int>> position;

    /* Initialize Origin */
    board[origin.first - 1][origin.second - 1] = true; 
    position.push(origin);
    int min_steps = 0;

    /* Using Breadth First Search to Find minimum steps*/
    while(!position.empty())
    {
        int possible_step = position.size();
        for (int i = 0; i < possible_step; i++)
        {
            pair<int, int> curr = position.front();
            position.pop();

            if(curr == destination)
                return min_steps;

            for (pair<int, int> move : possible_moves)
            {
                int x = curr.first + move.first;
                int y = curr.second + move.second;

                if(isValidMove(x, y, n) && !board[x - 1][y - 1])
                {
                    board[x - 1][y - 1] = true;
                    position.push({x, y});
                }
            }
        }

        min_steps++;
    }

    return -1;
}

int main() {
    int n;
    cin >> n;

    pair<int, int> origin, destination;
    cin >> origin.first >> origin.second;
    cin >> destination.first >> destination.second;

    cout << minMoves(n, origin, destination ) << endl;
}