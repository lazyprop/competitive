#include<iostream>
using namespace std;

void sort(int a[],int n)
{
	for (int i = 0;i<n;i++)
	{
		for (int j=i+1;j<n;j++)
		{
			if (a[j] < a[i])
			{
				int temp = a[j];
				a[j] = a[i];
				a[i] = temp;
			}
		}
	}
	
}
int main()
{
	int t;
	cin>>t;

	for (int x=0;x<t;x++)
	{
		int n;
		cin>>n;

		int m[n],w[n];

		for (int i = 0;i<n;i++)
		{
			cin>>m[i];
		}
		for (int i = 0;i<n;i++)
		{
			cin>>w[i];
		}

		sort(m,n);
		sort(w,n);

		int a= 0;
		for (int i = 0;i<n;i++)
		{
			a+= m[i] * w[i];	
		}
		cout<<a<<endl;
	}
	
}







