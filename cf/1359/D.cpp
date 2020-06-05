#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    int a[n];
    for (int i = 0; i < n; i++) cin>>a[i];

    long long ans = 0, inf = 10000000;
    for (int x = 0; x <= 30; x++)
    {
        long long cur = 0, best = 0;

        for (int i = 0; i < n; i++)
        {
            int num = a[i];
            if (num > x) num = -inf;

            cur+= num;
            best = min(best, cur);
            ans = max(ans, (cur-best) - x);

        }
    }

    cout<<ans<<endl;
}
