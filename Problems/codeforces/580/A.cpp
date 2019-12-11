#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int arr[n];
	for (int i = 0; i<n; i++)
	{
		cin>>arr[i];
	}
	int m = 1, count=1;
	for (int i = 1; i<n; i++)
	{
		if (arr[i] >= arr[i-1])
		{
			count++;
		}
		else
		{
			if (m<count)
			{
				m=count;
			}
			count=1;
		}
		if (m<count)
		{
			m = count;
		}
	}
	cout<<m<<endl;
}
			

