#include<iostream>
using namespace std;

int main()
{
	int n,k; cin>>n>>k;
	int arr[n],ans=0;
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}

	for (int i = 0; i<n-1; i++)
	{
		int d = k-arr[i]-arr[i+1];
		if (d>0)
		{
			arr[i+1]+=d;
			ans+=d;
		}

	}
	cout<<ans<<endl;
	for(int i = 0; i<n; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
