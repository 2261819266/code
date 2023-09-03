#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,a[3005][3005];
const int mod=1e9+7;
long long ans;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	        a[i][j]==0;
	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
	}
	ans=(n*(m+n)*(m+n-1)/2-1)%mod;
	cout<<ans;
	return 0;
}
