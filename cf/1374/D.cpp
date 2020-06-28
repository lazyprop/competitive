#include <bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
    int T = 1;
    cin>>T;
    while (T--)
    {
        ll n, k; cin>>n>>k;
        map<int, int> freq = {};

        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ll x; cin>>x;
            ll mod = (k - (x % k) + k) % k;

            if (!mod) continue;

            ans = max(ans, mod + (k * freq[mod]));
            freq[mod]++;
        }

        if (ans) ans++;
        cout<<ans<<endl;
    }

    return 0;
}
