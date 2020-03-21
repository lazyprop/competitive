//next round
#include<iostream>
using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	int a[n];

	for (int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	
	int ans = k;
	for (int i = k;i<n;i++)
	{
		if (a[i] >= a[k-1])
		{
			ans++;
		}
	}
	cout<<ans;
}





