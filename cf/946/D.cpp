#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, maxk; cin>> n >> m >> maxk;
    int g[n][maxk+1];
    for (int i = 0; i < n; i++)
    {
        string s; cin>> s;
        int start = 0, end = m-1;
        while (s[start] != '1' and start < m) start++;
        while (s[end] != '1' and end > start) end--;

        int len = end - start + 1;
        int j = 1;
        int hl[maxk+1], hr[maxk+1];
        hl[0] = len;
        hr[0] = len;

        for (int x = start+1; x < end; x++)
        {
            if (s[x] == '1')
            {
                hl[j] = len - (x - start);
                j++;
            }
        }

        j = 1;
        for (int x = end-1; x >= start; x--)
        {
            if (s[x] == '1')
            {
                hr[j] = len - (end - x);
                j++;
            }
        }

        for (int k = 0; k <= maxk; k++)
        {
            for (int x = 0; x <= k; x++)
            {
                g[i][k] = min(g[i][k], hl[x] + hr[k-x]);
            }
        }
    }
    
    int dp[n][maxk+1][maxk+1], best[n][maxk+1];
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k <= maxk; k++)
        {
            for (int j = 0; j <= k; j++)
            {
                dp[i][j][k] = best[i][k] + g[i][k-j];
            }
        }
    }
}
