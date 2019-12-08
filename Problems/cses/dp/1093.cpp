#include<bits/stdc++.h>
using namespace std;
 
const int mod = 1000000007;
int main()
{
 
	int n; cin>>n;
	int sum = (n*(n+1))/2;
 
	if (sum%2)
	{
		cout<<0<<endl;
		return 0;
	}
 
	int x = sum/2;
	int dp1[x+3] = {}, dp2[x+3] = {};
	dp1[1] = 1;
 
	for (int i = 2; i<=n; i++)
	{
		if (i%2)
		{
			for (int j = 0; j<=x; j++)
			{
				if (j)
				{
					dp1[j] = dp2[j];
					if (j>=i)
					{
						dp1[j]+= dp2[j-i];
						dp1[j]%= mod;
					}
				}
			}
		}
		else
		{
			for (int j = 0; j<=x; j++)
			{
				if (j)
				{
					dp2[j] = dp1[j];
					if (j>=i)
					{
						dp2[j]+= dp1[j-i];
						dp2[j]%= mod;
					}
				}
			}
		}
	}
	if (n%2)
	{
		cout<<dp1[x]<<endl;
	}
	else
	{
		cout<<dp2[x]<<endl;
	}
}