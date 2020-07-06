#include <bits/stdc++.h>
using namespace std;

int n, m;

int neighbors(int i, int j)
{
    int ans = 0;
    ans+= i > 0;
    ans+= j > 0;
    ans+= i < n-1;
    ans+= j < m-1;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin>>T;
    while (T--)
    {
        cin>>n>>m;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x; cin>>x;
                ans|= x > neighbors(i, j);
            }
        }

        if (ans)
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<<neighbors(i, j)<<" ";
            }
            cout<<endl;
        }
    }
}

