#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int x;
	cin>>x;
	 int a[n];

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	int r = 0;

	for (int i = 0;i<n;i++)
	{
		if (a[i] == x)
		{
			r = 1;
			break;
		}
	}
	cout<<r<<endl;
}

