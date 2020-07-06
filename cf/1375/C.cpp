#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        int first; cin>>first;
        for (int i = 1; i < n-1; i++)
        {
            int x; cin>>x;
        }
        int last; cin>>last;
        if (first < last) cout<<"YES\n";
        else cout<<"NO\n";
    }
}

