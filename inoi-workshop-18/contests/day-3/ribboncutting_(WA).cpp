#include<bits/stdc++.h>
using namespace std;

int f(int n,int dp[],s)
{
	if (dp[n] == -1)
	{
		int mn = 0;
		for (int i = 0; i<s; i++)
		{
			if (s[i] <=n)
			{
				mn = max(mn, f(n-s[i])+1);
			}
		}
	}
}
int main()
{
	int n,arr[3];
	cin>>n>>arr[0]>>arr[1]>>arr[2];
	sort(arr,arr+3);
	int count=0;
	for (int i = 0; i<n; i++)
	{
		if (arr[i] <= n)
		{
			count+=n/arr[i];
			n = n%arr[i];
		}		
	}
	cout<<count<<endl;
}