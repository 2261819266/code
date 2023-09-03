#include <bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int mod=1e9+7;
int read()
{
	int x=0,y=1;char ch;
	do{ch=getchar();
	if(ch=='-')y=-1;
	}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9')
		x=x*10+ch-'0',ch=getchar();
	return x*y;
}
void write(int x)
{
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
long long c(int x,int y)
{
	long long an=1ll;
	for(;y;y>>=1)
	{
		if(y&1)an=an*x%mod;
		x=1ll*x*x%mod;
	}
	return an;
}
int n,m;
int head[N],to[N*2],nxt[N*2],tot=1;
void add(int x,int y)
{
	tot++;
	to[tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
int dfn[N],zsz[N],cnt;
bool bridge[N*2];
int num;
void tarjan(int x,int fa)
{
	cnt++;
	zsz[x]=dfn[x]=cnt;
	for(int i=head[x],y;i;i=nxt[i])
	{
		y=to[i];
		if(y==fa)continue;
		if(dfn[y])
		{
			zsz[x]=min(zsz[x],dfn[y]);
		}
		else
		{
			tarjan(y,x);
			zsz[x]=min(zsz[x],zsz[y]);
		}
		if(zsz[y]>dfn[x])
		{
			bridge[i]=bridge[i^1]=1;
			num++;
		}
	}
}
int qiang[N],siz[N],lu[N],cmp;
bool v[N],uuu[N*2];
int found(int x)
{
//	cout<<x<<endl;
	qiang[x]=cmp;
	int an=1;
	v[x]=1;
	for(int i=head[x],y;i;i=nxt[i])
	{
		y=to[i];
		if(bridge[i]||uuu[i])continue;
		uuu[i]=uuu[i^1]=1;
		lu[cmp]++;
		if(!v[y])
		an+=found(y);
	}
	return an;
}
int head_s[N],to_s[N*2],nxt_s[N*2],tot_s=1;
void add_s(int x,int y)
{
	tot_s++;
	to_s[tot_s]=y;
	nxt_s[tot_s]=head_s[x];
	head_s[x]=tot_s;
}
long long ans,val[N],f[N];
int qqq;
void get(int x,int fa)
{
//	f[x]=(f[fa]*c(2,mod-2)%mod*val[x])%mod;
	for(int i=qqq+1;i;i--)
		f[i]=(f[i]+f[i-1]*val[x])%mod;
	for(int i=head_s[x],y;i;i=nxt_s[i])
	{
		y=to_s[i];
		if(y==fa)continue;
		qqq++;
		get(y,x);
	}
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1,x,y;i<=m;i++)
	{
		x=read(),y=read();
		add(x,y),add(y,x);
	}
	tarjan(1,0);
/*	for(int i=1;i<=n;i++)
		cout<<dfn[i]<<' '<<zsz[i]<<'\n';
	for(int i=1;i<=m;i++)
		cout<<bridge[i*2]<<endl;*/
	for(int i=1;i<=n;i++)
		if(!qiang[i])
			siz[++cmp]=found(i);
	for(int i=1;i<=cmp;i++)
		val[i]=((c(2,siz[i])-1+mod)%mod)*(c(2,lu[i]))%mod;
//	for(int i=1;i<=cmp;i++)
//		cout<<val[i]<<' '<<siz[i]<<' '<<lu[i]<<'\n';
	for(int i=1,x,y;i<=m;i++)
		if(bridge[i*2])
		{
			x=to[i*2],y=to[i*2+1];
			add_s(qiang[x],qiang[y]);
			add_s(qiang[y],qiang[x]);
		}
	f[0]=1ll;
	get(1,0);
	for(int i=1;i<=num+1;i++)
		ans=(ans+f[i]*c(2,num-i+1))%mod;
//	for(int i=1;i<=cmp;i++)
//		ans=(ans+f[i])%mod;
	cout<<ans<<endl;
	return 0;
}
