#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 50;

int dir[4][2] = {{1,0}, {0, 1}, {-1, 0}, {0,-1}};
int ans = 0, n, m;
char grid[maxn][maxn] ;
bool seen[maxn][maxn];

int valid(int x, int y)
{
    if (x >= n or y >= m) return false;
    if (x < 0 or y < 0) return false;
    return true; }

void dfs(int x, int y,int prevx,int prevy)
{
    if (!valid(x, y)) return;
    if (grid[x][y] != grid[prevx][prevy]) return;

    if (seen[x][y])
    {
        ans = 1;
        return;
    }

    seen[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0], nexty = y + dir[i][1];
        if (nextx == prevx and nexty == prevy) continue;
        dfs(nextx, nexty, x, y);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin>>grid[i][j];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            memset(seen, 0, sizeof(seen));
            dfs(i, j, i, j);
            if (ans) break;
        }
        if (ans) break;
    }
    if (ans) printf("Yes\n");
    else printf("No\n");
}
