#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	string arr;
	int ones[n];
	int f = 0;
	for (int i = 0; i<n; i++)
	{
		ones[i] = 0;
		cin>>arr[i];
		if (arr[i] == '1' and f==0)
		{
			ones[i] = 1;
			f = 1;
		}
		if (f==1 and i>0)
		{
			ones[i]+=ones[i-1];
			if (arr[i] == '1')
			{
				ones[i]++;
			}
		}
	}

	int ans=0, opt[n][n];
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			opt[i][j] = 0;
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = i; j<n; j++)
		{
			
			//cout<<s<<endl;
			int count=0, flag=0;
			
			for (int k = i; k<=j; k++)
			{
				if (arr[k] == '0')
				{
					flag=1;
				}
				opt[i][j]++;
				if (i>0)
					//opt[i][j]+=ones[i-1];
				//cout<<arr[k]<<" "<<flag<<endl;
				if (arr[k] == '1' and flag)
				{
					break;
				}
			}
			//cout<<opt[i][j]<<endl<<endl;
			
		}
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
		{
			ans = max(ans,opt[i][j]);
			cout<<opt[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<ans<<endl;
}