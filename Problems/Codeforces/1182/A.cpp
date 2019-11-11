#include<bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		if (n%2)
		{
			cout<<0<<endl;
		}
		else
		{
			cout<<(int) pow(2,n/2)<<endl;
		}
	}
}