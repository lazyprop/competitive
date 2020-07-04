#include <bits/stdc++.h>
using namespace std;

int n;

int longestpath(vector<int> adj[], int left, int right)
{
    queue<int> s;
    int seen[n+3] = {};
    s.push(left);
    seen[left] = 1;
    int last = left;

    while (!s.empty())
    {
        int x = s.front(); s.pop();
        last = x;
        for (auto y: adj[x])
        {
            if (!seen[y] and y != right)
            {
                seen[y] = 1;
                s.push(y);
            }
        }
    }

    int dist[n+3]= {};
    s.push(last);
    dist[last] = 1;
    
    while (!s.empty())
    {
        int x = s.front(); s.pop();
        last = x;
        for (auto y: adj[x])
        {
            if (!dist[y] and y != right)
            {
                dist[y] = dist[x]+1;
                s.push(y);
            }
        }
    }

    return dist[last]-1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    vector<pair<int, int> > edges;
    vector<int> adj[n+3];
    for (int i = 0; i < n-1; i++)
    {
        int x, y; cin>> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({x,y});
    }

    int ans = 0;
    for (auto edge: edges)
    {
        int left = edge.first, right = edge.second;
        ans = max(ans, longestpath(adj, left, right) *
                longestpath(adj, right, left));
    }
    cout<<ans<<endl;
}
