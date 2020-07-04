#include <bits/stdc++.h>
using namespace std;

#define ll long long

int f(ll x, ll target, ll n)
{
    if (n < 2) return n;
    if (x+1 == 2*target) return n%2;

    n/= 2; x/= 2;

    if (target > x+1)
    {
        target-= x+1;
    }
    return f(x, target, n);
}
    
int main()
{
    ll n, l, r; cin>>n>>l>>r;
    ll x = 1;
    ll temp = n;

    while (temp > 1)
    {
        temp/= 2;
        x*= 2;
    }
    x = x*2 - 1;

    int ans = 0;
    for (ll i = l; i <= r; i++)
    {
        ans+= f(x, i, n);
    }
    
    printf("%d\n", ans);
}
