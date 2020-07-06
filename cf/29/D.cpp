#include <bits/stdc++.h>
using namespace std;

const int maxn = 300;
map<int, vector<int> > paths;
int seen[maxn+3] = {};
vector<int> adj[maxn+3];
int edge[maxn+3][maxn+3] = {};
int leafcount = 0;

void dfs(int x)
{
    paths[x].push_back(x);
    int edgecount = 0;
    for (auto y: adj[x])
    {
        if (!seen[y])
        {
            seen[y] = 1;
            paths[y] = paths[x];
            edgecount++;
            dfs(y);
        }
    }
    if (!edgecount)
    {
        leafcount++;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    for (int i = 1; i < n; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        edge[x][y] = 1;
        edge[y][x] = 1;
    }

    seen[1] = 1;
    dfs(1);

    vector<int> path, cur;
    path.push_back(1);
    cur.push_back(1);

    while (leafcount--)
    {
        int x; cin>>x;
        int l = 0, count = min(cur.size(), paths[x].size());

        for (; l < count; l++)
        {
            if (cur[l] != paths[x][l]) break;
        }

        for (int i = cur.size()-1; i >= l; i--)
        {
            cur.pop_back();
            path.push_back(cur.back());
        }

        for (int i = l, last = paths[x].size(); i < last; i++)
        {
            cur.push_back(paths[x][i]);
            path.push_back(paths[x][i]);
        }
    }

    int node = path.back();
    int ind = paths[node].size() -1;
    while (ind--) path.push_back(paths[node][ind]);

    if (path.size() > (2*n - 1))
    {
        cout<<-1<<endl;
        return 0;
    }

    for (int i = 0, count = path.size(); i < count; i++)
    {
        printf("%d ", path[i]);
    }
    printf("\n");
}
