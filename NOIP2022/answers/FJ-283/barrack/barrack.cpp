#include <cstdio>
#include <iostream>
#include <cstring>
#include <iostream>
#include <cmath>
#include <map>
using namespace std;
int n,m,cnt,head[500005];
int low[500005],dfn[500005],z[500005],sy[500005],tot;
long long ef[1000005],od=1000000007,ans,f[500005],zb[500005];
struct node{
	int from,to,nex,sum;
}lj[2000005],tr[2000005];
struct node2{
	int ds,bs;
}jd[500005];
void cr(int x,int y)
{
	lj[++cnt].to=y;
	lj[cnt].from=x;
	lj[cnt].nex=head[x];
	head[x]=cnt;
}
void dfs(int x,int fa)
{
	//cout<<x<<' '<<fa<<endl;
	dfn[x]=low[x]=++cnt;
	z[++z[0]]=x;
	for(int i=head[x];i;i=lj[i].nex)
	{
		int y=lj[i].to;
		if(i==(fa^1)) continue;
		if(!dfn[y])
		{
			dfs(y,i);
			low[x]=min(low[x],low[y]);
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		int y=0;
		tot++;
		while(y!=x)
		{
			y=z[z[0]--];
			sy[y]=tot;
			jd[tot].ds++;
		}
	}
}
map<int,int>mp[500005];
void js(int x,int y)
{
	tr[++cnt].to=y;
	tr[cnt].nex=head[x];
	tr[cnt].sum=1;
	head[x]=cnt;
	mp[x][y]=cnt;
}
void dp(int x,int fa,int s)
{
	//cout<<x<<' '<<fa<<endl;
	f[x]=1;
	zb[x]=jd[x].bs;
	for(int i=head[x];i;i=tr[i].nex)
	{
		int y=tr[i].to;
		if(y==fa) continue;
		dp(y,x,tr[i].sum);
		f[x]=f[x]*((f[y]*(ef[tr[i].sum]-1)%od+ef[zb[y]]*ef[tr[i].sum]%od)%od)%od;
		zb[x]+=zb[y]+tr[i].sum;
	}
	f[x]=f[x]*ef[jd[x].ds]%od*ef[jd[x].bs]%od;
	f[x]=(f[x]-ef[zb[x]]+od)%od;
	//cout<<x<<' '<<f[x]<<endl;
	ans=(ans+f[x]*ef[m-zb[x]-s]%od)%od;
	//cout<<ans<<endl;
}
int kd()
{
	char c=getchar();
	int sr=0;
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') sr=sr*10+c-'0',c=getchar();
	return sr;
}
int main ()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	cnt=1;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		x=kd(),y=kd();
		cr(x,y);
		cr(y,x);
	}
	cnt=0;
	dfs(1,0);
	cnt=0;
	for(int i=1;i<=tot;i++) head[i]=0;
	for(int i=2;i<=2*m+1;i+=2) 
	{
		if(sy[lj[i].from]!=sy[lj[i].to]) 
		{
			if(!mp[sy[lj[i].from]][sy[lj[i].to]])
			{
				js(sy[lj[i].from],sy[lj[i].to]);
				js(sy[lj[i].to],sy[lj[i].from]);
			}
			else 
			{
				tr[mp[sy[lj[i].from]][sy[lj[i].to]]].sum++;
				tr[mp[sy[lj[i].to]][sy[lj[i].from]]].sum++;
			}
		}
		else jd[sy[lj[i].from]].bs++;
	}
	ef[0]=1;
	for(int i=1;i<=m;i++) ef[i]=ef[i-1]*2%od;
	dp(1,0,0);
	printf("%lld",ans);
}
