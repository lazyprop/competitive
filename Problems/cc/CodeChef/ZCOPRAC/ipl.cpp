#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	
	int dp[n];
	dp[0] = arr[0];
	dp[1] = arr[1] + arr[0];
	dp[2] = max(arr[2] + arr[1], arr[2] + arr[0]);
	for (int i = 3; i<n; i++)
	{
		dp[i] = arr[i] + max(dp[i-1],max(dp[i-2],dp[i-3]));
	}
	for (int i = 0; i<n; i++)
	{
		cout<<dp[i]<<" ";
	}
	cout<<endl;
	cout<<max(dp[n-1],max(dp[n-2],dp[n-3]))<<endl;
}
