#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;

		int a[n][2];
		for (int i = 0; i<n;i++)
		{
			cin>>a[i][0]>>a[i][1];
		}

		int x = a[0][0];
		int ans = 1;
		for (int i = 1; i<n-1; i++)
		{
			if (a[i][0] - a[i][1] > x)
			{
				// fell left
				ans++;
				x = a[i][0];
				continue;
			}
			if (a[i+1][0] > a[i][0] + a[i][1])
			{
				// fell right
				x = a[i][0] + a[i][1];
				ans++;
				continue;
			}
			else x = a[i][0];
		}
		if (n > 1) ans++;
		cout<<ans<<endl;
	}
}