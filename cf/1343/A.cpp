#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin>>T;
    while (T--)
    {
        long long n; cin>>n;
        
        for (int i = 2; i <= 40; i++)
        {
            if (n%((1ll<<i)-1)==0)
            {
                cout<< n/((1ll<<i)-1);
                break;
            }
        }
        cout<<endl;
    }
}

