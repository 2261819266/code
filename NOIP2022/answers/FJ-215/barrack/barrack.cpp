#include <iostream>
#include <cstdio>
using namespace std;

typedef long long LL;
const int MAXN = 2000000 + 10;
const LL MOD = 1000000007;
int N, M;
struct Edge {
	int u, v, nxt;
	Edge (int u = 0, int v = 0, int nxt = 0) : u(u), v(v), nxt(nxt) {}
} e[MAXN];
LL fir[MAXN], tote = -1; // 0开始计数 
LL po[MAXN];
bool bookp[MAXN], booke[MAXN];
LL f[MAXN];

void addedge(int x, int y) {
	e[++tote] = Edge(x, y, fir[x]);
	fir[x] = tote;	
}
void worA() {
	po[0] = 1;
	for(int i = 1; i <= N + 3; i++)
		po[i] = (po[i - 1] * 2) % MOD;
	LL ans = po[N - 1] * N % MOD;
	for(int i = 2; i <= N; i++)
		ans = (ans + po[N - i] * po[i - 2] % MOD * (N + 1 - i) % MOD) % MOD;
	printf("%lld\n", ans);
}
LL fin(LL x) {
	if(f[x] == x) return x;
	return f[x] = fin(f[x]);
}
bool che(LL k) {
	for(int i = 1; i <= N; i++) f[i] = i; // clear
	for(int i = 1; i <= N; i++)
		for(int j = fir[i]; j; j = e[j].nxt) {
			if(j == k || j == k ^ 1) continue;
			LL y = e[j].v;
			LL fx = fin(i), fy = fin(y);
			if(fx == fy) continue;
			f[fy] = fx;
		}
	LL id = -1;
	for(int i = 1; i <= N; i++) 
		if(bookp[i]) {
			if(id == -1) {
				id = fin(i);
				continue;
			} else
				if(id != fin(i)) {
					return false;
					break;
				}
		}
	return true;
}
bool check(LL poi, LL edg) {
	for(int i = 1; i <= N; i++) bookp[i] = false;
	for(int i = 0; i <= (M << 1); i++) booke[i] = false; // clear
	LL t = poi, k = 1;
	while(t > 0) {
		if(t & 1) bookp[k] = true; // true jun ying
		t >>= 1; k++;
	}
	t = edg, k = 0;
	while(t > 0) {
		if(t & 1) booke[k] = booke[k ^ 1] = true; // true kan shou
		t >>= 1; k += 2;
	}
	
	bool h = true;
	for(int l = 0; l < M * 2; l += 2) {
		if(booke[l] || booke[l ^ 1]) continue;
		if(!che(l)) h = false;
	}
	
	return h;
}
void worB() {
	LL ans = 0;
	for(LL poi = 1; poi <= (1LL << N) - 1; poi++)
		for(LL edg = 0; edg <= (1LL << M) - 1; edg++) if(check(poi, edg)) ans = (ans + 1) % MOD;
	printf("%lld\n", ans);
}
int main() {
	#ifdef test
		freopen("test.txt", "r", stdin);
	#else
		freopen("barrack.in", "r", stdin);
		freopen("barrack.out", "w", stdout);
	#endif
	bool isA = true;
	cin >> N >> M;
	if(M != N - 1) isA = false;
	int x, y;
	for(int i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		addedge(x, y); addedge(y, x);
//		OE[i] = Edge(x, y, 0);
		if(x != i || y != i + 1) 
			if(x != i + 1 || y != i) 
				isA = false;
	}
	if(isA) worA();
	else worB();
	return 0;
}

