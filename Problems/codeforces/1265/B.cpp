#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{

		int n; cin>>n;
		pair<int,int> a[n];
		for (int i = 0; i<n; i++)
		{
			cin>>a[i].first;
			a[i].second = i;
		}
		sort(a,a+n);

		int big = a[0].second, small = a[0].second;
		cout<<1;
		for (int i = 1; i<n; i++)
		{
			small = min(small,	a[i].second);
			big = max(big, a[i].second);
			if (big-small != i)
			{
				cout<<0;
			}
			else
			{
				cout<<1;
			}
		}
		cout<<endl;
	}
}