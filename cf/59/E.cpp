#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 3001;

int n, m, k;
vector<int> adj[maxn+1];
int dist[maxn][maxn], par[maxn][maxn], seen[maxn][maxn];
pair<int, int> last;
set<tuple<int, int, int> > forbid;

int bfs()
{
    queue<pair<int, int> > Q;
    Q.push({1, 0});
    dist[0][1] = 0;
    seen[0][1] = 1;
    par[0][1] = 0;

    while (!Q.empty())
    {
        int x = Q.front().first, p = Q.front().second;
        Q.pop();
        for (auto y: adj[x])
        {
            if (!seen[x][y] and forbid.find({p,x,y}) == forbid.end())
            {
                Q.push({y,x});
                seen[x][y] = 1;
                par[x][y] = p;
                dist[x][y] = dist[p][x] + 1;
                if (y == n)
                {
                    last = {x,y};
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m>>k;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 0; i < k; i++)
    {
        int a, b, c; cin>>a>>b>>c;
        forbid.insert({a,b,c});
    }

    if (!bfs())
    {
        printf("-1\n");
        return 0;
    }
    vector<int> path;
    int x = last.first, y = last.second;
    printf("%d\n", dist[x][y]);
    while (x != 0 and y != 1)
    {
        path.push_back(y);
        int temp = par[x][y];
        y = x;
        x = temp;
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for (auto u: path)
    {
        printf("%d ", u);
    }
    printf("\n");
}
