#include<iostream>
using namespace std;

unsigned long long fib(int n, unsigned long long memo[])
{
	unsigned long long f;
	if (n <=2)
	{
		f = 1;
	}

	else
	{
		if (memo[n] !=0)
		{
			f = memo[n];
		}
		else
		{

			f =  fib(n-1,memo) + fib(n-2,memo);
			memo[n] = f;
		}
	}
	return f;

}

int main()
{
	int n; cin>>n;
	unsigned long long memo[n];
	for (int i =0;i<n;i++)
	{
		memo[i] = 0;
		cout<<memo[i]<<endl; // idk what is happening. if i remove this line the program only prints one.
	}

	cout<<fib(n,memo)<<endl;
}





