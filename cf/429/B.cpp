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
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m; cin>> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            dp1[i][j] = a[i][j];
            int delta = 0;
            if (i) delta = dp1[i-1][j];
            if (j) delta = max(delta, dp1[i][j-1]);

            dp1[i][j]+= delta;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            dp2[i][j] = a[i][j];
            int delta = 0;
            if (i < n-1) delta = dp2[i+1][j];
            if (j < m-1) delta = max(delta, dp2[i][j+1]);

            dp2[i][j]+= delta;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = m-1; j >= 0; j--)
        {
            dp3[i][j] = a[i][j];
            int delta = 0;
            if (i) delta = dp3[i-1][j];
            if (j < m-1) delta = max(delta, dp3[i][j+1]);
            dp3[i][j]+= delta;
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            dp4[i][j] = a[i][j];
            int delta = 0;
            if (i < n-1) delta = dp4[i+1][j];
            if (j) delta = max(delta, dp4[i][j-1]);
            dp4[i][j]+= delta;
        }
    }

    int ans = 0;

    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            ans = max(ans, dp1[i-1][j] + dp2[i+1][j] +
                    dp3[i][j+1] + dp4[i][j-1]);

            ans = max(ans, dp1[i][j-1] + dp2[i][j+1] + 
                    dp3[i-1][j] + dp4[i+1][j]);
        }
    }

    cout<<ans<<endl;
}
