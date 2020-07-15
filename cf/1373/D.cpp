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
        int n; cin>>n;
        int a[n+1];
        for (int i = 1; i <= n; i++) cin>>a[i];

        ll dp[n+1][3] = {};
        for (int i = 1; i <= n; i++)
        {
            int x = i%2 ? 0 : a[i];
            dp[i][0] = max(dp[i][0], dp[i-1][0] + x);
        }

        cout<<max({dp[n][0], dp[n][1], dp[n][2]})<<endl;
    }
}
