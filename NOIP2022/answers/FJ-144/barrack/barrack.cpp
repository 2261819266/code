#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
#define int long long
const int Mod = 1e9 + 7;
const int N = 5005;
const int M = 5005;
bool st;
int Sz[N] , sz[N];
int ver[M << 1] , nxt[M << 1] , head[M] , bel[N] , b[M << 1] , dfn[N] , low[N] , num , tot , cnt , orz , Nw , o;
int pw[M << 1] , n , m , Ans;
vector<int> g[N]; 
bool ed;
inline int read() {
	int x = 0 , ff = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9') {
		if(ch == '-') ff = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar(); 
	}
	return x * ff;
}

inline int Add(int x , int y) {return x + y >= Mod ? x + y - Mod : x + y;}
inline int Dec(int x , int y) {return x < y ? x - y + Mod : x - y;}

inline void add(int x , int y) {
	ver[++tot] = y; nxt[tot] = head[x]; head[x] = tot;
}

inline void tarjan(int x , int in) {
	dfn[x] = low[x] = ++cnt; 
	for(int i = head[x];i;i = nxt[i]) {
		int y = ver[i]; 
		if(!dfn[y]) {
			tarjan(y , i);
			low[x] = min(low[x] , low[y]);
			if(dfn[x] < low[y]) b[i] = b[i ^ 1] = 1;
		}
		else if(i ^ (in ^ 1)) low[x] = min(low[x] , dfn[y]);
	}
}

inline void dfs(int x) {
	bel[x] = num; sz[num]++;
	for(int i = head[x];i;i = nxt[i]) {
		int y = ver[i]; if(bel[y] || b[i]) continue;
		dfs(y);
	}
}

inline void solve(int x , int fa) {
	for(auto y : g[x]) {
		if(y == fa) continue; solve(y , x); 
		Sz[x] += Sz[y]; if(Sz[y] != o && Sz[y]) ++Nw;   
	}
}

signed main () {
	freopen("barrack.in" , "r" , stdin); freopen("barrack.out" , "w" , stdout);
//	cerr << (&st - &ed) / 1048576.0 << "MB" << endl; 
	n = read(); m = read(); tot = 1; pw[0] = 1;
	for(int i = 1;i <= n + m;i++) pw[i] = pw[i - 1] * 2LL % Mod;
	for(int i = 1;i <= m;i++) {
		int u , v; u = read(); v = read();
		add(u , v); add(v , u);
	}
	for(int i = 1;i <= n;i++) if(!dfn[i]) tarjan(i , 0);
	for(int i = 1;i <= n;i++) if(!bel[i]) {++num; dfs(i);} 
	for(int i = 1;i <= n;i++) {
		for(int j = head[i];j;j = nxt[j]) {
			int y = ver[j]; if(bel[i] ^ bel[y]) g[bel[i]].push_back(bel[y]) , ++orz;
		}
	} 
	for(int i = 1;i < (1 << num);i++) {
		int nw = 1;
		for(int j = 1;j <= num;j++) Sz[j] = 0; o = 0; 
		for(int j = 1;j <= num;j++) {
			if(i & (1 << (j - 1))) nw = nw * Dec(pw[sz[j]] , 1) % Mod , Sz[j]++ , o++;
		} 
		Nw = 0; solve(1 , 0); Ans = Add(Ans , nw * pw[m - Nw] % Mod);
	} 
	printf("%lld\n" , Ans);
	return 0;
}
