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

	map <string,int> days;
	days["MON"]=1;
	days["TUE"]=2;
	days["WED"]=3;
	days["THU"]=4;
	days["FRI"]=5;
	days["SAT"]=6;
	days["SUN"]=7;
	
	string s; cin>>s;
	int ans = days["SUN"] - days[s];
	if (!ans) ans = 7;
	cout<<ans<<endl;
}