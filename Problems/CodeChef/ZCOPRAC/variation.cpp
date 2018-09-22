#include<iostream>
#include<algorithm>
using namespace std;

int search(long long a[], int n, long long  k,int i)
{
	int m = (n-1)/2;
	//cout<<m<<endl;
	if (m<=i)
	{
		return 0;
	}
	long long  tmp = a[m] - a[i];
	if (tmp>=k)
	{
		return 1;
	}
	
	else
	{
		search(a,m,k,i);
	}
}

int main()
{
	int n; cin>>n;
	long long k;cin>>k;
	long long a[n],ans=0;

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);

	for (int i = 0;i<n;i++)
	{
		cout<<search(a,n,k,i)<<endl;
	}
	cout<<ans<<endl;
}





