#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T = 1;
    cin>>T;
    while (T--)
    {
        int x, y, n; cin>>x>>y>>n;
        int f = n / x;
        if ((f*x) + y > n) cout<<(f-1) * x + y;
        else cout<<f*x + y;
        cout<<endl;
    }

    return 0;
}
