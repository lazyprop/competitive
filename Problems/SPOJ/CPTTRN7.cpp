#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for (int a = 0;a<t;a++)
	{
		int x,y;
		cin>>y>>x;

		for (int i = 0;i<y;i++)
		{
			for (int j = 0;j<x;j++)
			{
				if ((i>0 and i<y-1) and (j>0 and j<x-1))
				{
					cout<<".";
				}
				else
				{
					cout<<"*";
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
