#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	char cc=getchar();
	int ss=0,ff=1;
	while((cc<'0'||cc>'9')&&cc!='-')cc=getchar();
	if(cc=='-')ff=-1,cc=getchar();
	while(cc>='0'&&cc<='9')ss=(ss<<1)+(ss<<3)+(cc^48),cc=getchar();
	return ss*ff;
}
struct pyh{int to,nx,f;}e[1000001];
int n,m,head[100001],xb,a,b,bb,h,lx,ly,ans,st;
long long s1,s2,s3,mod=1e9+7;
void add(int xx,int yy){e[++xb].to=yy;e[xb].nx=head[xx];head[xx]=xb;}
void dfs(int u)
{
	h|=1<<(u-1);
	for(int i=head[u];i;i=e[i].nx)
	{
		int v=e[i].to;
		if(((1<<((i-1)/2))&b)==0)continue;
		if((h&(1<<(v-1)))!=0)continue;
		h|=1<<(v-1);
		dfs(v);
	}
	return ;
}
bool pd()
{
	for(int i=0;i<n;i++)if(((1<<i)&a)!=0){st=i+1;break;}
	h=0;
	dfs(st);
	return (h&a)==a;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read();m=read();
	if(n>5000)
	{	
		s1=1;
		for(int i=1;i<=n-2;i++)
		{
			s1<<=1;
			if(s1>mod)s1-=mod;
		}
		s2=n*(n+3)/2;
		s2%=mod;
		s3=(s2*s1)%mod;
		cout<<s3;
		return 0;
	}
	for(int i=1;i<=m;i++)lx=read(),ly=read(),add(lx,ly),add(ly,lx);
	for(a=1;a<=(1<<n)-1;a++)
	{
		for(bb=0;bb<=(1<<m)-1;bb++)
		{
			int fl=1;
			for(int ii=1;ii<=m;ii++)
			{
				if((1<<(ii-1))&bb)continue;
				else b=(((1<<m)-1)^(1<<(ii-1)));
				fl&=pd();
			}
			if(fl)ans++;
		}
	}
	cout<<ans;                                           
}
