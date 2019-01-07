#include<iostream>
#include<string>
using namespace std;

int length(string s)
{
	int n=0;
	while (s[n]!='\0')
	{
		n++;
	}
	return n;
}

int lcs(string x, string y, int n,int  m)
{
	if (m==0 or n==0)
	{
		return 0;
	}
	if (x[n-1] == y[m-1])
	{
		return 1 + lcs(x,y,n-1,m-1);
	}
	else
	{
		return max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
	}
}


int main()
{
	string a,b; cin>>a>>b;
	int n = length(a), m = length(b);
	
	cout<<lcs(a,b,n,m)<<endl;
}

