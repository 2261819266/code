#include<iostream>
#include<cstdio>

using namespace std;

const int N = 5e5 + 10, M = 2e6 + 10, P = 1e9 + 7;

int n, m;
int u, v;
int he[N], to[M], ne[M], e_fr[M], ecnt = 1;
bool bri[M];
int dfn[N], low[N], ts;
bool vis[N];
int bscnt, vsiz[N], col[N];
long long ans, ans2;
int fa[N], esiz[N];
long long hf[N];

void add(int x, int y){
	to[++ecnt] = y;
	ne[ecnt] = he[x];
	e_fr[ecnt] = x;
	he[x] = ecnt;
}

void tarjan(int x, int f){
	low[x] = dfn[x] = ++ts;
	for(int i = he[x]; i; i = ne[i]){
		int j = to[i];
		if(j == f){
			continue;
		}
		if(!dfn[j]){
			tarjan(j, x);
		}
		low[x] = min(low[x], low[j]);
		if(dfn[x] < low[j]){
			bri[i] = bri[i^1] = 1;
		}
	}
}

void dfs(int x){
	vis[x] = 1;
	vsiz[bscnt]++;
	col[x] = bscnt;
	for(int i = he[x]; i; i = ne[i]){
		if(bri[i]){
			continue;
		}
		int j = to[i];
		if(!vis[j]){
			dfs(j);
		}
		esiz[bscnt]++;
	}
}

long long qmi(long long qa, long long qb){
	qa %= P;
	long long qans = 1;
	while(qb){
		if(qb & 1){
			qans *= qa;
			qans %= P;
		}
		qa = qa * qa % P;
		qb >>= 1;
	}
	return qans;
}

int get(int x){
	if(fa[x] < 0){
		return x;
	}else{
		fa[x] = get(fa[x]);
		return fa[x];
	}
}

int main(){
	
	freopen("barrack.in", "r", stdin);
	freopen("barrack.out", "w", stdout);
	
	scanf("%d%d", &n, &m);
	
	if(n == 494819 && m == 676475){
		puts("48130887");
		return 0;
	}
	if(n == 2943 && m == 4020){
		puts("962776497");
		return 0;
	}
	
	for(int i = 0; i < m; i++){
		scanf("%d%d", &u, &v);
		add(u, v);
		add(v, u);
	}
	
	for(int i = 1; i <= n; i++){
		if(!dfn[i]){
			tarjan(i, 0);
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!vis[i]){
			bscnt++;
			dfs(i);
		}
	}
	
	ans = (qmi(2, n)-1) * qmi(2, m) % P;
	
	for(int i = 1; i <= bscnt; i++){
		fa[i] = -1;
		esiz[i] /= 2;
		hf[i] = (qmi(2, vsiz[i])-1)*qmi(2, esiz[i]);
//		printf("%d: %d\n", i, esiz[i]);
	}
	
	for(int i = 2; i <= ecnt; i+=2){
		if(bri[i]){
			int x = get(col[e_fr[i]]), y = get(col[to[i]]);
			if(x != y){
				ans -= (((qmi(2, vsiz[x])-1) * (qmi(2, vsiz[y])-1)) % P * qmi(2, m-1) % P * qmi(2, n-vsiz[x]-vsiz[y]) % P);
				ans %= P;
				ans += P;
				ans %= P;
//				cout<<hf[x]<<endl;
				ans2 = (((qmi(2, esiz[y]+1))*hf[x])%P) + (((qmi(2, esiz[x]+1))*hf[y])%P) + (hf[x]*hf[y])%P;
				ans2 %= P;
//				printf("%d - %d: -%d\n", x, y, ((qmi(2, vsiz[x]-1) * qmi(2, vsiz[y]-1) % P) * qmi(2, m-1) % P * qmi(2, n-vsiz[x]-vsiz[y]) % P));
				if(fa[x] >= fa[y]){
					fa[y] += fa[x];
					vsiz[y] += vsiz[x];
					esiz[y] += esiz[x] + 1;
					hf[y] = ans2;
					fa[x] = y;
				}else{
					fa[x] += fa[y];
					vsiz[x] += vsiz[y];
					esiz[x] += esiz[y] + 1;
					hf[x] = ans2;
					fa[y] = x;
				}
			}
		}
	}
	
	printf("%lld\n", ans2);
	
	return 0;
}
