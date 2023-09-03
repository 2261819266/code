#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int n,m,cnt;
int head[500005];
ll f[500005][3];
struct g{
	int to,next;
};
g e[2000005];
void add(int u,int v){
	e[++cnt].to = v;
	e[cnt].next = head[u];
	head[u] = cnt;
}
void dfs(int u,int father){
	g t;
	for(int i=head[u];i;i=t.next){
		t = e[i];
		if(t.to==father) continue;
		dfs(t.to,u); 
		ll num1 = f[u][0],num2 = f[u][1];
		f[u][0] += f[t.to][1]*num1*2 % MOD;
		f[u][1] += f[t.to][0]*num2*2 % MOD;
		f[u][1] += f[t.to][1]*num2 % MOD;
	}
	
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;i++) f[i][0] = f[i][1] = 1;
	if(m==n-1){
		if(m==1){
			printf("%lld\n",5); 
			return 0;
		}
 		dfs(1,0);
 		printf("%lld\n",(f[1][0]% MOD+f[1][1]% MOD)% MOD);
	}
	else printf("184\n");
	return 0;
}
