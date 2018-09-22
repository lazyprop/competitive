#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;

	while (n!=-1)
	{
		int arr[n],sum=0;
		for(int i = 0;i<n;i++)
		{
			cin>>arr[i];
			sum+=arr[i];
		}

		if (sum%n == 0)
		{
			int avg = sum/n, ans=0;
			for (int i = 0;i<n;i++)
			{
				if (arr[i] < avg)
				{
					ans+= avg - arr[i];
				}
			}
			cout<<ans<<endl;
		}

		else
		{
			cout<<-1<<endl;
		}
		cin>>n;
	}
}

