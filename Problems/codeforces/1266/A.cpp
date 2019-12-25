#include<bits/stdc++.h>
using namespace std;

int main()
{
	//ifstream cin("in.txt");

	int n; cin>>n;
	while (n--)
	{
		string s; cin>>s;
		int sum = 0, a[12] = {};
		for (auto dig: s)
		{
			a[dig-'0']++;
			sum+= dig-'0';
		}

		if (!a[0] or sum%3 != 0)
		{
			cout<<"cyan\n";
			continue;
		}

		a[0]--;
		int flag = 0;
		for (int i = 0; i<10; i+=2)
		{
			if (a[i])
			{
				cout<<"red"<<endl;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout<<"cyan"<<endl;
		}
	}
}