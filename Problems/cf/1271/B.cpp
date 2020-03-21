#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin>>n;
	string s; cin>>s;

	int w = 0, b= 0;
	for (int i = 0; i<n; i++)
	{
		if (s[i] == 'W')
		{
			w++;
		}
		else
		{
			b++;
		}
	}

	if (abs(w-b) == n)
	{
		cout<<0<<endl;
		return 0;
	}

	if (w%2 ==1 and b%2 == 1)
	{
		cout<<-1<<endl;
		return 0;
	}

	string x = s;

	vector<int> sol;

	sort(x.begin(), x.end());
	if (b%2)
	{
		//sort(x.begin(), x.end(),greater<char>());
		for (int i = n-1; i>0; i--)
		{
			if (s[i] != 'B')
			{
				if (s[i] == 'W') s[i] = 'B';
				else s[i] = 'W';

				if (s[i-1] == 'W') s[i-1] = 'B';
				else s[i-1] = 'W';

				sol.push_back(i);
			}
		}
	}
	else
	{
		for (int i = 0; i<n-1; i++)
		{
			if (s[i] != 'W')
			{
				if (s[i] == 'W') s[i] = 'B';
				else s[i] = 'W';

				if (s[i+1] == 'W') s[i+1] = 'B';
				else s[i+1] = 'W';

				sol.push_back(i+1);
			}
		}
	}

	cout<<sol.size()<<endl;
	for (auto u: sol)
	{
		cout<<u<<" ";
	}
	cout<<endl;
}