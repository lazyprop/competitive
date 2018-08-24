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
		for (int i=0,j=0;i<l;i++)
		{
			cout<<s[j];
			if (flag == 0)
			{
				j = (j + 2*n - 1 - i) %l;
				flag = 1;
			}
			else
			{
				j= (j+1 - i)%l;
				flag = 0;
			}
		}


		cout<<endl;
		cin>>n;
	}
}


