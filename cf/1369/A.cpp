#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int T = 1;
    cin>>T;
    while (T--)
    {
        int n; cin>>n;
        if (n%4 == 0) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
