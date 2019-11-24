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

		int q[n];
		int seen[n+10]={},flag=0;

		for (int i = 0; i<n; i++)
		{
			cin>>q[i];
		}

		int ans[n];
		int cur = 1;
		ans[0] = q[0];
		seen[q[0]]++;
		for (int i = 1; i<n; i++)
		{
			if (q[i] > q[i-1])
			{
				ans[i] = q[i];
			}
			else
			{
				while (seen[cur])
				{
					cur++;
					if (cur>q[i])
					{
						flag = -1;
						break;						
					}
				}
				ans[i] = cur;
			}
			seen[ans[i]]++;
		}

		if (!flag)
		{
			for (int i = 0; i<n; i++)
			{
				cout<<ans[i]<<" ";
			}
		}
		else cout<<-1;
		cout<<endl;
	}	
}