#include<bits/stdc++.h>
using namespace std;

#define ll unsigned long long

ll count(ll n,ll x)
{
	ll res = 0;
	while (x<=n)
	{
		res+= (n/x);
		x*=x;
		//cout<<res<<endl;
	}
	return res;
}


int main()
{
	ll n; cin>>n;

	if (n%2)
	{
		cout<<0<<endl;
	}
	else
	{
		ll ans = count(n,10);
		
		ll x = 50;
		for (int i = 0; x<=n; i++)
		{
			ans+= count(n,x);
			x*=5;
		}
		cout<<ans<<endl;
	}
}