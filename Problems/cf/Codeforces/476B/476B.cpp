#include<bits/stdc++.h>

using namespace std;

#define make_graph(m,G) for(int i=0;i<m;i++){int a,b;cin>>a>>b;G[a-1].push_back(b-1);G[b-1].push_back(a-1);}
#define make_dir_graph(m,G) for(int i=0;i<m;i++){int a,b;cin>>a>>b;G[a-1].push_back(b-1);}
#define make_weighted_graph(m,G,w) for(int i=0;i<m;i++){int a,b;cin>>a>>b;cin>>w[a-1][b-1];w[b-1][a-1]=w[a-1][b-1];G[a-1].push_back(b-1); G[b-1].push_back(a-1);}
#define make_weighted_dir_graph(m,G,w) for(int i=0;i<m;i++){int a,b;cin>>a>>b;cin>>w[a-1][b-1];G[a-1].push_back(b-1);}

double factorial(double n)
{
	return tgamma(n+1);
}
int main()
{
	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		string orig,s; cin>>orig;
		cin>>s;
		int pos = 0, opos=0;

		int n = s.size();
		double qcount=0;
		for (int i = 0; i<n; i++)
		{
			if (orig[i] == '+') opos++;
			if (orig[i] == '-') opos--;
		}
		
		for (int i = 0; i<n; i++)
		{
			if (s[i] == '+') pos++;
			if (s[i] == '-') pos--;
			if (s[i] == '?') qcount++;
		}

		double ans=0.0;
		if (abs(pos-opos) <= qcount)
		{
			if (pos==opos and qcount == 0)
			{
				ans=1.0;
			}
			else
			{
				double dx = abs(opos-pos);
				if (((int) qcount- (int) dx)%2 != 1)
				{
					int m = (qcount-dx)/2;
					ans = factorial(qcount) / (factorial(m) * factorial(qcount-m));
					ans/= pow(2,qcount);
				}
			}
		}

		cout<<setprecision(12)<<ans<<endl;
	}
}