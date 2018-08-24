#include<iostream>
using namespace std;

int strlen(string s)
{
	int n=0;
	while (true)
	{
		if (s[n]!='\0')
		{
			n++;
		}
		else
		{
			break;
		}
	}
	return n;
}

int main()
{
	int n;
	cin>>n;

	while (n!=0)
	{
		string s;
		cin>>s;

		int l = strlen(s);
		char arr [n][l/n];

		int flag=0;
		for (int i=0;i<n;i++)
		{
			int j = i;
			while (j<l)
			{
			
				cout<<j<<endl;

				if (flag==0)
				{
					cout<<2*(n-i)-1<<"  ";

					flag = 1;
				}
				else
				{
				
					j+=2*i  + 1;
					//cout<<endl<<j<<endl;
					flag=0;
				}
			}
		}
		


		cout<<endl;
		cin>>n;
	}
}


