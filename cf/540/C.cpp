#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 500;
char grid[maxn][maxn];
int n, m;

int neighbor(int x, int y)
{
    int ans = 0;
    if (x+1 < n) ans+= (grid[x+1][y] == '.');
    if (x-1 >= 0) ans+= (grid[x-1][y] == '.');
    if (y+1 < m) ans+= (grid[x][y+1] == '.');
    if (y-1 >= 0) ans+= (grid[x][y-1] == '.');
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>grid[i][j];
        }
    }

    int r1, c1, r2, c2; cin>>r1>>c1>>r2>>c2;
    r1--; c1--; r2--; c2--;

    if (r1 == r2 and c1 == c2)
    {
        if (neighbor(r1, c1)) printf("YES\n");
        else printf("NO\n");
        return 0;
    }
    if ((abs(r1-r2) == 1 and c1 == c2) or (abs(c1-c2) == 1 and r1 == r2))
    {
        if (grid[r2][c2] == '.' and neighbor(r2,c2)) printf("YES\n");
        else if (grid[r2][c2] == 'X') printf("YES\n");
        else printf("NO\n");
        return 0;
    }

    stack<pair<int, int> > S;
    int seen[n][m] = {};
    S.push({r1, c1});
    bool start = false, ans = 0;
    while (!S.empty())
    {
        int x = S.top().first, y = S.top().second;
        S.pop();

        if (r2 == x and c2 == y)
        {
            ans= 1;
            break;
        }
        if (seen[x][y] or (grid[x][y] == 'X' and start)) continue;
        seen[x][y] = 1;
        start = 1;

        if (x+1 < n) S.push({x+1, y});
        if (x-1 >= 0) S.push({x-1, y});
        if (y+1 < m) S.push({x, y+1});
        if (y-1 >= 0) S.push({x, y-1});
    }
    if (ans)
    {
        if (grid[r2][c2] == 'X') printf("YES\n");
        else if (neighbor(r2, c2) >= 2) printf("YES\n");
        else printf("NO\n");
    }
    else printf("NO\n");
}
