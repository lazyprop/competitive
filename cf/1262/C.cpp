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

	int T; cin>>T;
	while (T--)
	{
		int n,k; cin>>n>>k;
		string s; cin>>s;
		string t = "";

		for (int i = 0; i<k-1; i++)
		{
			t+= "()";
		}

		for (int i = 0; i<n/2 - k + 1; i++)
		{
			t+="(";
		}
		for (int i = 0; i<n/2 - k + 1; i++)
		{
			t+=")";
		}

		vector<pair<int,int> > ans;
		for (int i = 0; i<n; i++)
		{
			int r=0;

			for (int j = i; j<n; j++)
			{
				if (s[j] == t[i])
				{
					r = j;
					break;
				}
			}
			reverse(s.begin()+i, s.begin()+r+1);
			ans.push_back(make_pair(i+1,r+1));
		}
		int l = ans.size();
		cout<<l<<endl;
		for (int i = 0; i<l; i++)
		{
			cout<<ans[i].first<<" "<<ans[i].second<<endl;
		}
	}
}