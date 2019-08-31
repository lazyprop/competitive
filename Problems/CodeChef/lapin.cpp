#include<iostream>
#include<algorithm>
using namespace std;

int strlen(string s)
{
	int l=0;
	while (s[l] != '\0')
	{
		l++;
	}
	return l;
}

int main()
{
	int t;
	cin>>t;

	for (int x = 0;x<t;x++)
	{
		string s;
		cin>>s;
		vector<char> c;
		vector<int> f;

		for (int i = 0,l=strlen(s);i<l;i++)
		{
			if ( find(c.begin(), c.end(), s[i])  != c.end())
			{


		
