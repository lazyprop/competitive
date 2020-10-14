#include<iostream>
using namespace std;

int main()
{
	int n; cin>>n;
	int arr[n];

	for (int i =0;i<n;i++)
	{
		cin>>arr[i];
	}

	int c=0;
	for (int i = 0;i<n;i++)
	{
		for (int j=n-1; j>=i;j--)
		{
			int flag=1;
			for (int k = i;k<=j;k++)
			{
				cout<<arr[k]<<" ";
				if (arr[k] != arr[n-k+1])
				{
					flag=0;
					break;
				}
			}
			c+=flag;
		}
	}
	cout<<c<<endl;
}