#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sizecom(const vector<int>& v1, const vector<int>& v2)
{
    return v1.size() > v2.size();
}
int main()
{
	int n,cap; cin>>n>>cap;
	vector<int> diff;

	unsigned long long suf=0;
	for (int i = 0; i<n; i++)
	{
		int a,b; cin>>a>>b;
		diff.push_back(a-b);
		suf+=a;
	}
	//sort(size.begin(), size.end(), sizecom);
	sort(diff.begin(), diff.end());
	
	int ans=0;
	for (int i = n-1; i>=0;i--)
	{
		if (suf<=cap)
		{
			break;
		}
		suf-=diff[i];
		ans++;
	}
	if (suf>cap) cout<<-1<<endl;
	else cout<<ans<<endl;
}
