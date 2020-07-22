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
    while (m--)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int state[n+1][n+1] = {};
    pair<int, int> par[n+1][n+1];
    queue<pair<int, int> > Q;
    Q.push({1,n});
    state[1][n] = 1;
    par[1][n] = {0, 0};
    while (!Q.empty())
    {
        int x = Q.front().first, y = Q.front().second;
        Q.pop();

        for (auto a: adj[x])
        {
            for (auto b: adj[y])
            {
                if (a == b or state[a][b]) continue;
                state[a][b] = state[x][y] + 1;
                Q.push({a, b});
                par[a][b] = {x, y};
            }
        }
    }

    if (!state[n][1])
    {
        printf("-1\n");
        return 0;
    }

    int x = n, y = 1;
    vector<int> v1, v2;
    while (x or y)
    {
        v1.push_back(x);
        v2.push_back(y);
        int tmp = par[x][y].first;
        y = par[x][y].second;
        x = tmp;
    }
    printf("%lu\n", v1.size() - 1);
    for (auto x: v2)
    {
        printf("%d ", x);
    }
    printf("\n");
    for (auto x: v1)
    {
        printf("%d ", x);
    }
    printf("\n");
}
