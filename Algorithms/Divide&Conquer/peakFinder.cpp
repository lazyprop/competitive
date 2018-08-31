// note: a peak is an element greater that its neighbours
//  	 not the largest element in the array
#include<iostream>
using namespace std;

int search(int a[], int n, int f, int l,int i)
{
	if (n==1)
	{
		return a[i];
	}

	int m = (n-1)/2;
	cout<<m<<endl;
	if (a[m] <1)
	{
		search(a,n/2,f,m,m);
	}
	if (a[m] < 1)
	{
		search(a,n/2,m+1,l,m);
	}
}

int main()
{
	int n; cin>>n;
	int a[n];
	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<search(a,n,0,n-1,0)<<endl;
}



