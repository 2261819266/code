#include<cstdio>
#include<algorithm>
#include<cstring>
#define re register
#define il inline
#define mst(w,t) (std::memset(w,t,sizeof(w)))
const int N=1e3+3,p=998244353;
int n,m,c,f,a[N][N],nxt[N][N],pre[N][N],s[N][N],b[N][N],res,ans;
char xr[N];
void init()
{
	scanf("%d%d%d%d",&n,&m,&c,&f),mst(a,0),mst(nxt,0),mst(pre,0),mst(s,0),mst(b,0),res=ans=0;
	for(re int i=1;i<=n;++i)
	{
		scanf(" %s",xr+1);
		for(re int j=1;j<=m;++j) a[i][j]=xr[j]^48;
	}
	for(re int i=1;i<=n;++i) a[i][0]=a[i][m+1]=1;
	for(re int j=1;j<=m;++j) a[0][j]=a[n+1][j]=1;
	for(re int i=1;i<=n;++i)
	{
		for(re int j=1,lst;j<=m;++j)
		{
			for(lst=j;j<m&&a[i][lst]==a[i][j+1];++j);
			for(nxt[i][lst]=a[i][lst]?0:(j-lst);lst<=j;++lst,nxt[i][lst]=(a[i][lst]?0:(j-lst)));
		}
		for(re int j=1;j<=m;++j) s[i][j]=s[i-1][j]+nxt[i][j],a[i][j]&&(s[i][j]=0);
	}
	for(re int j=1;j<=m;++j)
		for(re int i=n,lst;i>0;--i)
		{
			for(lst=i;i&&a[lst][j]==a[i-1][j];--i);
			for(pre[lst][j]=a[lst][j]?(1<<30):i;lst>=i;--lst,pre[lst][j]=a[lst][j]?(1<<30):i);
		}
	for(re int j=1;j<=m;++j)
	{
		for(re int i=1,lst;i<=n;++i)
		{
			for(lst=i;i<n&&a[lst][j]==a[i+1][j];++i);
			for(b[lst][j]=a[lst][j]?0:(i-lst);lst<=i;++lst,b[lst][j]=a[lst][j]?0:(i-lst));
		}
	}
	return;
}
void solve()
{
	for(re int i=3;i<=n;++i)
		for(re int j=1;j<m;++j)
			if((!a[i][j])&&(pre[i][j]<=i-2))
				(res+=1ll*nxt[i][j]*(s[i-2][j]-s[pre[i][j]-1][j])%p)%=p;
	for(re int i=3;i<=n;++i)
		for(re int j=1;j<m;++j)
			if((!a[i][j])&&(pre[i][j]<=i-2))
				(ans+=1ll*nxt[i][j]*(s[i-2][j]-s[pre[i][j]-1][j])%p*b[i][j]%p)%=p;
	return;
}
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	re int T,id;
	scanf("%d%d",&T,&id);
	for(;T--;init(),solve(),printf("%d %d\n",res*c,ans*f));
	return 0;
}
