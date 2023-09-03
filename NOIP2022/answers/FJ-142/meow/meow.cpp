#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int maxn=550;
int n,t,st[maxn][500],c[maxn],cnt,m,k,a[maxn];
struct node
{
	int opt,x,y;
}g[maxn];
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
int calc(int x)
{
	if(x<=n-1)return x;
	else return x-n+1;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();m=read();k=read();
		for(int i=1;i<=m;i++)a[i]=read();
		if(k==2*n-2)
		{
			cnt=0;
			memset(st,0,sizeof(st));
			memset(c,0,sizeof(c));
			for(int i=1;i<=m;i++)
			{
				int u=calc(a[i]);
				if(c[calc(a[i])]==1)
				{
				    g[++cnt].opt=1;
					g[cnt].x=u;
					if(st[u][c[u]]==a[i])c[u]=0;
					else c[u]++,st[u][c[u]]=a[i];
				}
				else if(c[u]==2)
				{
					if(st[u][c[u]]==a[i])
					{
				       g[++cnt].opt=1;
					   g[cnt].x=u;	
					   c[u]=1;					
					}
					else
					{
						st[u][1]=st[u][2];
						c[u]--;
						g[++cnt].opt=1;
						g[cnt].x=n;
						g[++cnt].opt=2;
						g[cnt].x=u;g[cnt].y=n;
					}
				}
				else if(c[u]==0)
				{
					g[++cnt].opt=1;
					g[cnt].x=u;
					c[u]=1;
					st[u][c[u]]=a[i];
				}
			}
			for(int i=1;i<=cnt;i++)
			{
				if(g[i].opt==1)printf("%d %d\n",g[i].opt,g[i].x);
				else printf("%d %d %d\n",g[i].opt,g[i].x,g[i].y);
			}
		}
	}
	return 0;
}
