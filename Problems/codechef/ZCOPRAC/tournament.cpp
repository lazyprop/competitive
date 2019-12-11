#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int n;cin>>n;
	long long a[n],ans=0;

	for (int i = 0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);

	for (int i = 0;i<n;i++)
	{
		ans += (a[i] * i) - (a[i]*(n-i-1));
	}
	cout<<ans<<endl;
}




