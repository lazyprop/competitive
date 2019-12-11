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
		int large = 0;
		vector<int> a(n);
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			large = max(large,a[i]);
		}
		sort(a.begin(), a.end());

		int ans = n;
		int mid = n/2;
		for (int i =0; i<n/2; i++)
		{
			for (;;)
			{
				if (a[i]*2 <= a[mid])
				{
					ans--;
					mid++;
					break;
				}
				else mid++;

				if (mid==n) break;
			}
			if (mid==n) break;
		}

		cout<<ans<<endl;
	}
}