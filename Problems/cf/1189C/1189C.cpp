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
		int a[n], pre[n+1];
		pre[0] = 0;
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
			pre[i+1] = pre[i] + a[i];
		}

		int q; cin>>q;
		while (q--)
		{
			int l,r; cin>>l>>r;
			cout<<(pre[r] - pre[l-1]) / 10<<endl;
		}
	}
}