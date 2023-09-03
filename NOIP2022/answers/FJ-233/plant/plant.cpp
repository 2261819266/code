#include<bits/stdc++.h>
#define mod 998244353
using namespace std;
int a[1005][1005],b[1005][1005];
int s1[1005][1005],s2[1005][1005];
bool vis[1005][1005];
long long anc,anf;
int n,m,t,id,c,f,k;
void dfs(int u,int v,int d)
{
	vis[u][v]=1;
	if(a[u][v]==0)
	{
		if(a[u][v+1]==1)return;
		if(a[u+1][v]==1||a[u+2][v]==1)return;
		int l=v+1,r=m,temp=v;//ср 
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(s1[u][mid]>s1[u][v])
			r=mid-1;
			else temp=mid,l=mid+1;
		}
		b[u][v]=temp;
		//cout<<"temp="<<temp<<endl;
		if(d==0)//об 
		{
			l=u+2,r=n;k=u;
			while(l<=r)
			{
				int mid=(l+r)>>1;
				if(s2[mid][v]>s2[u][v])
					r=mid-1;
				else k=mid,l=mid+1;
			}
			d=k;
		}
		
		//cout<<"k="<<k<<endl;
		for(int x=u+2;x<=d;x++)
		{
			if(a[x][v+1]==1)continue;
			if(!b[x][v])
			{
				l=v+1,r=m;int y=v;
				while(l<=r)
				{
					int mid=(l+r)>>1;
					if(s1[x][mid]>s1[x][v])
						r=mid-1;
					else y=mid,l=mid+1;
				}
				//cout<<"y="<<y<<endl;
				b[x][v]=y;
			}
			anc=(anc+(temp-v)*(b[x][v]-v)%mod)*c%mod;
			anf=(anf+(temp-v)*(b[x][v]-v)*(d-x)*f%mod)%mod;
			//cout<<"anc="<<anc<<endl<<"anf="<<anf<<endl;
			dfs(x,v,d);
		}
	}
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&id);
	while(t--)
	{
		k=0;
		memset(a,0,sizeof(a));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		memset(vis,0,sizeof(vis));
		memset(b,0,sizeof(b));
		anc=anf=0;
		scanf("%d%d%d%d",&n,&m,&c,&f);
		if(c==0&&f==0)
		{
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				char ch;
				cin>>ch;
				if(ch=='0')a[i][j]=0;
				else a[i][j]=1;
				s1[i][j]=a[i][j]+s1[i][j-1];
				s2[i][j]=a[i][j]+s2[i-1][j];
			}
		for(int j=1;j<=m;j++)
			for(int i=1;i<=n;i++)
			{
				if(!vis[i][j])
				dfs(i,j,0);
			}
		cout<<anc<<" "<<anf<<endl;
	}
	return 0;
}
