#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 2e5 + 7;

vector<int> v[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    while (T--)
    {
        int n, k; cin>>n>>k;
        ll a[n];
        for (int i = 0; i < n; i++) cin>>a[i];

        ll w[k];
        for (int i = 0; i < k; i++)
        {
            cin>>w[i];
        }

        for (int i = 0; i <= n; i++) v[i].clear();
        sort(a, a+n);
        sort(w, w+k);

        for (int i = 0; i < k/2; i++)
        {
            swap(w[i], w[k-i-1]);
        }
        int x = 0;
        for (int i = 0; i < n-k; i++)
        {
            while (w[x] == v[x].size()+1) x++;
            v[x].push_back(a[i]);
        }

        ll ans = 0;
        int y = 1;
        for (int i = 0; i < k; i++)
        {
            ans+= a[n-i-1];
            if (v[i].size()) ans+= v[i][0];
            else
            {
                ans+= a[n-y];
                y++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
