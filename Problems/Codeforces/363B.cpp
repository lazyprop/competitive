#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k; cin>>n>>k;
	int arr[n],sum[n+1];
	memset(sum,0,sizeof(sum));
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
		if (sum>0)
		{
			sum[i]+= arr[i] + sum[i-1];
			cout<<sum[i]<<" ";
		}
	}
	cout<<endl;
	
	int m = INT_MAX, index=0;
	for (int i = k-1; i<n; i++)
	{
		cout<<arr[i]<<" "<<arr[i-k+1]<<endl;
		cout<<sum[i]-sum[i-k+1]<<endl;
		if (sum[i]-sum[i-k+1]<m)
		{
			m=sum[i]-sum[i-k+1];
			index=i-k+1;
		}
	}
	cout<<index+1<<endl;
}
