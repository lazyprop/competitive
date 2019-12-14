#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        string s; cin>>s;
        int n = s.size();

        int l=0,u=0, r= 0, d= 0;
        for (int i = 0; i<n; i++)
        {
            if (s[i] == 'L') l++;
            else if (s[i] == 'U') u++;
            else if (s[i] == 'R') r++;
            else d++;
        }

        int minlr = min(l,r);
        int minud = min(u,d);

        string res = "";

        if (!minud and minlr)
        {
            res = "LR";
        }
        else if (minud and !minlr)
        {
            res = "UD";
        }
        else if (minud and minlr)
        {
            for (int i = 0; i<minlr; i++)
            {
                res+= 'L';
            }
            for (int i = 0; i<minud; i++)
            {
                res+= 'U';
            }
            for (int i = 0; i<minlr; i++)
            {
                res+= 'R';
            }
            for (int i = 0; i<minud; i++)
            {
                res+= 'D';
            }
        }

        cout<<res.size()<<endl;
        cout<<res<<endl;
    }
}