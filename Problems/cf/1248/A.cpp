#include<bits/stdc++.h>

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		long long oddp = 0, evenp = 0;
		for (int i = 0; i<n; i++)
		{
			int a; cin>>a;
			if (a%2 == 1) oddp++;
			else evenp++;
		}
		int m; cin>>m;
		long long oddq = 0, evenq = 0;
		for (int i = 0; i<m; i++)
		{
			int a; cin>>a;
			if (a%2 == 1) oddq++;
			else evenq++;
		}
		long long a,b,ans;
		a = oddq * oddp;
		b = evenq * evenp;
		ans = a+b;
		cout<<ans<<endl;
	}
}