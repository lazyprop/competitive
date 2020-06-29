#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        if (n%2)
        {
            cout<<"NO\n";
            continue;
        }

        if ((n/2) % 2)
        {
            cout<<"NO\n";
            continue;
        }

        cout<<"YES\n";

        int sum = 0;
        for (int i = 0; i < n/2; i++)
        {
            int x = (i+1) * 2;
            cout<<x<<" ";
            sum+= x;
        }


        int sum2 = 0;
        for (int i = 0; i < (n/2) - 1; i++)
        {
            int x = (i * 2) + 1;
            cout<<x<<" ";
            sum2+= x;
        }
        cout<<sum - sum2<<endl;
    }
}

