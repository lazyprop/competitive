#include<bits/stdc++.h>
using namespace std;

int main()
{
	// ifstream cin("in.txt");
	int T; cin>>T;
	while (T--)
	{
		int n; cin>>n;
		int ans = 0, count = 0, flag = 0;
		string s; cin>>s;

		for (int i = 0; i<n; i++)
		{
			count = 0;
			if (s[i] == 'A')
			{
				int j = i+1;
				while (s[j] == 'P' and j < n)
				{
					count++;
					j++;
				}
				i = j-1;
				ans = max(ans, count);
			}
		}
		cout<<ans<<endl;
	}
}