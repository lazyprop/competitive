#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        int n, m; cin>>n>>m;
        int seen[1010] = {};
        for (int i = 0; i < n; i++)
        {
            int x; cin>>x;
            seen[x]++;
        }

        int a[m];
        for (int i = 0; i < m; i++) cin>>a[i];

        string ans = "NO";
        int fa;
        for (int i = 0; i < m; i++)
        {
            if (seen[a[i]])
            {
                ans = "YES";
                fa = a[i];
                break;
            }
        }
        cout<<ans;
        if (ans == "YES") cout<<"\n1 "<<fa;
        cout<<endl;
    }
}
