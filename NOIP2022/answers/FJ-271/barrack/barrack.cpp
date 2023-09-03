#include<bits/stdc++.h>
using namespace std;
int read()
{
	int c=0;
	char ch=0;
	while(ch<'0' || ch>'9') ch=getchar();
	while(ch>='0' && ch<='9')
	{
		c=(c<<3)+(c<<1)+(ch-'0');
		ch=getchar();
	}
	return c;
}
const int N=5e5+8,M=1e6+8,Mod=1e9+7;
int n,m,u1,v1,cnt=0,head[N];
struct Edg
{
	int nxt;
	int to;
	int id;
}tr[M<<1];
void Add(int u,int v,int idx)
{
	tr[++cnt].nxt=head[u];
	tr[cnt].to=v;
	tr[cnt].id=idx;
	head[u]=cnt;
}
int tot=0,sta[N],ans=0;
bool Get[N];
int ksm(int a,int b)
{
	int sum=1;
	while(b)
	{
		if(b&1) sum=(sum*a)%Mod;
		a=a*a%Mod;
		b>>=1;
	}
	if(sum<0) sum+=Mod;
	return sum;
}
void ls(int now,int edgid)
{
	if(Get[now]==true) return ;
	Get[now]=true;
	for(int i=head[now];i;i=tr[i].nxt)
	{
		if(tr[i].id==edgid) continue;
		int To=tr[i].to;
		ls(To,edgid);
	}
}
bool cheak(int edg)
{
	for(int i=1;i<=tot;i++)
	{
		memset(Get,false,sizeof(Get));
		ls(sta[i],edg);
		for(int j=1;j<=tot;j++) if(Get[sta[j]]==false) return true;
	}
	return false;
}
void ss(int pos)
{
	if(pos>n)
	{
		if(tot==0) return ;
		if(tot==1)
		{
			ans=(ans+ksm(2,m))%Mod;
			return ;
		}
		int res=m;
		for(int i=1;i<=m;i++) if(cheak(i)==true) res--;
		ans=(ans+ksm(2,res))%Mod;
		return ;
	}
	ss(pos+1);
	sta[++tot]=pos;
	ss(pos+1);
	tot--;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		u1=read(),v1=read();
		Add(u1,v1,i);
		Add(v1,u1,i);
	}
	ss(1);
	printf("%d",ans);
	return 0;
}
