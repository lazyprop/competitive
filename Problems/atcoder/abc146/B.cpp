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

	int n; cin>>n;
	string s; cin>>s;
	int x = s.size();

	for (int i = 0; i<x; i++)
	{
		s[i] = 'A' + (s[i]-'A' + n)%26;
	}	
	cout<<s<<endl;
}