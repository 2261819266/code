#include<cstdio>
using namespace std;
const int Mod=1000000007;
int n,m,first[5005],to[200005],nxt[200005],num,X[200005],Y[200005],t[200005],vis[5005],l,ms[5005],ans;
int tt[500005];
void add(int x,int y){to[++num]=y,nxt[num]=first[x],first[x]=num;}
void dfs(int x,int fa){
	vis[x]=1;
	for(int i=first[x];i;i=nxt[i])if(!vis[to[i]]&&(to[i]^fa)&&(i^l)&&(i^(l+1)))dfs(to[i],x);
}
bool dfs3(int x,int fa){
	vis[x]=1;
	if(ms[x])return 1;
	for(int i=first[x];i;i=nxt[i])if(!vis[to[i]]&&(to[i]^fa)&&(i^l)&&(i^(l+1)))if(dfs3(to[i],x))return 1;
	return 0;
}
void dfs2(int x){
	if(x>n){
		int fflag=0;
		for(int i=1;i<=n;++i)fflag|=ms[i];
		if(!fflag)return;
		int ta=1;
		for(int i=1;i<=m;++i){
			if(t[i]){
				l=i*2-1;
				for(int j=1;j<=n;++j)vis[j]=0;
				if(!dfs3(X[i],X[i])||!dfs3(Y[i],Y[i]))ta=(ta*2)%Mod;
			}
			else ta=(ta*2)%Mod;
		}
		ans=(ta+ans)%Mod;
		return;
	}
	ms[x]=1,dfs2(x+1);
	ms[x]=0,dfs2(x+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),add(u,v),add(v,u),X[i]=u,Y[i]=v;
	if(m==n-1){
		tt[0]=1;for(int i=1;i<=n;++i)tt[i]=(tt[i-1]<<1)%Mod;
		ans=(1ll*n*tt[m])%Mod;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				ans=(ans+(1ll*tt[j-i-1]*tt[n-j+i-1])%Mod)%Mod;
			}
		}
		return !printf("%d",ans);
	}
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j)vis[j]=0;
		l=i*2-1,dfs(1,1);
		int flag=1;
		for(int j=1;j<=n;++j)if(!vis[j]){flag=0;break;}
		if(flag)t[i]=0;
		else t[i]=1;
	}
	dfs2(1);
	return !printf("%d",ans);
}/*
4 4
1 2
2 3
3 1
1 4
*/