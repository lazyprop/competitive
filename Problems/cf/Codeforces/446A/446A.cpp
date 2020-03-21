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
		int a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		int l[n+10]={},r[n+10] = {};
		l[0] = 1;
		for (int i = 1; i<n; i++)
		{
			if (a[i] > a[i-1])
			{
				l[i] = l[i-1]+1;
			}
			else
			{
				l[i] = 1;
			}
		}
		r[n-1] = 1;
		for (int i = n-2; i>=0; i--)
		{
			if (a[i] < a[i+1])
			{
				r[i] = r[i+1]+1;
			}
			else
			{
				r[i]= 1;
			}
		}
		int ans = 0;
		for (int i = 0; i<n; i++)
		{
			ans = max(ans,l[i] + r[i]-1);
			if (i>0) ans = max(ans,l[i-1]+1);
			if (i<n-1) ans = max(ans,r[i+1]+1);

			if (i>0 and i<n-1 and a[i-1] + 1 < a[i+1])	
			{
				ans = max(ans,l[i-1] + r[i+1] + 1);
			}
		}
		cout<<ans<<endl;
	}
}