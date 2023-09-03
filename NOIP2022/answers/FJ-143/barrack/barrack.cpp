#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define eb emplace_back
using namespace std;
typedef long long ll;
const int p=1000000007,inv=500000004;
int n,m,x,y,pw[1000005],ans;
int head[500005],to[2000005],nex[2000005],cnt=1;
int dfn[500005],low[500005],stk[500005],top;
int N,col[500005],a[500005],f[500005];
vector<int> e[500005];
inline void adde(int f,int t){
	to[++cnt]=t;
	nex[cnt]=head[f];
	head[f]=cnt;
}
inline void paint(){
	int u=stk[top--];
	col[u]=N,++a[N];
}
void tarjan(int u,int j){
	dfn[u]=low[u]=++cnt;
	stk[++top]=u;
	for(int i=head[u],v;i;i=nex[i]){
		if(i==(j^1))continue;
		v=to[i];
		if(!dfn[v]){
			tarjan(v,i);
			low[u]=min(low[u],low[v]);
		}
		else low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u]){
		++N;
		while(stk[top]^u)paint();
		paint();
	}
}
void dfs(int u,int pre){
	int g=1,tmp=0,val;
	for(auto v:e[u]){
		if(v==pre)continue;
		dfs(v,u);
		val=((ll)f[v]*inv+1)%p;
		g=(ll)g*val%p;
		tmp=(tmp+val-1)%p;
	}
	f[u]=((ll)g*pw[a[u]]-1)%p;
	ans=((ll)ans+f[u]-tmp)%p;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m),pw[0]=1;
	for(int i=1;i<=max(n,m);++i)
		pw[i]=(pw[i-1]<<1)%p;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&x,&y);
		adde(x,y),adde(y,x);
	}
	cnt=0,tarjan(1,0);
	for(int i=1;i<=m;++i){
		x=col[to[i<<1]],y=col[to[i<<1|1]];
		if(x^y)e[x].eb(y),e[y].eb(x);
	}
	dfs(1,0);
	ans=(ll)ans*pw[m]%p;
	printf("%d\n",(ans+p)%p);
	return 0;
}
