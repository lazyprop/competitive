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
		int n; cin>>n;
		vector<int> ans;

		for (int i = 1; i<= sqrt(n)+1; i++)
		{
			ans.push_back(n/i);
		}

		int l = ans.size();
		for (int i = 0; i<ans[l-1]; i++)
		{
			ans.push_back(i);
		}

		sort(ans.begin(), ans.end());
		l = ans.size();
		cout<<l<<endl;
		for (int i = 0; i<l; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
}