// Half of Half of String
// https://spoj.com/problems/STRHH

#include<iostream>
#include<string.h>

using namespace std;

int strlen(string a)
{
	int i=0;
	while (true)
	{
		if (a[i] == '\0')
		{
			return i;
			break;
		}
		i++;
	}
}

		
int main()
{
	int t;
	cin>>t;

	for (int i = 0;i<t;i++)
	{
		string a;
		cin>>a;
		int l = strlen(a)/2;
		for (int j = 0;j<l;j++)
		{
			if (j%2==0)
			{
				cout<<a[j];
			}
		}
		cout<<endl;

	}

}
