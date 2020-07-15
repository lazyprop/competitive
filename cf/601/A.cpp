#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin>>n>>m;
    int adj[n+2][n+2] = {};
    for (int i = 0; i < m; i++)
    {
        int x, y; cin>>x>>y;
        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    queue<int> Q;
    int dist1[n+2] = {};
    Q.push(1);
    dist1[1] = 1;
    while (!Q.empty())
    {
        int x = Q.front(); Q.pop();

        for (int y = 1; y <= n; y++)
        {
            if (!adj[x][y] or x == y or dist1[y]) continue;
            dist1[y] = dist1[x] + 1;
            Q.push(y);
        }
    }

    int dist2[n+2] = {};
    Q.push(1);
    dist2[1] = 1;
    while (!Q.empty())
    {
        int x = Q.front(); Q.pop();

        for (int y = 1; y <= n; y++)
        {
            if (adj[x][y] or x == y or dist2[y]) continue;
            dist2[y] = dist2[x] + 1;
            Q.push(y);
        }
    }

    if (dist1[n] and dist2[n]) cout<<max(dist1[n], dist2[n]) - 1<<endl;
    else cout<<-1<<endl;
}
