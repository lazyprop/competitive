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

		
		for (int i=0;i<n;i++)
		{
			int j = i;
			int flag=0;
			while (j<l)
			{
			
				cout<<s[j];

				if (flag==0)
				{
					j+=2*(n-i) - 1;

					flag = 1;
				}
				else
				{
				
					j+=2*i + 1;
					flag=0;
				}
			}
		}
		


		cout<<endl;
		cin>>n;
	}
}


