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

	int Testcases=1;
	//cin>>Testcases;
	while (Testcases--)
	{
		// code
		int l,r; cin>>l>>r;

		int flag = 0;
		for (int x = l; x<=r; x++)
		{
			flag = 0;
			int dig[10] = {};
			int temp = x;
			while (temp > 0)
			{
				int y = temp%10;
				if (dig[y])
				{
					flag = 1;
					break;
				}
				dig[y]++;
				temp/=10;
			}
			if (!flag)
			{
				cout<<x<<endl;
				break;
			}
		}

		if (flag) cout<<-1<<endl;
	}
}