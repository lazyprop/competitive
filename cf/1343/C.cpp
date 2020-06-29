#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }

        long long ans = 0;

        int state = 1;

        for (int i = 0; i < n;)
        {
            state = a[i] > 0;
            int x = INT_MIN;
            while (a[i] > 0 == state)
            {
                x = max(x, a[i]);
                i++;
            }
            x+= 0;
            cout<<"";
            ans+= x;
        }

        cout<<ans<<endl;
    }
}
