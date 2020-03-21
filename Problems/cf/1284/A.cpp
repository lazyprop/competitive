#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");
	int n, m; cin>>n>>m;
	string a[n], b[m];

	for (int i = 0; i<n; i++) cin>>a[i];
	for (int i = 0; i<m; i++) cin>>b[i];

	int Q; cin>>Q;
	while (Q--)
	{
		int t; cin>>t;
		t--;
		cout<<a[t%n]<<b[t%m]<<endl;
	}
}