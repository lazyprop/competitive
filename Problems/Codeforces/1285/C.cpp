#include <bits/stdc++.h>

using namespace std;

#define ll long long


int main()
{
	// ifstream cin("in.txt");

	ll x; cin >> x;

	ll small = LLONG_MAX;

	for(ll i = 1; i*i <= x; i++)
	{
		if(x % i == 0 and __gcd(i, x / i) == 1)
		{
			small = min(small, max(i, x/i));
		}
	}

	cout<<min(x/small, small)<<" "<<max(x/small, small)<<endl;
}