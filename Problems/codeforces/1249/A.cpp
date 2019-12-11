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
		int a[n];
		for (int i = 0; i<n; i++) cin>>a[i];
		
		sort(a,a+n);
		int ans = 1;
		for (int i = 1; i<n; i++)
		{
			if (a[i] - a[i-1] == 1)
			{
				ans++;
				break;
			}
		}
		cout<<ans<<endl;
	}
}