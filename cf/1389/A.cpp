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
        int l, r; cin>>l>>r;
        if (r < l*2) printf("-1 -1\n");
        else printf("%d %d\n", l, l*2);
    }
}
