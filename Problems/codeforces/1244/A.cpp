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
		float a,b,c,d;
		int k;
		cin>>a>>b>>c>>d>>k;
		int x = ceil(a/c);
		int y = ceil(b/d);

		if (x+y > k)
		{
			cout<<-1<<endl;
		}
		else
		{
			cout<<x<<" "<<y<<endl;
		}
	}
}