#include<bits/stdc++.h>
using namespace std;

int m;
int dp[200000];

int modpow(int n)
{
	int res = 1;
	while (n--)
	{
		res*=2;
		res%= m;
	}
	return res;
}

int f(int n)
{
	if (n == 1) return 2;
	if (dp[n]) return dp[n];

	int res = modpow(n);

	vector<int> fact;
	fact.push_back(1);
	for (int i = 2; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			fact.push_back(i);
			if (n/i != i)
			{
				fact.push_back(n/i);
			}
		}
	}

	for (auto u : fact)
	{
		res-= f(u);
		res+= m;
		res%= m;
	}

	dp[n] = res;
	return res;
}

int main()
{
	// ifstream cin("in.txt");

	int n; cin>>n>>m;

	cout<<f(n)<<endl;
}