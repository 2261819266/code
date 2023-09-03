#include <bits/stdc++.h>

#define fo(x) freopen(#x".in", "r", stdin); freopen(#x".out", "w", stdout);
#define rep(i, l, r) for (int i = l, rep##i = r; i <= rep##i; ++i)
#define per(i, r, l) for (int i = r, per##i = l; i >= per##i; --i)

using namespace std; typedef long long ll; typedef unsigned long long ull;
bool St;
namespace IO {
const int max_io_buf = 1 << 17;
char I[max_io_buf], *p1, *p2;
inline char gc() {
	return p1 == p2 && (p2 = (p1 = I) + fread(I, 1, sizeof(I), stdin), p2 == p1) ? EOF : *p1++;
} 
//inline char gc() {
//	return (char)getchar();
//}
} 

template <typename T> void rd(T &x) {
	x = 0; char c = IO::gc(); bool f = false;
	while (!isdigit(c)) f |= (c == '-'), c = IO::gc();
	while (isdigit(c)) x = x * 10 + c - '0', c = IO::gc();
	if (f) x *= -1;
}

const int maxn = 5e5 + 5;
const int maxm = 1e6 + 5;
const int mod = 1e9 + 7;

void norm(int &x) {
	if (x >= mod) x -= mod;
	else if (x < 0) x += mod;
}
int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = (ll)a * a % mod) if (b & 1) c = (ll)c * a % mod;
	return c;
}

struct Edge {
	int to, nx;
};

int n, m, pw2[maxn + maxm];

int h[maxn], tt; Edge e[maxm * 2];
int H[maxn], Tt; Edge E[maxm * 2];
void adde(int u, int v) {
	e[++tt] = {v, h[u]}, h[u] = tt;
}
void Adde(int u, int v) {
	E[++Tt] = {v, H[u]}, H[u] = Tt;
}
#define fore(u, v) for (int i##u = h[u], v; v = e[i##u].to, i##u; i##u = e[i##u].nx)
#define Fore(u, v) for (int i##u = H[u], v; v = E[i##u].to, i##u; i##u = E[i##u].nx)

void init(int n) {
	pw2[0] = 1;
	rep (i, 1, n) norm(pw2[i] = 2 * pw2[i - 1]);
}

int D[maxn], L[maxn], S[maxn], T[maxn], sz[maxn];

void tarjan(int u, int fa) {
	D[u] = L[u] = ++*D, S[++*S] = u;
	fore (u, v) if (v != fa) {
		if (!D[v]) {
			tarjan(v, u), L[u] = min(L[u], L[v]);
		} else L[u] = min(L[u], D[v]);
	}
	if (D[fa] < L[u]) {
		++*T;
		for (int v; v = S[*S], S[*S + 1] != u; --*S)
			T[v] = *T, ++sz[*T];
	}
}

bitset<maxn> vs;
int f[maxn], g[maxn], Sz[maxn], Fw[maxn], A;

void dfs0(int u, int fa) {
	vs[u] = true;
	Fore (u, v) if (v != fa) {
		++Fw[v];
		if (!vs[v]) dfs0(v, u);
	}
}

void dfs(int u) {
	vs[u] = true;
	// f[u]
	g[u] = 1, Sz[u] = 0;
	int t = 1, t2 = 1;
	Fore (u, v) {
		int w = Fw[v];
//		cerr << v << " " << w << endl;
		if (vs[v]) continue;
		dfs(v);
		
		int P2 = pw2[w], P21 = P2 - 1;
		int d = (ll)g[v] * P2 % mod;

		Sz[u] += Sz[v] + w;
		g[u] = (ll)g[u] * d % mod;
		int o = (ll)f[v] * P21 % mod + d;
		norm(o);
		t = (ll)t * o % mod;
		t2 = (ll)t2 * d % mod;
	}
	f[u] = (ll)t * (pw2[sz[u]] - 1) % mod;
	norm(f[u] += (t - t2) % mod);
//	cerr << u << ": " << f[u] << " " << g[u] << endl;
}

bool Ed;

int main() {
	fo(barrack)
	cerr << (double)std::abs(&Ed - &St) / 1024.0 / 1024.0 << "Mb\n";
	rd(n), rd(m), init(n + m);
	rep (i, 1, m) {
		int u, v; rd(u), rd(v);
		adde(u, v), adde(v, u);
	}
	tarjan(1, n + 1);
	rep (u, 1, n) fore (u, v) if (T[u] < T[v])
		Adde(T[u], T[v]), Adde(T[v], T[u]);

	dfs0(1, 0);
	rep (i, 1, n) vs[i] = false;
	dfs(1);
	rep (u, 1, *T) {
		int s = m - Sz[u] - Fw[u];
		norm(A += (ll)f[u] * pw2[s] % mod);
	} 

	printf("%d", A);
	
//	rep (i, 1, Tn) cerr << T[i] << " ";
	cerr << "A" << A << endl;

	cerr << "\n" << double(clock()) / CLOCKS_PER_SEC << "s\n";
	return 0;
}

