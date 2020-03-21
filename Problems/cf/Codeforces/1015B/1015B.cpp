#include<iostream>
#include<vector>
using namespace std;

string s,t;
int n;


int find(char c, int i)
{
	while (i<n)
	{
		if (s[i]==c)
		{
			return i;
		}
		i++;
	}
	return -1;
}

int main()
{
	cin>>n;
	cin>>s>>t;
	vector<int> moves;
	int ans=0;
	for (int i = 0; i<n; i++)
	{
		char c = t[i];
		int index=find(c,i);
		if (index==-1)
		{
			//cout<<c<<endl;
			ans=-1;
			break;
		}
		while (index>i)
		{
			swap(s[index],s[index-1]);
			moves.push_back(index);
			ans++;
			index--;
		}
	}
	cout<<ans;
	if (ans>0)
	{
		cout<<endl;
		for (int i = 0; i<ans; i++)
		{
			cout<<moves[i]<<" ";
		}
	}
	cout<<endl;
}




