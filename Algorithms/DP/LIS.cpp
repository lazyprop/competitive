#include<iostream>
using namespace std;

int dp[1000000];
int main()
{
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	dp[0] = 1;
	for (int i = 1; i<n; i++)
	{
		dp[i] =1;
		for (int j = 0; j<i; j++)
		{
			if (arr[j] <= arr[i])
			{
				dp[i] = max(dp[i],1+dp[j]);
			}
		}
	}
	cout<<dp[n-1]<<endl;
}



	
