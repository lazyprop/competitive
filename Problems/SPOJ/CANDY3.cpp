#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t; cin>>t;
	while (t--)
	{
		vector<int> v;
		//string s; cin>>s;
		int n = 0, sum=0;
		char c,p='a'; cin>>c;
		
		while (p!='\n' and c!='\n')
		{
			v.push_back(c-'0');
			sum+=c='0';
			p = c;
			cin>>c;
		}

		if (sum%v.size() == 0)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}

