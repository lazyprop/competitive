#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 150000;
vector<int> adj[maxn+3];
int seen[maxn+3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin>>n>>m;
    vector<int> adj[n+3];
    for (int i = 0; i < m; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
    {
        if (seen[i]) continue;

        stack<int> s;
        s.push(i);
        seen[i] = 1;

        ll edgecount = 0, vertcount = 0;
        if (adj[i].empty()) continue;

        while (!s.empty())
        {
            int x = s.top(); s.pop();
            vertcount++;
            edgecount+= adj[x].size();
            for (auto y: adj[x])
            {
                if (!seen[y])
                {
                    seen[y] = 1;
                    s.push(y);
                }
            }
        }
        
        if (vertcount == 2) continue;
        if (edgecount != (vertcount*(vertcount-1)))
        {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
}
