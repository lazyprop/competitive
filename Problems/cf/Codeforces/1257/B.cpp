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
		int x,y; cin>>x>>y;

		string ans = "YES";
		
		if (x>=y) ans = "YES";

		else if (x==1 or x==3) ans = "NO";
		else if (x==2 and y!=3) ans = "NO";

		cout<<ans<<endl;
	}
}