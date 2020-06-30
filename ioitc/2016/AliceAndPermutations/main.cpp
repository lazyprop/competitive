#include <bits/stdc++.h>
using namespace std;

#define ll long long

int MOD = pow(10,9) + 7;

ll modpow(ll a,ll b)
{
    ll ans = 1;
    while (b--)
    {
        ans*= a;
        ans%= MOD;
    }
    //cout<<ans<<endl;

    return ans;
}

ll modmultfact(ll a, ll b)
{
    for (ll i = 1; i <= b; i++)
    {
        a*= i;
        a%= MOD;
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T; cin>>T;
    while (T--)
    {
        ll n, k; cin>> n >> k;
        k = min(k, n);

        ll ans = modpow(k+1, n-k);
        ans = modmultfact(ans, k);
        cout<< ans << "\n";
    }
}
