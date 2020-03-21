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
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		sort(a,a+n);
		int ans = 0;
		for (int i = n-1; i>=0; i--)
		{
			ans++;
			if (a[i] < ans)
			{
				ans--;
				break;
			}
		}
		cout<<ans<<endl;
	}
}	