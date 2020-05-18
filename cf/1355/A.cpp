#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("in.txt");

    int T; cin>>T;
    while (T--)
    {
        ll a, k; cin>>a>>k;

        for (int i = 1; i < k; i++)
        {
            ll temp = a;
            int maxdig = -1, mindig = 10;
            while (temp)
            {
                if (temp % 10 < mindig) mindig = temp % 10;
                if (temp % 10 > maxdig) maxdig = temp % 10;
                temp /= 10;
            }

            if (mindig * maxdig == 0) break;
            a += mindig*maxdig;
        }
        cout<<a<<endl;
    }
}
