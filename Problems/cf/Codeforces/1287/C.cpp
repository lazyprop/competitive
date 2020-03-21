#include<bits/stdc++.h>
using namespace std;

int main()
{
	ifstream cin("in.txt");
	
	int n; cin>>n;
	int ans = 0, prev = 0;
	int a[n], start = -1;
	
	int even = n/2;
	int odd = n - even;

	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		if (a[i] % 2) odd--;
		else even--;
	}
	
	

	cout<<ans<<endl;
}