#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    int T = 1;
    cin>>T;
    while (T--)
    {
        ll n; cin>>n;

        ll temp = n;
        int three = 0, two = 0;
        while (temp % 3 == 0)
        {
            temp/= 3;
            three++;
        }
        while (temp % 2 == 0)
        {
            temp/= 2;
            two++;
        }

        if (temp != 1 or two > three)
        {
            cout<<-1<<endl;
            continue;
        }

        cout<<(2 * three) - two<<endl;
    }
    return 0;
}
