#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, k;
int a[20], bonus[20][20];
ll dp[262146][20];

ll f(int mask, int ind)
{
    if (__builtin_popcount(mask) > m)
    {
        return INT_MIN;
    }

    if (dp[mask][ind] >= 0) return dp[mask][ind];

    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (!(mask & (1<<i)))
        {
            ll score = a[i] + bonus[ind][i];
            score+= f(mask | 1<<i, i);
            ans = max(ans, score);
        }
    }
    dp[mask][ind] = ans;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin>> a[i];
    }
    while (k--)
    {
        int x, y, c; cin>> x >> y >> c;
        bonus[x-1][y-1] = c;
    }
    memset(dp, -1, sizeof(dp));
    
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, a[i] + f(0 | 1<<i, i));
    }
    cout << ans << endl;
}
