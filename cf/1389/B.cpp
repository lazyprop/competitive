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
        int n, k, z; cin>>n>>k>>z;
        int a[n+2];
        for (int i = 1; i <= n; i++) cin>>a[i];

        int dp[n+2][3][z+1];
        memset(dp, 0, sizeof(dp));
        int ans = 0;
        for (int j = 0; j <= z; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                dp[i][0][j] = max(dp[i-1][0][j], dp[i-1][1][j]) + a[i];
                dp[i][1][j] = dp[i+1][0][j-1] + a[i];

                if (i-1+2*j <= k) ans = max({ans, dp[i][0][j], dp[i][1][j]});
            }
        }

        printf("%d\n", ans);
    }
}
