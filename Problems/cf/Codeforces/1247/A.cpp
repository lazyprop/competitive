#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
int main()
{
	//ifstream cin("in.txt");
	//ofstream cout("out.txt");
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int da,db; cin>>da>>db;	
	if (da == 9 and db==1)
	{
		cout<<9<<" "<<10<<endl;
		return 0;
	}
	if (db-da > 1 or db-da < 0)
	{
		cout<<-1<<endl;
		return 0;
	}

	if (abs(da-db) == 1)
	{
		cout<<da<<" "<<db<<endl;
		return 0;
	}
	cout<<da*10<<" "<<db*10+1<<endl;
}