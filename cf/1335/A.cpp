// why DOJ ?
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin>>T;
    while (T--)
    {
        int n; cin>>n;
        if (n%2 == 0) cout<<n/2 - 1<<endl;
        else cout<<n/2<<endl;
    }
}
