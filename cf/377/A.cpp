#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k; cin>>n>>m>>k;
    int grid[n][m];
    pair<int, int> start = {-1, -1};
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin>>c;
            grid[i][j] = (c == '.');
            if (grid[i][j])
            {
                if (start.first == -1)
                {
                    start = {i, j};
                }
                s++;
            }
        }
    }

    int count = 0;
    queue<pair<int, int> > Q;
    int seen[n][m] = {};
    Q.push(start);

    while (!Q.empty())
    {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        if (!grid[x][y]) continue;
        if (seen[x][y]) continue;
        
        count++;
        seen[x][y] = 1;
        if (count == s-k) break;

        if (x+1 < n)
        {
            Q.push({x+1, y});
        }
        
        if (y+1 < m)
        {
            Q.push({x, y+1});
        }

        if (y-1 >= 0)
        {
            Q.push({x, y-1});
        }

        if (x-1 >= 0)
        {
            Q.push({x-1, y});
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (seen[i][j]) printf(".");
            else
            {
                if (grid[i][j]) printf("X");
                else printf("#");
            }
        }
        printf("\n");
    }
}
