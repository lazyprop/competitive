#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int arr[n], opt[n];
	
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
		opt[i] = 0;
	}

	for (int i = 0; i<n;i++)
	{
		int count;
		for (int j = 0; j<i; j++)
		{
			if (arr[j]>arr[i])
			{
				count=j-1;
				break;
			}
		}
		opt[i] = count;
	}
	int m=0;
	for (int i = 0; i<n; i++)
	{
		m = max(opt[i],m);
	}
	cout<<m<<endl;
}




