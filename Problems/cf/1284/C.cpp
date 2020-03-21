#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ifstream cin("in.txt");
	int n,mod; cin>>n>>mod;
	ll fact[n+1];
	fact[0] = 1;
	for (int i = 1; i<= n; i++)
	{
		fact[i] = (ll) i * fact[i-1];
		fact[i]%= mod;
	}

	ll ans = 0;
	ans%= mod;

	for (int k = 0; k < n; k++)
	{
		ans+= fact[k+1] * fact[n-k-1] * (n-k) * (n-k);
		ans%= mod;
		// cout<<ans<<endl;
	}
	cout<<ans<<endl;
}