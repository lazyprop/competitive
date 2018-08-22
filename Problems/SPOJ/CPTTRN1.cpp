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
			if (i%2 == 0)
			{
				for (int j=0;j<x;j++)
				{
					if (j%2==0)
					{
						cout<<"*";
					}
					else
					{
						cout<<".";
					}
				}
			}
			if (i%2==1)
			{
				for (int j = 0;j<x;j++)
				{
					if(j%2 == 0)
					{
						cout<<".";
					}
					else
					{
						cout<<"*";
					}
				}
			}
			cout<<endl;
		}
		cout<<endl;
	}
}
