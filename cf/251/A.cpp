#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, d; cin>>n>>d;
    int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ll ind = upper_bound(a, a+n, a[i]+d) - a;
        ind--;
        ll len = ind - i + 1;
        if (len > 2)
        {
            ans+= (ll) ((len-2) * (len-1)) / 2;
        }
    }
    printf("%lld\n", ans);
}
