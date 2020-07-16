#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = (2 * pow(10,5)) + 5;
int b[maxn];

bool cmp(int x, int y)
{
    return b[x] < b[y];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<int> adj[n+3];
    for (int i = 0; i < n-1; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        b[a[i]] = i;
    }
    
    for (int i = 1; i <= n; i++)
    {
        sort(adj[i].begin(), adj[i].end(), cmp);
    }

    // bfs over tree to get levels
    int level[n+3] = {};
    queue<int> Q;
    Q.push(1);
    level[1] = 1;

    vector<int> seq;
    while (!Q.empty())
    {
        int x = Q.front(); Q.pop();
        seq.push_back(x);

        for (auto y: adj[x])
        {
            if (!level[y])
            {
                level[y] = level[x] + 1;
                Q.push(y);
            }
        }
    }

    int ans = 1;
    for (int i = 0, l = seq.size(); i < l; i++)
    {
        if (a[i] != seq[i])
        {
            ans = 0;
            break;
        }
    }

    if (ans) cout<<"Yes\n";
    else cout<<"No\n";
}
