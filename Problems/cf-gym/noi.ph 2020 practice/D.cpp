#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");

	int T; cin>>T;
	while (T--)
	{
		int n,b; cin>>n>>b;

		cout<<max(1, n-b)<<endl;
	}
}