#include<iostream>
#include<string>
using namespace std;

string to_binary(int n)
{
	string s = "";
	while (n)
	{
		s.append(to_string(n%2));
		n/=2;
	}
	string k="";
	for (int i =s.length()-1; i>=0; i--)
	{
		k += s[i];
	}

	return k;
}

	
int main()
{
	int t;  cin>>t;
	while (t--)
	{
		int n; cin>>n;
		string s = "1";
		for (int i = 2; stoull(s) % n != 0; i++)
		{
			s = to_binary(i);
		}


		cout<<s<<endl;
		
	}
}
