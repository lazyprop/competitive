#include<iostream>
#include<map>
using namespace std;

int fib(int n, map<int,int> memo)
{
	int f;
	if (memo[n])
	{
		f= memo[n];
	}
	else
	{
		if (n<=2)
		{
			f= 1;
		}
		else
		{
			f= fib(n-1,memo) + fib(n-2,memo);
		}
	}
	memo[n] = f;
	return f;

}

int main()
{
	map <int,int> memo;
	int n;
	cin>>n;
	
	cout<<fib(n,memo)<<endl;
	for (int i = 0;i<memo.size();i++)
	{
		cout<<memo[i]<<" ";
	}
	cout<<endl;

}


