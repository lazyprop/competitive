#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int valid(int x, int y)
{
    if (x < 0 or y < 0) return 0;
    if (x >= n or y >= m) return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    char grid[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++) cin>>grid[i][j];
    }

    vector<int> components;
    int seen[n][m] = {};

    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (seen[i][j] or grid[i][j] == '*') continue;
            int size = 0;

            stack<pair<int, int>> S;
            S.push({i, j});
            while (!S.empty())
            {
                int x = S.top().first, y = S.top().second;
                S.pop();

                if (seen[x][y] or grid[x][y] == '*') continue;
                seen[x][y] = cur;
                size++;

                for (int f = 0; f < 4; f++)
                {
                    int newx = x + dir[f][0];
                    int newy = y + dir[f][1];
                    if (valid(newx, newy)) S.push({newx, newy});
                }
            }
            cur++;
            components.push_back(size);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
            {
                printf(".");
                continue;
            }
            int ans = 1;
            set<int> same;
            for (int f = 0; f < 4; f++)
            {
                int newx = i + dir[f][0];
                int newy = j + dir[f][1];
                if (!valid(newx, newy)) continue;

                int comp = seen[newx][newy];
                if (!comp) continue;

                if (same.find(comp) != same.end()) continue;
                ans+= components[comp-1];
                same.insert(comp);
            }
            ans%= 10;
            printf("%d", ans);
        }
        printf("\n");
    }
}
