#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int i = 0;i<t;i++)
	{
	int a,b,c;
	cin>>a>>b>>c;

	if (a==0 and b==0 and c==0)
	{
		return 0;
	}

	else if (c-b == b-a) // if sequence is AP
	{
		cout<<"AP ";
		int d = c-b;
		cout<<c+d<<endl;
	}
	else
	{
		cout<<"GP ";
		int r = c/b;

		cout<<c*r<<endl;
	}
	}
}

