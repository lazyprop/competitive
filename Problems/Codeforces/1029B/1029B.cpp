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
	
	int m = 0;
	for (int i = 0; i<n; ++i)
	{
		int count=0;
		for (int j = i; j<n; ++j)
		{
			//cout<<j<<endl;
			if (arr[j] <= 2*arr[i])
			{
				++count;
			}
			else
			{
				i=j-1;
				break;
			}
		}
		m = max(m,count);
	}
	cout<<m<<endl;
}
