#include<bits/stdc++.h>
using namespace std;

#define ll long long
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n;
	ll a[n+1], b[n+1] = {};
	
	ll ans = -1e15;
	
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		ans = max(ans, a[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		cin>>b[i];
		b[i]+= b[i-1];
	}

	ll diff = a[1] - b[1];
	ll sum = a[1];
	
	for (int i = 2; i <= n; i++)
	{
		diff = max(diff, a[i-1] - b[i-1]);
		sum = max(sum, a[i-1] + b[i-2]);

		ans = max(ans, a[i] + diff + b[i-1]);
		ans = max(ans, a[i] + sum + b[n] - b[i]);
	}

	cout<<ans<<endl;
}