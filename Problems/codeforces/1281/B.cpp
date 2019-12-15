#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{
		string s,t; cin>>s>>t;
		int n= s.size();
		string x = s;
		sort(x.begin(), x.end());

		if (x==s)
		{
			if (s<t)
			{
				cout<<s<<endl;
			}
			else
			{
				cout<<"---"<<endl;
			}
			continue;
		}
		int ind = 0;
		while (x[ind] == s[ind] and ind < n)
		{
			ind++;
		}

		char c = x[ind];
		int r = n-1;
		while (s[r] != c and r > ind)
		{
			r--;
		}

		s[r] = s[ind];
		s[ind] = c;

		if (s<t)
		{
			cout<<s<<endl;
		}
		else
		{
			cout<<"---"<<endl;
		}
	}	
}