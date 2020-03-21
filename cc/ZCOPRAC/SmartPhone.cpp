#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;
	cin>>n;
	long long a[n];

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}


	//sort
	sort(a,a+n);
	

	long long budg = 0;
	for (int i = 0;i<n;i++)
	{
		long long temp = a[i] * (n-i);
		if (temp > budg)
		{
			budg = temp;
		}
	}
	cout<<budg<<endl;
}



					

