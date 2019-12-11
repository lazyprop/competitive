#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int a[n];
		vector<int> cuts;
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			if (i)
			{
				if (a[i-1] != a[i])
				{
					cuts.push_back(i);
				}
			}
		}

		int x = cuts.size();

		// find best cut <= n/2
		int l = 0, r= x-1;
		int right = 0;
		while (l<=r)
		{
			int m = l+ (r-l)/2;
			if (cuts[m] <= n/2)
			{
				right = m;
				l = m+1;
			}
			else
			{
				r = m-1;
			}
		}

		
		cout<<g<<" "<<s<<" "<<b<<endl;
	}
}