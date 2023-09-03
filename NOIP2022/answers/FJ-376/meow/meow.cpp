#include<cstdio>
#include<queue>
#define re register
#define il inline
const int M=2e6+3,N=603;
int n,m,k,a[M],nxt[M],pre[M],vis[M],sz;
struct wt{int op,x,y;}ans[M<<1];
bool top[M];
std::deque<int>q[N];
il int get_empty()
{
	for(re int i=1;i<=n;++i) if(q[i].empty()) return i;
	return n+1;
}
il int f(int x){return q[x].empty()?m+1:nxt[q[x].front()];}
il int get(int x)
{
	re int y=0;
	for(re int i=n;i;--i)
		if(q[i].size()<2&&f(i)>nxt[x]) y=i;
	return y?y:get_empty();
}
il void solve()
{
	for(re int i=0;i<=n;++i) q[i].clear();
	scanf("%d%d%d",&n,&m,&k),nxt[0]=0,sz=0,q[0].push_back(0),--n;
	for(re int i=1;i<=k;++i) pre[i]=m+1,vis[i]=top[i]=0;
	for(re int i=1;i<=m;++i) scanf("%d",a+i);
	for(re int i=m;i;--i)
		nxt[i]=pre[a[i]],pre[a[i]]=i;
	for(re int i=1,x;i<=m;++i)
	{
		if(vis[a[i]])
		{
			if(top[a[i]]) q[vis[a[i]]].pop_back(),ans[++sz]=(wt){1,vis[a[i]]};
			else x=get_empty(),q[vis[a[i]]].pop_back(),ans[++sz]=(wt){1,x},ans[++sz]=(wt){2,vis[a[i]],x};
			vis[a[i]]=top[a[i]]=0;
		}
		else
			x=get(i),!q[x].empty()&&(top[a[q[x].back()]]=false),q[x].push_back(i),ans[++sz]=(wt){1,x},vis[a[i]]=x,top[a[i]]=true;
	}
	printf("%d\n",sz);
	for(re int i=1;i<=sz;++i) (ans[i].op==1)?printf("1 %d\n",ans[i].x):printf("2 %d %d\n",ans[i].x,ans[i].y);
	return;
}
int main()
{
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	re int T;
	for(scanf("%d",&T);T--;solve());
	return 0;
}
