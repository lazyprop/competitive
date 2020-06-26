#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp1[1001][1001];
int dp2[1001][1001];
int dp3[1001][1001];
int dp4[1001][1001];
int a[1001][1001];

int main()
{
    int n, m; cin>> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    
    dp1[0][0] = a[0][0]
    dp2[n-1][m-1] = a[n-1][m-1];
    dp3[n-1][0] = a[n-1][0];
    dp4[0][m-1] = a[0][m-1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp1[i][j] = a[i][j];
            int delta = 0;
            if (i) delta = dp[i-1][j];
            if (j) delta = max(delta, dp[i][j-1]);

            dp1[i][j]+= delta;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m-1; j >= 0; j--)
        {
            dp3[i][j] = a[i][j];
            int delta = 0;
            if (i) delta = dp[i-1][j];
            if (j) delta = max(delta, dp[i][j-1]);

            dp1[i][j]+= delta;
        }
    }
}
