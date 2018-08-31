#include<iostream>
using namespace std;

int main()
{
	int n;cin>>n;
	long long a[n],ans=0;

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}

	for (int i = 0;i<n-1;i++)
	{
		for (int j=n;j>i+1;j--)
		{
			if (a[i] > a[j])
			{
				ans+= a[i] - a[j];
			}
			else
			{
				ans+= a[j] - a[i];
			}
		}
	}
	cout<<ans<<endl;
}




