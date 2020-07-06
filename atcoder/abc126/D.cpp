#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<pair<int,ll> > adj[n+3];
    for (int i = 0; i < n-1; i++)
    {
        int x, y; cin>>x>>y;
        ll c; cin>>c;
        adj[x].push_back({y,c});
        adj[y].push_back({x,c});
    }

    ll dist[n+3] = {};
    stack<int> s;
    dist[1] = 1;
    s.push(1);
    while (!s.empty())
    {
        int x = s.top(); s.pop();
        for (auto y: adj[x])
        {
            if (!dist[y.first])
            {
                s.push(y.first);
                dist[y.first] = dist[x] + y.second;
            }
        }
    }

    cout<<0<<endl;
    for (int i = 2; i <= n; i++)
    {
        dist[i]--;
        if (dist[i] % 2) cout<<1<<endl;
        else cout<<0<<endl;
    }
}
