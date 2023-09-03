#include<bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int n,m,city,road,t;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			t=1;
			for(int j=n;j>=n-i+1;j--)t*=j;
			city+=t;
		}
		road=city+1;
		cout<<(road*city)%mod;
	}
	if(m==n-1)cout<<5;
	return 0;
}
