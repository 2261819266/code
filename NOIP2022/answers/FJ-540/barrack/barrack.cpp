#include<bits/stdc++.h>
using namespace std;
int n,m,a[3003][3003],u,v;
int t[3003];
int ans;
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	ans=n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=0;
			a[j][i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u][v]=1;
		a[v][u]=1;
		t[u]++;
		t[v]++;
	}
	for(int i=2;i<=n;i++)
	{
		ans+=t[i];
	}
	cout<<ans+2;
	return 0;
}