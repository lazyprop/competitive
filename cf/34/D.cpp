#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r1, r2; cin>> n >> r1 >> r2;
    vector<int> adj[n+3];
    //cout<<"done\n";
    for (int i = 1; i <= n; i++)
    {
        if (i == r1) continue;
        int x; cin>>x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }
    //cout<<"done\n";

    int prev[n+3] = {};
    stack<int> s;
    s.push(r2);
    prev[r2] = -1;

    while (!s.empty())
    {
        int x = s.top(); s.pop();

        for (auto y: adj[x])
        {
            if (prev[y]) continue;
            prev[y] = x;
            s.push(y);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (i == r2) continue;
        cout<<prev[i]<<" ";
    }
    cout<<endl;
}
