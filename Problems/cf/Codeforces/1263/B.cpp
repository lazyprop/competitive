#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long

int convert(string s)
{
	int x = 0;
	for (int i = 0; i<4; i++)
	{
		x+= (s[i]-'0') * pow(10,3-i);
	}
	return x;
}
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		string a[n];
		for (int i = 0; i<n; i++) cin>>a[i];

		map<string,int> seen;
		int ans = 0;
		for (int i =0; i<n; i++)
		{
			if (seen.find(a[i]) != seen.end())
			{
				string x= a[i];
				x[3] = '0';

				while (x[3] <= '9')
				{
					if (seen.find(x) == seen.end())
					{
						a[i] = x;
						ans++;
						break;
					}
					x[3]++;
				}
			}
			seen[a[i]]++;				

		}
		cout<<ans<<endl;
		for (int i = 0; i<n; i++)
		{
			cout<<a[i]<<endl;
		}
	}
}