#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n,l; cin>>n>>l;
	int arr[n];
	for (int i = 0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);

	double md=arr[0]*2;
	for (int i = 0;i<n-1;i++)
	{
		if (arr[i+1] - arr[i] > md)
		{
			md = arr[i+1] - arr[i];
		}
	}
	
	if ((l-arr[n-1]) *2 > md)
	{
		md = (l-arr[n-1]) *2;
	}
	cout.precision(9);
	cout<<(double) md/2 <<endl;
}


