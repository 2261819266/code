#include<bits/stdc++.h>
using namespace std;
int t,n,m,k,op;
int a[2000005];
int h[305],ta[305];
int cz[2000005][3];
int qn(int now)
{
	for(int j=now;j<=m;j++)
		for(int k=1;k<=n;k++)
			if(h[k]==a[j])
				return h[k];
}
void work(int now,int x)
{
	for(int i=1;i<=n;i++)
	{
		if(h[i]==x)
		{
			cz[++op][0]=1;
			cz[op][1]=i;
			h[i]=ta[i];
			ta[i]=0;
			return;
		}
		if(ta[i]==x)
		{
			for(int j=1;j<=n;j++)
			{
				if(h[j]==0)
				{
					cz[++op][0]=1;
					cz[op][1]=j;
					cz[++op][0]=2;
					cz[op][1]=i;
					cz[op][2]=j;
					ta[i]=0;
					return;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(h[i]==0)
		{
			cz[++op][0]=1;
			cz[op][1]=i;
			h[i]=x;
			return;
		}
	}
	for(int i=1;i<=n;i++)
	{
		int next=qn(now);
		if(ta[i]==0&&h[i]!=next)
		{
			cz[++op][0]=1;
			cz[op][1]=i;
			ta[i]=h[i];
			h[i]=x;
			return;
		}
	}
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>m>>k;
		for(int j=1;j<=m;j++)
			cin>>a[j];
		for(int j=1;j<=m;j++)
			work(j,a[j]);
	}
	cout<<op<<"\n";
	for(int i=1;i<=op;i++)
	{
		cout<<cz[i][0]<<" ";
		if(cz[i][0]==1) cout<<cz[i][1]<<"\n";
		else cout<<cz[i][1]<<" "<<cz[i][2]<<"\n";
	}
	return 0;
}