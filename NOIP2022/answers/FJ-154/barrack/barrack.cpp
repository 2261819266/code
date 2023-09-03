#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<vector>
#include<bitset>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int MAXN=1e6+50,INF=0x3f3f3f3f,MOD=1e9+7;

int read(){
	int flag=1,cnt=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-') flag=-1;c=getchar();}
	while(c>='0'&&c<='9') cnt=(cnt<<1)+(cnt<<3)+(c^48),c=getchar();
	return flag*cnt;
}

//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 
//多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 多测要清空！！！ 

struct edge{
	int nxt;
	int to;
};

edge e[MAXN<<1];
int head[MAXN],Cnte=0;
int N,M,siz[MAXN];
LL f[MAXN][2],g[MAXN],pw[MAXN];
LL Ans=0;

void adde(int u,int v){
	++Cnte;
	e[Cnte].to=v;
	e[Cnte].nxt=head[u];
	head[u]=Cnte;
}

void dfs(int u,int father){
	f[u][0]=1;f[u][1]=0;siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt){
		int v=e[i].to;
		if(v==father) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		f[u][1]=(f[u][0]*g[v]+f[u][1]*(g[v]+pw[siz[v]]))%MOD;
		f[u][0]=f[u][0]*pw[siz[v]]%MOD;
	}
	g[u]=(f[u][0]+f[u][1]*2)%MOD;
}

void Init(){
	N=read();M=read();
	for(int i=1;i<=M;++i){
		int u=read(),v=read();
		adde(u,v);adde(v,u);
	}
}

void Solve(){
	pw[0]=1;
	for(int i=1;i<=N;++i) pw[i]=pw[i-1]*2%MOD;
	dfs(1,0);
	Ans=g[1];
	for(int i=2;i<=N;++i) Ans=(Ans+g[i]*pw[N-siz[i]-1])%MOD;
}

void Print(){
	printf("%lld\n",Ans);
	//for(int i=1;i<=N;++i) printf("%lld ",g[i]);
}

int main()
{
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	Init();
	Solve();	
	Print();
	return 0;
}
/*
4 3
1 2
2 3
1 4
*/
