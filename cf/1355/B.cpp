#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("in.txt");

    int T; cin>>T;

    while (T--)
    {
        int n; cin>>n;
        int a[n];
        
        for (int i = 0; i < n; i++) cin>>a[i];
        sort(a,a+n);

        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur++;
            if (cur == a[i])
            {
                ans++;
                cur = 0;
            }
        }

        cout<<ans<<endl;
    }
}

