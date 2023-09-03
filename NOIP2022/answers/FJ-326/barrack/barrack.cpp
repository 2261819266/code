#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<bitset>
#include<map>
#define int long long
#define mod Mod
using namespace std;
const int N=2e6+10,Mod=1e9+7;
int n,m;
int cnt,f[N],to[N],nex[N];
int sum[N],dp[N];
map<int,map<int,bool> > vis;
void add(int x,int y){
	to[++cnt]=y,nex[cnt]=f[x],f[x]=cnt;
	to[++cnt]=x,nex[cnt]=f[y],f[y]=cnt;
	return;
}

int Cnt,F[N],To[N],Nex[N];
void Add(int x,int y){
	To[++Cnt]=y,Nex[Cnt]=F[x],F[x]=Cnt;
	To[++Cnt]=x,Nex[cnt]=F[y],F[y]=Cnt;
	return;
}

int dfn[N],low[N],st[N],col[N],val[N];
int top,Times,tot;
void T(int x,int father){
	dfn[x]=low[x]=++Times;
	st[++top]=x;
	for (int i=f[x];i;i=nex[i]){
		if (to[i]==father) continue;
		if (!dfn[to[i]]){
			T(to[i],x);
			low[x]=min(low[to[i]],low[x]);
		}
		else if (!col[to[i]])
 			{low[x]=min(low[to[i]],low[x]);}
 	}
 	if (low[x]==dfn[x]){
 		tot++;
		while (st[top+1]!=x)
			col[st[top]]=tot,top--,val[tot]++; 	
	}
	return;
}

int g[N];

void dfs(int x,int father){
	int v,len=0;
	g[0]=g[1]=0;
	for (int i=F[x];i;i=Nex[i]){
		v=To[i];
		if (v==father) continue;
		for (int j=0;j<=len;j++) {
			dp[x]+=dp[to[i]]*g[j]%mod;
			dp[x]%=mod;
			g[j+1]+=dp[to[i]]*g[j]%mod;
			g[j+1]%=mod;
		}
		len++;
		g[len+1]=0;
	}
}
void init(){
	sum[0]=1;
	for (int i=1;i<=n;i++) 
		sum[i]=sum[i-1]*i%mod;
	return;
}
signed main(){
//	freopen("barrack.in","r",stdin);
//	freopen("barrack.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	init();
	int u,v;
	for (int i=1;i<=m;i++){
		scanf("%lld%lld",&u,&v);
		add(u,v);
	}
	for (int i=1;i<=n;i++)
		if (!dfn[i]) T(i,-1);
	for (int i=1;i<=n;i++){
		for (int j=f[i];j;j=nex[i]) {
			if (col[to[j]]==col[i]) continue;
			if (vis[(int)col[to[j]]][(int)col[i]]) continue;
			vis[(int)col[to[j]]][(int)col[i]]=1;
			Add(i,to[j]);
		}
	}
	
	dfs(1,-1);
	
	printf("%lld\n",dp[1]);
	return 0;
}
