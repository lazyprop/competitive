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
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n],b[n];
		for (int i = 0; i<n; i++) cin>>a[i];
		for (int i = 0; i<n; i++) cin>>b[i];

		int l = 0, r=n-1;
		while (l<=r)
		{
			int flag = 0;
			if (a[l] == b[l])
			{
				l++;
				flag++;
			}
			if (a[r] == b[r])
			{
				r--;
				flag++;
			}
			if (!flag) break;
		}

		int k = 0;
		if (l < n) k = b[l] - a[l];
		string ans = "YES";
		for (int i = l+1; i<=r; i++)
		{
			if (b[i] - a[i] != k)
			{
				ans = "NO";
			}
		}
		if (k < 0) ans = "NO";
		cout<<ans<<endl;
	}
}