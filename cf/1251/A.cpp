#include<bits/stdc++.h>

#define ll long long
#define ull unsigned long long

using namespace std;

int main()
{
	int Testcases=1;
	cin>>Testcases;
	while (Testcases--)
	{
		// code
		string s; cin>>s;
		int n = s.size();
		int ans[26] = {};
		for (int i = 0; i<n; i++)
		{
			int count = 1;
			int x = s[i];
			for (i++; i<n; i++)
			{
				//cout<<x<<" "<<s[i]<<endl;
				//cout<<i;
				if (s[i] == x)
				{
					//cout<<"x"<<endl;
					count++;
				}
				else
				{
					i--;
					break;
				}
			}
			//cout<<x<<" "<<count<<endl;
			if (count%2 == 1)
			{
				ans[x-'a']=1;
			}
		}
		for (int i = 0; i<26; i++)
		{
			if (ans[i]) cout<<(char) (i+'a');
		}
		cout<<endl;
	}
}