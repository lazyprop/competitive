#include<iostream>
#include<vector>
#include<string.h>
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
	int m,n;
	cin>>n>>m;
	
	vector<int> x;
	vector<int> y;

	for (int i =0;i<n;i++)
	{
		string s;
		cin>>s;

		for (int j = 0,l=strlen(s);j<l;j++)
		{
			if (string(1,s[j]) == "B")
			{
				x.push_back(j+1);
				y.push_back(i+1);
			}
		}

	}
	
	cout<<y[(y.size() + 1 )/2 - 1]<<" "<<x[(x.size() + 1 )/2 - 1]<<endl;
}




