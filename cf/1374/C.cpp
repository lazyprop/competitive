#include <bits/stdc++.h>
using namespace std;

int flog(int n, int x)
{
    int ans = 0;
    int base = x;
    while (x < n)
    {
        x*= base;
        ans++;
    }
    
    if (x == n) return ans;
    return 0;
}
    
int main()
{
    int T = 1;
    cin>>T;
    while (T--)
    {
        int n; cin>>n;
        string s; cin>>s;

        int ans = 0, bal = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ')' and bal <= 0)
            {
                ans++;
                continue;
            }

            if (s[i] == '(') bal++;
            else bal--;
            //cout<<bal<<" ";
        }
        //cout<<endl;

        cout<<ans<<endl;
    }

    return 0;
}
