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

    int par[n+1] = {};
    queue<int> Q;
    Q.push(1);
    par[1] = -1;
    while (!Q.empty())
    {
        int x = Q.front(); Q.pop();
        for (auto y: adj[x])
        {
            if (par[y]) continue;
            par[y] = x;
            Q.push(y);
        }
    }

    printf("Yes\n");
    for (int i = 2; i <= n; i++)
    {
        printf("%d\n", par[i]);
    }
}
