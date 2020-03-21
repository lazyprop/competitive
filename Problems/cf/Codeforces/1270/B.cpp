#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int small = INT_MAX, large = 0;
		int l = 0 , r = 0;
		int a[n];

		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		int flag = 0;
		for (int i = 1; i<n; i++)
		{
			if (abs(a[i] - a[i-1]) > 1)
			{
				cout<<"YES"<<endl;
				cout<<i<<" "<<i+1<<endl;
				flag = 1;
				break;
			}
		}
		if (!flag) cout<<"NO"<<endl;
	}
}