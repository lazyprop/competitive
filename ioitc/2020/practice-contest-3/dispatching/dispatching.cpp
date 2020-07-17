#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 3005;

int n, m;
vector<int> adj[maxn];
ll c[maxn], l[maxn];

ll f(int man)
{
    vector<int> nodes;
    int seen[n+3] = {};
    stack<int> S;
    S.push(man);
    seen[man] = 1;
    seen[0] = 1;

    while (!S.empty())
    {
        int x = S.top(); S.pop();
        nodes.push_back(c[x]);

        for (auto y: adj[x])
        {
            if (!seen[y])
            {
                S.push(y);
                seen[y] = 1;
            }
        }
    }
    sort(nodes.begin(), nodes.end());

    ll sum = 0;
    int count = 0;
    //printf("%d\n\t", man);
    //printf("nodes = ");
    for (auto u: nodes)
    {
        if (sum+u <= m)
        {
            sum+= u;
            count++;
        }
        //printf("%d ", u);
    }
    //printf("\n\t");
    ll res = count * l[man];
    //printf("res = %lld count = %d\n", res, count);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for (int i = 1; i <= n; i++)
    {
        int b; cin>>b>>c[i]>>l[i];
        adj[b].push_back(i);
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, f(i));
    }
    printf("%lld\n", ans);
}
