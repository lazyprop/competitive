#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        int c[n];
        for (int i = 0; i < n; i++) cin>>c[i];

        int q; cin>>q;
        while (q--)
        {
            int a[n];
            for (int i = 0; i < n; i++)
            {
                int x; cin>>x;
                a[i] = c[x];
            }
            
            // lis(a[])
            map<int, int> mp;
            int dp[n];

            dp[0] = 1;
            for (int i = 1; i < n; i++)
            {
                dp[i] = 1;
                if (a[i] >= a[i-1]) dp[i] = 1 + dp[i-1];


            }

        }
    }

}
