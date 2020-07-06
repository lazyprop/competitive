#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<pair<int, int> > adj[n+3];
    for (int i = 0; i < n-1; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }

    int q, k; cin>>q>>k;

    // dfs
    stack<int> s;
    int dist[n+3] = {};
    dist[k] = 1;
    s.push(k);
    while (!s.empty())
    {
        int x = s.top(); s.pop();
        for (auto y: adj[x])
        {
            if (!dist[y.first])
            {
                dist[y.first] = dist[x] + y.second;
                s.push(y.first);
            }
        }
    }

    while (q--)
    {
        int x, y; cin>>x>>y;
        cout<<dist[x] + dist[y] - 2<<endl;
    }
}
