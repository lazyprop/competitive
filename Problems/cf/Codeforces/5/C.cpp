#include<bits/stdc++.h>
using namespace std;

int main()
{
	string a; cin>>a;
	int n = a.size();

	int pos[n+1], pose[n+1];
	int count[n+1] = {}, maxlen = 0;

	stack<int> s;
	for (int i = 0; i<n; i++)
	{
		if (a[i] == '(')
		{
			s.push(i);
		}
		else
		{
			if (s.empty())
			{
				pos[i] -1;
				pose[i] = -1;
			}
			else
			{
				pos[i] = s.top();
				pose[i] = s.top();
				s.pop();

				if (a[pos[i]-1] == ')' and pose[pos[i]-1] >= 0)
				{
					pose[i] = pose[pos[i] -1];
				}
				int len = i - pose[i] + 1;
				maxlen = max(maxlen,len);

				count[len]++;
			}
		}
	}

	if (maxlen) cout<<maxlen<<" "<<count[maxlen]<<endl;
	else cout<<"0 1\n";
}