#include<iostream>
using namespace std;

int search(int arr[],int a,int b,int x)
{
	if (b>=a)
	{
		int m = a + (b-1)/2;
		if (arr[m] == x)
		{
			return m;
		}
		else
		{
			if (arr[m] > x)
			{
				return search(arr,a,m-1,x);
			}
			else
			{
				return search(arr,m+1,b,x);
			}
		}
	}
	else
	{
		return -1;
	}
}
int main()
{
	int n,x; cin>>n>>x;
	int a[n];
	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}

	cout<<search(a,0,n-1,x)<<endl;
}
