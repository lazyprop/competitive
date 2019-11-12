#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a[n] = {};
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}

		int l[n]={}, r[n] = {};

		for (int i = 1; i<n; i++)
		{
			l[i] = l[i-1];
			if (a[i-1] >= 0) l[i]++;
		}
		for (int i = n-2; i>=0; i--)
		{
			r[i] = r[i+1];
			if (a[i+1] <= 0) r[i]++;
		}

		int best = INT_MAX;
		for (int i = 1; i<n-1; i++)
		{
			if (a[i]) best = min(best, l[i] + r[i]);
			else best = min(best, l[i] + r[i]+1);
		}
		if (n==2)
		{
			best = 0;
			if (a[0] >= 0) best++;
			if (a[1] <= 0) best++;
		}
		
		cout<<best<<endl;
	}
}