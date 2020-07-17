#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1000000 + 10;
const int k = 25;

int a[maxn];
int lgg[maxn];
pair<int, int> st[maxn][k];

ll f(int l, int r)
{
    if (r < l) return -1;
    if (r == l) return 0;

    int j = lgg[r-l+1];
    int big, ind;
    if (st[l][j] > st[r - (1<<j) + 1][j])
    {
        big = st[l][j].first;
        ind = st[l][j].second;
    }
    else
    {
        big = st[r - (1<<j) + 1][j].first;
        ind = st[r - (1<<j) + 1][j].second;
    }

    ll ans = 0;
    ll x1 = f(l, ind-1), x2 = f(ind+1, r);

    if (x1 != -1) ans+= big+x1;
    if (x2 != -1) ans+= big+x2;

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    for (int i = 0; i < n; i++) cin>>a[i];

    lgg[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        lgg[i] = lgg[i/2] + 1;
    }

    for (int i = 0; i < n; i++)
    {
        st[i][0] = {a[i],i};
    }

    for (int j = 1; j <= k; j++)
    {
        for (int i = 0; i + (1<<j) <= n; i++)
        {
            pair<int, int> x1 = st[i][j-1], x2 = st[i+(1<<(j-1))][j-1];
            if (x1.first > x2.first)
            {
                st[i][j] = x1;
            }
            else
            {
                st[i][j] = x2;
            }
       }
    }

    printf("%lld\n", f(0,n-1));
}
