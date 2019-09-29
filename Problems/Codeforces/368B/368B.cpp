#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m; cin>>n>>m;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}

	int discovered[100001], dp[n+1];
	memset(discovered,0,sizeof(discovered));
	memset(dp,0,sizeof(dp));

	for (int i = n-1; i>=0; i--)
	{
		if (!discovered[arr[i]-1])
		{
			dp[i]+=1+dp[i+1];
			discovered[arr[i]-1]=1;
		}
		else
		{
			dp[i] = dp[i+1];
		}
	}
	
	for (int i = 0; i<m; i++)
	{
		int temp; cin>>temp;
		cout<<dp[temp-1]<<endl;
	}
}


