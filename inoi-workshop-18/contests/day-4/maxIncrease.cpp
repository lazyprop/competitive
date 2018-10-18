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
	opt[0] = 1;
	int size=1;
	for (int i = 1; i<n; i++)
	{
		if (arr[i] > arr[i-1])
		{
			opt[i]+=1+opt[i-1];
		}
		else
		{
			opt[i] = 1;
		}
	}
	int m=0;
	for (int i = 0; i<n; i++)
	{
		m = max(opt[i],m);
	}
	cout<<m<<endl;
}




