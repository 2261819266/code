#include<bits/stdc++.h>
using namespace std;
const int M=260000;
int id,n,q,a[M],b[M],st1[M][30],st2[M][30];
long long mod=1<<31;
long long ask(int x,int y)
{
	int t=log(y-x+1)/log(2);
	//cout<<t;
	long long u;u=max(st1[x][t],st1[y-(1<<t)+1][t]);
	long long v;v=max(st2[x][t],st2[y-(1<<t)+1][t]);
    return u*v%mod;
}
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>id>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		st1[i][0]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		st2[i][0]=b[i];	
	}

	int t=log(n)/log(2);

	for(int j=1;j<=t;j++)
	{
		for(int i=1;i<=n;i++)
		{
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		long long ans=0;
		int l,r;
		cin>>l>>r;
		for(int j=l;j<=r;j++)
		for(int k=j;k<=r;k++)
		{
			ans+=ask(j,k);
			ans%=mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
