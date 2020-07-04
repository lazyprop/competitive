#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        if (n%2 == 0)
        {
            cout<<n/2<<endl;
        }
        else
        {
            cout<<((n-1)/2)+1<<endl;
        }
    }
}
