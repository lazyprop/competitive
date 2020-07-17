#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin>>n>>m;
    vector<int> adj[n+1];
    for (int i = 0; i < m; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s1, t1, l1; cin>>s1>>t1>>l1;
    int s2, t2, l2; cin>>s2>>t2>>l2;

    int dist[n+2][n+2] = {};
    for (int i = 1; i <= n; i++)
    {
        int seen[n+1] = {};
        queue<int> Q;
        Q.push(i);
        seen[i] = 1;
        while (!Q.empty())
        {
            int x = Q.front(); Q.pop();
            for (auto y: adj[x])
            {
                if (!seen[y])
                {
                    seen[y] = 1;
                    Q.push(y);
                    dist[i][y] = dist[i][x] + 1;
                }
            }
        }
    }

    if (dist[s1][t1] > l1 or dist[s2][t2] > l2)
    {
        printf("-1\n");
        return 0;
    }

    int ans = max(0, m - dist[s1][t1] - dist[s2][t2]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //if (i == j) continue;
            int d1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            int d2 = dist[s2][i] + dist[i][j] + dist[j][t2];
            if (d1 > l1 or d2 > l2) continue;

            int x = d1 + d2 - dist[i][j];
            ans = max(ans, m - x);
        }
    }

    swap(s1, t1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            //if (i == j) continue;
            int d1 = dist[s1][i] + dist[i][j] + dist[j][t1];
            int d2 = dist[s2][i] + dist[i][j] + dist[j][t2];
            if (d1 > l1 or d2 > l2) continue;

            int x = d1 + d2 - dist[i][j];
            ans = max(ans, m - x);
        }
    }
    printf("%d\n", ans);
}
