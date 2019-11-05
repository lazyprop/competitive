#include<bits/stdc++.h>

using namespace std;

#define size 100010
#define ll long long
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n], freq[100010]={};
		int large=0;
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			freq[a[i]]++;
			large = max(large,a[i]);
		}

		ll dp[size];
		dp[0] = 0;
		dp[1] = freq[1];
		for (int i=2; i<=size-5; i++)
		{
			dp[i] = max(dp[i-1],dp[i-2] +(ll)freq[i]*i);
		}
		cout<<dp[size-5]<<endl;
	}
}