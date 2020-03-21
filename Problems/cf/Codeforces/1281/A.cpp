#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T;
	cin >>T;
	while (T--)
	{
		string s; cin>>s;
		int n = s.size();
		string x = "";
		if (n<2) continue;
		x+= s[n-2];
		x+= s[n-1];
		if (x=="po")
		{
			cout<<"FILIPINO"<<endl;
			continue;
		}
		if (n<4) continue;
		x = "";
		x+= s[n-4];
		x+= s[n-3];
		x+= s[n-2];
		x+= s[n-1];

		if (x=="desu" or x=="masu")
		{
			cout<<"JAPANESE\n";
			continue;
		}
		if (n<5) continue;
		x = "";
		x+= s[n-5];
		x+= s[n-4];
		x+= s[n-3];
		x+= s[n-2];
		x+= s[n-1];
		if (x== "mnida")
		{
			cout<<"KOREAN\n";
		}
	}	
}