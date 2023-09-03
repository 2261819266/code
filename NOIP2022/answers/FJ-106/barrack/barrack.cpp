#include<cstdio>
int n,m,tot,u[1000010],v[1000010],head[500010],to[2000010],nxt[2000010],siz[500010],tp[50],vs[50];
long long Ans,ans[500010][2];
const long long MOD=1000000007;
long long Add(long long a,long long b)
{
	return (a+b<MOD)?(a+b):a+b-MOD;
}
long long POW(long long a,long long b)
{
	long long res=1;
	for(;b;b>>=1){
		if(b&1) res=res*a%MOD;
		a=a*a%MOD;
	}
	return res;
}
void add(int u,int v)
{
	nxt[++tot]=head[u],to[tot]=v,head[u]=tot;
}
void dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i]) if(to[i]!=fa){
		dfs(to[i],x);
		siz[x]+=siz[to[i]];
	}
	ans[x][1]=1;
	for(int i=head[x];i;i=nxt[i]) if(to[i]!=fa){
		ans[x][0]=Add(ans[x][0],Add(ans[to[i]][0],ans[to[i]][1])*POW(2,siz[x]-siz[to[i]])%MOD);
		ans[x][1]=ans[x][1]*Add(ans[to[i]][1],POW(2,siz[to[i]]))%MOD;
	}
}
void dfs(int x)
{
	vs[x]=1;
	for(int i=head[x];i;i=nxt[i]) if(!vs[to[i]]) dfs(to[i]);
}
int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%d%d",&u[i],&v[i]);
	/*if(n<=16){
		f[0]=1;
		for(int i=1,x;i<(1<<n);i++){
			for(int j=0;j<n;j++) tmp[j+1]=((i&(1<<j))>>j),(tmp[j+1]?x=j+1:0);
			for(int j=head[x];j;j=nxt[j]) if(){
				
			}
		}
	}*/
	if(n==m+1){
		for(int i=1;i<=m;i++) add(u[i],v[i]),add(v[i],u[i]);
		dfs(1,0);
		printf("%lld",Add(ans[1][0],ans[1][1]));
		return 0;
	}
	if(n+m<=18){
		for(int i=1;i<(1<<n);i++) for(int j=0;j<(1<<m);j++){
			for(int k=1;k<=n;k++) head[k]=vs[k]=0;
			tot=0;
			int np=0,flag=0;
			for(int k=0;k<n;k++) if(i&(1<<k)) tp[++np]=k+1;
			for(int k=0;k<m;k++) if(j&(1<<k)) add(u[k+1],v[k+1]),add(v[k+1],u[k+1]);
			dfs(tp[1]);
			for(int k=1;k<=np;k++) if(!vs[tp[k]]){flag=1;break;}
			if(!flag){
				Ans++;
			}
		}
		printf("%llu",Ans);
		return 0;
	}
	printf("0");
}
