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
		int h,n; cin>>h>>n;
		int a[n+10] = {};
		for (int i = 0; i<n; i++)
		{
			cin>>a[i];
		}
		int cryst = 0;
		for (int i = 0; i<n-1;)
		{
			if (a[i+1] - a[i+2] != 1)
			{
				cryst++;
				i++;
			}
			else i+=2;
		}
		cout<<cryst<<endl;
	}
}