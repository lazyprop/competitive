//https://www.codechef.com/ZCOPRAC/problems/STRIMPOR
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);//fast io
    cin.tie(0);
    cout.tie(0);
    int t;//no of test cases
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;//the number of elements in the array, the length of the substring
        long long a[n + 1];//the original array
        long long x[n + 1], z[n + 1];//arrays to calculate the starting and ending points.
        //x[i] --> starting substrings at i, z[i] --> ending substrings at i
        long long x1[4] = {0}, z1[4] = {0};//aiding to calculate the starting and ending points.
        long long dp[n + 1];//used to optimise the code in the later stages
        //dp[i] --> minimum importance of substring of length k, till i
        for(long long i = 1; i <= n; i++)
        {
            char c;
            cin >> c;
            a[i] = c - 'X';//when character is X --> a[i] = 0, Y --> a[i] = 1, Z --> a[i] = 2
            x[i] = z[i] = dp[i] = 0;
        }
        for(long long i = n; i > 0; i--)
        {
            if(a[i] == 2)//character Z
                z1[i % 3]++;
            if(a[i] == 0)//character X
                x[i] = z1[(i - 1) % 3];
        }
        for(long long i = 1; i <= n; i++)
        {
            if(a[i] == 0)//character X
                x1[i % 3]++;
            if(a[i] == 2)//character Z
                z[i] = x1[(i + 1) % 3];
        }
        long long curr = 0;
        for(long long i = 1; i <= k; i++)
        {
            curr += x[i];//no of diff good substrings when we take range 1 to k
        }
        dp[k] = curr;
        for(long long i = k + 1; i <= n; i++)
        {
            curr -= z[i - k];//we don't care about these anymore
            curr += x[i];//new no of good substrings
            dp[i] = min(dp[i - 1], curr);
        }
        cout << dp[n] << endl;//answer
    }
    return 0;
}

