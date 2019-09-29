#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n; cin>>n;
	unsigned long long arr[n], arr2[n],sum[n],sum2[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
		if (i==0)
		{
			sum[i] = arr[i];
		}
		else
		{
			sum[i] = sum[i-1] + arr[i];
		}
		arr2[i] = arr[i];
	}
	sort(arr2,arr2+n);

	for (int i = 0; i<n; i++)
	{
		if (i==0)
		{
			sum2[i] = arr2[i];
		}
		else
		{
			sum2[i] = sum2[i-1] + arr2[i];
		}
		//cout<<sum[i]<<" ";
	}
	/*
	cout<<endl;
	for (int i = 0; i<n; i++)
	{
		cout<<sum2[i]<<" ";
	}
	cout<<endl;
	*/
	
	int m; cin>>m;
	while (m--)
	{
		int type,l,r;
		cin>>type>>l>>r;
		unsigned long long ans;
		if (l>1)
		{
			if (type==1)
			{
				ans = sum[r-1] - sum[l-2];
			}
			else
			{
				ans = sum2[r-1] - sum2[l-2];
			}
		}
		else
		{
			if (type==1)
			{
				ans = sum[r-1];
			}
			else
			{
				ans= sum2[r-1];
			}
		}
		cout<<ans<<endl;		
	}		
}

