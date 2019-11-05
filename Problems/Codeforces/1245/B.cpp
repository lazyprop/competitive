#include<bits/stdc++.h>

using namespace std;

int main()
{
	ifstream cin("in.txt");
	ofstream cout("out.txt");
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		int n; cin>>n;
		int a,b,c; cin>>a>>b>>c;
		int r=0,p=0,s=0;
		string S; cin>>S;
		for (int i = 0; i<n; i++)
		{
			char x = S[i];
			if (x=='R') r++;
			else if (x=='P') p++;
			else if (x=='S') s++;
		}

		int ans = min(a,s) + min(b,r) + min(c,p);
		float x=(float)n/2.0;
		if (ans >= ceil(x))
		{
			cout<<"YES\n";
			char t[n] = {};
			cout<<t<<endl;
			for (int i = 0; i<n; i++)
			{
				if (S[i] == 'R' and b>0)
				{
					t[i] = 'P';
					b--;
				}
				else if (S[i] == 'P' and c>0)
				{
					t[i] = 'S';
					c--;
				}
				else if (S[i] == 'S' and a>0)
				{
					t[i] = 'R';
					a--;
				}
				else break;
			}
			cout<<t<<endl;
			for (int i = 0; i<n; i++)
			{
				if (t[i] == 0)
				{
					if (a>0 and S[i]=='R')
					{
						t[i] = 'R';
						a--;
					}
					else if (b>0 and S[i]=='P')
					{
						t[i] = 'P';
						b--;
					}
					else if (c>0 and S[i]=='S')
					{
						t[i] = 'S';
						c--;
					}
					else break;
				}
			}
			cout<<t<<endl;
			for (int i = 0; i<n; i++)
			{
				if (t[i] == 0)
				{
					if (a>0)
					{
						t[i] = 'R';
						a--;
					}
					else if (b>0)
					{
						t[i] = 'P';
						b--;
					}
					else if (c>0)
					{
						t[i] = 'S';
						c--;
					}
					else break;
				}
			}
			cout<<t<<"\n";
		}
		else 
		{
			cout<<"NO\n";
		}
	}
}