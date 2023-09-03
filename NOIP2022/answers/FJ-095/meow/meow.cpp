#include<iostream>
#include<cstring>
#include<cstdio>
#define int long long
using namespace std;
int read()
{
	int res=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')res=res*10+ch-'0',ch=getchar();
	return res;
}
int T,n,m,k,a[2000001],xl[2000001],stack[301][301],ans[4000001][3],pd;
void dfs(int x)
{
	if(pd)return;
	if(x>m)
	{
		memset(stack,0,sizeof(stack));
		memset(ans,0,sizeof(ans));
		for(int i=1;i<=m;++i)
		{
			int xx=xl[i];ans[++ans[0][0]][0]=1;ans[ans[0][0]][1]=xl[i];
			stack[xx][++stack[xx][0]]=a[i];
			if(stack[xx][0]>1&&stack[xx][stack[xx][0]]==stack[xx][stack[xx][0]-1])
				stack[xx][stack[xx][0]]=0,stack[xx][stack[xx][0]-1]=0,stack[xx][0]-=2;
			if(stack[xx][0]==1)
			{
				for(int j=1;j<=n;++j)
					if(xx!=j&&stack[xx][1]==stack[j][1])
					{
						for(int k=1;k<stack[j][0];++k)stack[j][k]=stack[j][k+1];
						stack[j][stack[j][0]]=0;--stack[j][0];stack[xx][0]=0;stack[xx][1]=0;
						ans[++ans[0][0]][0]=2;ans[ans[0][0]][1]=j;ans[ans[0][0]][2]=xx;
						break;
					}
			}
		}
		for(int i=1;i<=n;++i)
			if(stack[i][0]!=0)
				return;
		if(ans[0][0]>2*m)return;
		printf("%lld\n",ans[0][0]);
		for(int i=1;i<=ans[0][0];++i)
		{
			if(ans[i][0]==1)printf("%lld %lld\n",ans[i][0],ans[i][1]);
			else printf("%lld %lld %lld\n",ans[i][0],ans[i][1],ans[i][2]);
		}
		pd=1;
		return;
	}
	for(int i=1;i<=n;++i)xl[x]=i,dfs(x+1);
}
signed main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();m=read();k=read();
		for(int i=1;i<=m;++i)a[i]=read();
		dfs(1);
	}
	return 0;
}
