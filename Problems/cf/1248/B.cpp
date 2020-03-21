#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n] = {};
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		int l = 0, r = n-1;
		long long x = 0, y= 0;
		for (int i = 0; i<n/2; i++)
		{
			x+= a[i];
		}
		for (int i = n/2; i<n; i++)
		{
			y+= a[i];
		}
		long long ans =  x*x + y*y;
	
		cout<<ans;
		cout<<endl;
	}
}