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
	
	// sort
	
	for (int i = 0;i<n;i++)
	{
		int min = a[i];
		int k = i;
		for (int j = i;j<n;j++)
		{
			// find minimum value 
			if (a[j] < min)
			{
				min = a[j];
				k = j;
			}		
			
			// replace it with current element
			int temp = a[i];
			a[i] = min;
			a[k] = temp;
			
		}
	}
	cout<<endl;
	for (int i = 0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
}
