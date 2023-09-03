#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=1e6+10;
int read()
{
	int s=0,b=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') b=-1; c=getchar();}
	while(c>='0'&&c<='9') s=s*10+c-'0',c=getchar();
	return s*b;
}
struct edge
{
	int nxt,to,dis;
}a[N];
struct edge2
{
	int from,to;
}b[N],tmp,c[N];
int h[N],cnt,l;
void build(int x,int y)
{
	a[++cnt]=edge{h[x],y},h[x]=cnt;
	a[++cnt]=edge{h[y],x},h[y]=cnt;
}

//--------------------------------------------------

int n,m;
int s,color[N],curc,cntc[N];
ll ans;
bool cut1(int x,int y)
{
	return ((x==tmp.from&&y==tmp.to)||(x==tmp.to&&y==tmp.from));
}
bool cut2(int x,int y)
{
	for(int i=1;i<=l;i++)
		if((x==c[i].from&&y==c[i].to)||(x==c[i].to&&y==c[i].from))
			return 1;
	return 0;
}
void dfs1(int now)
{
	for(int i=h[now];i;i=a[i].nxt)
		if(!cut1(now,a[i].to)&&!color[a[i].to])
			color[a[i].to]=color[now],dfs1(a[i].to);
	return ;
}
void dfs2(int now)
{
	for(int i=h[now];i;i=a[i].nxt)
		if(!cut2(now,a[i].to)&&!color[a[i].to])
			color[a[i].to]=color[now],dfs2(a[i].to);
	return ;
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);

	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		build(x,y),b[i]=edge2{x,y};
	}
	for(int i=1;i<=m;i++)
	{
		tmp=b[i];
		color[1]=1; dfs1(1);
		for(int j=1;j<=n;j++)
			if(!color[j])
			{
				c[++l]=b[i];
				break;
			}
		for(int j=1;j<=n;j++) color[j]=0; 
	}
	for(int i=1;i<=n;i++)
		if(!color[i]) curc++,color[i]=curc,dfs2(i);
	for(int i=1;i<=n;i++) cntc[color[i]]++;
	for(int i=1;i<=n&&cntc[i];i++,s++);
	for(int i=1;i<=s;i++) ans=(ans+ll(pow(2,cntc[i])-1)%mod*ll(pow(2,m)))%mod;
	printf("%lld\n",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

