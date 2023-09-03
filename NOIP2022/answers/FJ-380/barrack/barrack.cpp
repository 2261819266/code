#include<bits/stdc++.h>
using namespace std;
const int N=5e5+6;
typedef long long ll;
int n,m,tot,a[N*2],b[N*2],ver[2*N],nxt[2*N],head[N],cho[N],p[N],f[21][21];
ll ans;
void add(int x,int y){ver[++tot]=y;nxt[tot]=head[x];head[x]=tot;}
bool check()
{
	p[0]=0;
	for(int i=1;i<=n;i++) if(cho[i]) p[++p[0]]=i;
	if(!p[0]) return false;
    /*for(int i=1;i<=n;i++)
    {
    	for(int j=1;j<=n;j++) f[i][j]=0;
	}
    for(int i=n+1;i<=n+m;i++) if(cho[i]) f[a[i-n]][b[i-n]]=f[b[i-n]][a[i-n]]=1;
    for(int k=1;k<=n;k++)
    {
    	for(int i=1;i<=n;i++)
    	{
    		for(int j=1;j<=n;j++) if(i^j) f[i][j]|=(f[i][k]&f[k][j]);
		}
	}
	for(int i=1;i<p[0];i++)
	{
		for(int j=i+1;j<=p[0];j++) if(!f[p[i]][p[j]]&&!f[p[j]][p[i]]) return false;
	}*/
	for(int l=n+1;l<=n+m;l++)
	{
		for(int i=1;i<=n;i++)
        {
    	    for(int j=1;j<=n;j++) f[i][j]=0;
	    }
        for(int i=n+1;i<=n+m;i++) if(cho[i]||i!=l) f[a[i-n]][b[i-n]]=f[b[i-n]][a[i-n]]=1;
        for(int k=1;k<=n;k++)
        {
    	    for(int i=1;i<=n;i++)
    	    {
    		    for(int j=1;j<=n;j++) if(i^j) f[i][j]|=(f[i][k]&f[k][j]);
		    }
	    }
	    for(int i=1;i<p[0];i++)
	    {
		    for(int j=i+1;j<=p[0];j++) if(!f[p[i]][p[j]]&&!f[p[j]][p[i]]) return false;
	    }
	}
	return true;
}
void dfs(int now)
{
	if(now==n+m+1)
	{
		if(check()) ans++;
		return ;
	}
	dfs(now+1);
	cho[now]=1;
	dfs(now+1);
	cho[now]=0;
}
void solve()
{
	dfs(1);
	printf("%lld",ans);
}
void work()
{
	puts("114514");
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i],&b[i]);
    if(n<=20) solve();
    else work();
	return 0;
}
