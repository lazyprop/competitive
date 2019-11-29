#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int d(ll n)
{
	int x = 0;
	while (n>0)
	{
		x++;
		n/=10;
	}
	return x;
}

int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a,b,x; cin>>a>>b>>x;

	ll l = 0, r = 1000000000, best=0;
	while (l<=r)
	{
		ll m = l + (r-l)/2;

		if ((ull) a*m + b*d(m) <= x)
		{
			l = m+1;
			best = m;
		}
		else
		{
			r = m-1;
		}
	}
	cout<<best<<endl;
}