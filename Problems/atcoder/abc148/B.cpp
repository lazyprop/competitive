#include<bits/stdc++.h>
using namespace std;

int main()
{
	int r; cin>>r;
	string s= "",t="";
	
	cin>>s>>t;

	string x = "";
	
	int l = 0;
	while (l<r)
	{
		x+= s[l];
		x+= t[l];
		
		l++;
	}
	cout<<x<<endl;
}