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

        for (int i = 0; i < n; i++)
        {
            int x; cin>>x;
            int neg = 1;
            if (i%2) neg = 0;

            if (x < 0 == neg) cout<<x;
            else cout<<-x;
            cout<<" ";
        }
        cout<<endl;
    }
}
