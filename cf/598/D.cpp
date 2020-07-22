#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
int dir[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0,-1}};
int valid(int x, int y)
{
    if (x >= n or y >= m) return 0;
    if (x < 0 or y < 0) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k; cin>>n>>m>>k;
    int grid[n][m];
    int count[1000010] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin>>c;
            grid[i][j] = c == '.';
        }
    }

    int seen[n][m] = {};
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (seen[i][j] or !grid[i][j]) continue;
            stack<pair<int, int> > S;
            S.push({i,j});
            
            while (!S.empty())
            {
                int x = S.top().first, y = S.top().second;
                S.pop();
                
                if (!grid[x][y])
                {
                    count[cur]++;
                    continue;
                }

                if (seen[x][y]) continue;

                seen[x][y] = cur;
                
                for (int f = 0; f < 4; f++)
                {
                    int nextx = x + dir[f][0], nexty = y + dir[f][1];
                    if (valid(nextx,nexty))
                    {
                        S.push({nextx, nexty});
                    }
                }
            }
            cur++;
        }
    }

    while (k--)
    {
        int x, y; cin>>x>> y;
        x--; y--;
        printf("%d\n", count[seen[x][y]]);
    }

}
