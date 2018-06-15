#include<iostream>
#include<string.h>

using namespace std;

int strlen(string n)
{
	int i = 0;
	while (true)
	{
		if (n[i] == '\0')
		{
			break;
			
		}
		i++;
	}
	return i;
}
int main ()
{
	int t;
	cin>>t;

	for (int i = 0;i<t;i++)
	{
		string n;
		cin>>n;

		int count = 0;
		
		for (int i = 0,len = strlen(n);i<len;i++)
		{
			if ( n[i] == 52)
			{
				count++;
			}
		}

		cout<<count<<endl;
	}
}

