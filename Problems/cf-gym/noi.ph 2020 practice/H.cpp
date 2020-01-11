#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	// ifstream cin("in.txt");
	
	int mod = pow(10,9) + 7;
	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;

		ll ans = 1, temp = 0;
		while (n--)
		{
			int x; cin>>x;
			if (x > 1)
			{
				ans*=(x*max((ll) 1,temp))%mod;
				temp = 0;
			}
			else temp+= x;
			ans%=mod;
		}
		if (ans == 1) ans=0;
		cout<<ans+temp<<endl;		
	}
}