#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int f,s,g,u,d;
	cin>>f>>s>>g>>u>>d;
	
	vector<int> L={s};
	int count=0, flag=1;
	int discovered[f];
	for (int i = 0; i<f;i++) discovered[i] = 0;

	while (L.size() > 0)
	{
		vector<int> temp;
		for (int i = 0; i<L.size(); i++)
		{
			//cout<<L[i]<<endl;
			L[i]+=0;
			if (L[i]==g)
			{
				flag=0;
				break;
			}
			else
			{
				if (L[i] + u <= f and discovered[L[i]+u]==0)
				{
					discovered[L[i]+u] = 1;
					temp.push_back(L[i]+u);
				}
				if (L[i]-d >= 1 and discovered[L[i]-d]==0)
				{
					discovered[L[i]-d] = 1;
					temp.push_back(L[i]-d);
				}
				//discovered[L[i]] = 1;
			}
		}
		if (temp.size() > 0)
		{
			count++;
		}
		L=temp;
	}
	if (flag==1)
	{
		cout<<"use the stairs";
	}
	else
	{
		cout<<count<<endl;
	}
}

