#include<bits/stdc++.h>
using namespace std;

int f()
{
    int wl, dl, wr, dr;
    cin>>wl>>dl>>wr>>dr;

    if (!wl)
    {
        wl = f();
    }
    
    if (!wr)
    {
        wr = f();
        
    }

    if (!wl or !wr) return 0;

    if (wl * dl == wr * dr)
    {
        return wl + wr;
    }

    return 0;
}

int main()
{
    int T; cin>>T;
    while (T--)
    {
        int ans = f();
        //cout<<ans.first<<" "<<ans.second<<endl;

        if (ans) cout<<"YES\n";
        else cout<<"NO\n";

        if (T) cout<<endl;
    }
    return 0;
}
