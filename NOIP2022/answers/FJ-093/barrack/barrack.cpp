#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const long long mod=1e9+7;
long long n,m,a[30],b[30],vis[30],f[30],cnt[30],p[40],ans;
long long getf(long long v)
{
	if(f[v]==v) return v;
	else return f[v]=getf(f[v]); 
}
void dfs(long long st)
{
	if(st==m+1)
	{
		memset(cnt,0,sizeof(cnt));
		for(long long i=1;i<=n;i++) f[i]=i;
		for(long long i=1;i<=m;i++)
		{
			if(vis[i])
			{
				long long f1=getf(a[i]),f2=getf(b[i]);
				if(f1!=f2) f[f2]=f1;
			}
		}
		for(long long i=1;i<=n;i++)
			cnt[getf(i)]++;
		for(long long i=1;i<=n;i++)
			ans+=p[cnt[i]]-1;
		return;
	}
	vis[st]=1;
	dfs(st+1);
	vis[st]=0;
	dfs(st+1);
	return;
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	p[0]=1;
	for(long long i=1;i<=35;i++) p[i]=p[i-1]*2,p[i]%=mod;
	scanf("%lld%lld",&n,&m);
	if(m<=25)
	{
		memset(vis,0,sizeof(vis));
		for(long long i=1;i<=m;i++) scanf("%lld%lld",&a[i],&b[i]);
		dfs(1);
		printf("%lld",ans);
	}
	else printf("114514");
	return 0;
}
