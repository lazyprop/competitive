#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    vector<int> adj[n+100];

    for (int i = 0; i < n; i++)
    {
        string s; cin>>s;
        for (int j = 0, l = s.size(); j < l; j++)
        {
            int c = n + s[j] - 'a';
            adj[i].push_back(c);
            adj[c].push_back(i);
        }
    }

    int ans = 0, seen[n+100] = {};
    for (int i = n; i < n+26; i++)
    {
        if (!seen[i] and !adj[i].empty())
        {
            stack<int> s;
            seen[i] = 1;
            s.push(i);
            while (!s.empty())
            {
                int x = s.top(); s.pop();
                for (auto y: adj[x])
                {
                    if (!seen[y])
                    {
                        s.push(y);
                        seen[y] = 1;
                    }
                }
            }
            ans++;
        }
    }
    printf("%d\n", ans);
}
