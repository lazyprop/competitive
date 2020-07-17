#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    int a[n];
    for (int i = 1; i <= n; i++) cin>>a[i];
    sort(a+1,a+n+1);

    int q; cin>>q;
    while (q--)
    {
        int x; cin>>x;
        int l = 1, r = n, best = 0;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            if (a[mid] <= x)
            {
                best = mid;
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        printf("%d\n", best);
    }
}
