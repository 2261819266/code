#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
vector<int> e[maxn];
long long mod=1000000007;
void mg(int from,int to)
{
	e[from].push_back(to);
}
long long pow1(int a,int b)
{
	int cnt=1;
	for(int i=1;i<=b;i++)
	{
		cnt=(cnt*a)%mod;
	}
	return cnt;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		mg(u,v);
	}
	int sum=0;
	for(int i=0;i<=m;i++)
	{
		for(int j=1;j<=i+1;j++)
		{
			sum=(sum+pow1(2,i))%mod;
		}
	}
	cout<<sum%mod;
	return 0;
}
