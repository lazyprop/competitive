#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T; cin>>T;
	while (T--)
	{
		string s; cin>>s;
		int n = s.size();

		int flag = 0;
		for (int i = 1; i<n; i++)
		{
			if (s[i] == s[i-1] and s[i] != '?')
			{
				flag++;
				break;
			}
		}

		if (!flag)
		{
			for (int i = 0; i<n; i++)
			{
				while (s[i] == '?')
				{
					if (i>0)
					{
						if (s[i-1] == 'a') s[i] = 'b';
						if (s[i-1] == 'b') s[i] = 'c';
						if (s[i-1] == 'c') s[i] = 'a';
					}
					else
					{
						s[i] = 'a';
					}
					i++;
				}
				if (i>0)
				{
					if (s[i] == s[i-1])
					{
						if (s[i] == 'a') s[i-1] = 'b';
						if (s[i] == 'b') s[i-1] = 'c';
						if (s[i] == 'c') s[i-1] = 'a';
					}
				}
			}
			cout<<s<<endl;
		}
		else
		{
			cout<<-1<<endl;
		}
	}
}