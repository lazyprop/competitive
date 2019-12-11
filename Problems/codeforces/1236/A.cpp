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
		int a,b,c; cin>>a>>b>>c;

		int x = min(b,c/2);
		b-=x;
		int y = min(a,b/2);
		cout<<(x+y)*3<<endl;
	}
}