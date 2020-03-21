// way too long words
#include<iostream>
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
	int n;
	cin>>n;

	for (int x =0;x<n;x++)
	{
		string s;
		cin>>s;

		int l = strlen(s);
		if (l<=10)
		{
			cout<<s<<endl;
		}
		else 
		{
			cout<<s[0]<<l-2<<s[l-1]<<endl;
		}
	}
}

