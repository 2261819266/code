#include <cstdio>
#include <algorithm>
#include <cstring>

const int N = 5e5+10,M = 1e6+2,p = 1e9+7;
int head[M<<1],Next[M<<1],ver[M<<1],tot;
inline void add(int x,int y){
	ver[++tot] = y,Next[tot] = head[x],head[x] = tot;
}
int n,m,v[N],vhh,bri[M<<1],dfn[N],low[N],num;
bool vis[M];
void tarjan(int x);
int dfs(int x,int cnt);
inline int power(int b){
	int a = 2,res = 1;
	while (b){
		if (b&1)
			res = res*a%p;
		b >>= 1;
		a = a*a%p;
	}
	return res;
}

int main(){
	scanf("%d%d",&n,&m);
	tot = 1;
	for (int i = 1;i <= m;++i){
		int x,y;
		scanf("%d %d",&x,&y);
		add(x,y);
		add(y,x);
	}

	tarjan(1);


	for (int i = 1;i <= n;++i)
		if (vis[i] == false){
			v[vhh] = dfs(i,0);
			vhh++;
		}

	int yyy = 0,cjx = 1;
	for (int i = 0;i < vhh;++vhh){
		yyy = (power(v[i])+yyy)%p;
		cjx = (power(v[i]-1)*cjx)%p;
	}
	int ans = power(m-1)*((2*yyy-N)%p + cjx)%p;
	printf("%d\n",ans);
	return 0;
}

void tarjan(int x){
	low [x] = dfn[x] = ++num;
	for (int i = head[x];i;i = Next[i]){
		int y = ver[i];
		if (vis[i] == false){
			tarjan(y);
			low[x] = std::min(low[x],low[y]);
		}
		else
			low[x] = std::min(low[x],dfn[y]);
		vis[i] = vis[i^1] = true;
		if (dfn[x] < low[x])
			bri[i^1] = bri[i] = true;
	}
}

int dfs(int x,int cnt){
	int res = 0;
	vis[x] = true;
	for (int i = head[x];i;i = Next[i]){
		if (bri[i]) continue;
		int y = ver[i];
		if (vis[y] == false)
			res += dfs(y,cnt+1);
	}
	return res;
}
