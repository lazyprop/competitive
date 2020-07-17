#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 5005;
const int mod = pow(10,9);

int a[maxn][maxn];
int n, m;

int check(int i, int j, int x)
{
    int ans = 1;
    if (i) ans = ans & a[i-1][j] == x;
    if (j) ans = ans & a[i][j-1] == x;
    if (i and j) ans= ans & a[i-1][j-1] == x;
    return ans;
}


ll f(int i, int j)
{
    if (i >= n xor j >= m) return 1;
    if (abs(n-i) <= 2 and abs(m-j) <= 2) return 1;

    ll ans = 0;

    ll f1 = (f(i+2, j) ? f(i+2, j) : 1) * (f(i, j+2) ? f(i, j+2) : 1);
    ll f2 = (f(i+2, j) ? f(i+2, j) : 1) * (f(i+1, j+2) ? f(i+1, j+2) : 1);
    ll f3 = (f(i+2, j+1) ? f(i+2, j+1) : 1) * (f(i, j+2) ? f(i, j+2) : 1);

    if (!check(i, j, 1))
    {
        if (a[i][j]) return 1;
        ans+= f1;
        ans%= mod;
        ans+= f2;
        ans%= mod;
        ans+= f3;
    }

    if (!check(i, j, 2))
    {
        if (a[i][j]) return 1;
        ans+= f1;
        ans%= mod;
        ans+= f2;
        ans%= mod;
        ans+= f3;
    }
    ans%= mod;
    printf("(%d, %d): %lld\n", i, j, ans);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int k; cin>>n>>m>>k;
    for (int i = 0; i < k; i++)
    {
        int x, y, c; cin>>x>>y>>c;
        a[x][y] = c+1;
    }
    
    ll ans = 0;
    ans+= (f(0, 0) + f(0, 1)) % mod;
    ans+= (f(1, 0) + f(1, 1)) % mod;
    ans%= mod;
    printf("%lld\n", ans);
}
