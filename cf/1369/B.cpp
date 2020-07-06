#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T = 1;
    cin>>T;
    while (T--)
    {
        int n; cin>>n;
        string s; cin>>s;

        string test = s;
        sort(test.begin(), test.end());
        if (s == test)
        {
            cout<<s<<endl;
            continue;
        }

        int x = 0, y = 0;
        while (s[x] == '0') x++;
        for (int i = n-1; s[i] == '1' and i >= 0; i--) y++;

        x++;
        while (x--) cout<<"0";
        while (y--) cout<<"1";
        cout<<endl;
    }
    return 0;
}
