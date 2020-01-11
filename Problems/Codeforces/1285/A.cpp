#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ifstream cin("in.txt");

	int n; cin>>n;
	int l = 0, r= 0;	
	for (int i = 0; i<n; i++)
	{
		char c; cin>>c;
		if (c == 'L') l++;
		else r++;
	}

	cout<<l+r+1<<endl;
}