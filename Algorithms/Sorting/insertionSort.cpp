#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[n];

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}

	//sort 
	
	for (int i = 0;i<n;i++)
	{
		int min = a[i];
		int k = i;
		for (int j = i;j<n;j++)
		{
			if (a[j]<min and j!= k+i+1)
			{
				min = a[j];
				k = j;
			}
		}
		
		
		// insert min at a[i]
		
		int temp = a[i];
		a[i] = min;

		
		for (int j = i+1;j<n;j++)
		{
			int t = a[j];
			a[j] = temp;
			temp = t;

		}
	}
	
	cout<<endl;
	for (int i = 0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}



