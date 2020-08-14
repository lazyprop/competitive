// viewed solution :(

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
		string s; cin>>s;

		for (int l = 0; l<n;)
		{
			int r = l+1;
			while (r<n and s[r-1] == '1')
			{
				r++;
			}

			sort(a+l,a+r);
			l=r;
		}

		string ans="YES";
		for (int i =0; i<n; i++)
		{
			if (a[i] != i+1)
			{
				ans="NO";
				break;
			}
		}
		cout<<ans<<endl;
	}
}