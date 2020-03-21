#include<bits/stdc++.h>

using namespace std;

int main()
{
	int t=1;
	// cin>>t;
	while (t--)
	{
		// code
		int n,k; cin>>n>>k;
		int a[n];

		cin>>a[0];
		
		for (int i = 1; i<n; i++)
		{
			cin>>a[i];
		}
		sort (a,a+n);		

		int count= 0;
		for (int i = 0; i<n; i++)
		{
			int best = n;
			int l = i+1, r=n-1;
			while (l<=r)
			{
				int m = l + (r-l)/2;
				if (a[m] - a[i] >=k)
				{
					best = m;
					r = m-1;
				}
				else
				{
					l = m+1;
				}
			}
			count+= n-best;
		}
		cout<<count;
		cout<<endl;
	}
}