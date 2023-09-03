
#include <bits/stdc++.h>

using namespace std; const int maxn = 2.5e5 + 5; typedef unsigned long long ull;

int T, n, a[maxn], b[maxn];

int p[maxn], pl[maxn], pr[maxn];

const int S = 189;

ull A[maxn], B[maxn], AB[maxn];

ull sab[maxn / S + 5], sa[maxn / S + 5], sb[maxn / S + 5], da[maxn / S + 5], db[maxn / S + 5], len[maxn / S + 5];

ull pAB[maxn], pA[maxn], pB[maxn];

inline void spread(int u)
{
	int L = pl[u], R = pr[u];
	ull dA = da[u], dB = db[u], dAB = dA * dB; da[u] = db[u] = 0;
	for (int i = L; i <= R; i++)
	{
		AB[i] = AB[i] + dA * B[i] + dB * A[i] + dAB;
		A[i] += dA, B[i] += dB;
	}
}

inline void maintain(int u, bool need = 0)
{
	int L = pl[u], R = pr[u];
	ull &sA = sa[u], &sB = sb[u], &sAB = sab[u]; sA = sB = sAB = 0;
	for (int i = L; i <= R; i++) sAB += AB[i], sA += A[i], sB += B[i];
	if (need)
	{
		pAB[L] = AB[L];
		pA[L] = A[L];
		pB[L] = B[L];
		for (int i = L + 1; i <= R; i++) pAB[i] = pAB[i - 1] + AB[i], pA[i] = pA[i - 1] + A[i], pB[i] = pB[i - 1] + B[i];
	}
}

inline void editA(int l, int r, ull d, bool need = 0)
{
	if (p[l] == p[r])
	{
		spread(p[l]);
		for (int i = l; i <= r; i++) AB[i] += d * B[i], A[i] += d;
		maintain(p[l], need);
		return;
	}
	int L = p[l] + 1, R = p[r] - 1;
	for (int i = L; i <= R; i++)
	{
		sab[i] += d * sb[i], sa[i] += d * len[i], da[i] += d;
	}
	editA(l, pr[p[l]], d, need), editA(pl[p[r]], r, d, need);
}

inline void editB(int l, int r, ull d, bool need = 0)
{
	if (p[l] == p[r])
	{
		spread(p[l]);
		for (int i = l; i <= r; i++) AB[i] += d * A[i], B[i] += d;
		maintain(p[l], need);
		return;
	}
	int L = p[l] + 1, R = p[r] - 1;
	for (int i = L; i <= R; i++)
	{
		sab[i] += d * sa[i], sb[i] += d * len[i], db[i] += d;
	}
	editB(l, pr[p[l]], d, need), editB(pl[p[r]], r, d, need);
}

ull SS[maxn / S + 5];

inline ull query(int l, int r)
{
	int L = p[l], R = p[r];
	return (R ? SS[R - 1] : 0) + pAB[r] + pA[r] * db[R] + pB[r] * da[R] + da[R] * db[R] * (r - pl[R] + 1);
}

int s1[maxn], s2[maxn], t1, t2;

vector<int> Ask[maxn];

int Q, ql[maxn], nr[maxn], qr[maxn]; ull Ans[maxn];

int q[2][maxn], cur;

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d%d", &T, &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) scanf("%d%d", ql + i, qr + i);
//	cerr << clock() / 1.0 / CLOCKS_PER_SEC << endl;
	for (int i = 1; i <= n; i++) p[i] = i / S;
	for (int i = 1; i <= n; i++) pr[p[i]] = i;
	for (int i = n; i >= 1; i--) pl[p[i]] = i;
	for (int i = 0; i <= p[n]; i++) len[i] = pr[i] - pl[i] + 1;
	for (int i = 1; i <= Q; i++) Ask[qr[i]].push_back(i);
//	cerr << "!";
	for (int i = 1; i <= n; i++)
	{
//		cerr << "for: " << i << endl;
		while (t1 && a[s1[t1]] < a[i]) editA(s1[t1 - 1] + 1, s1[t1], a[i] - a[s1[t1]]), t1--; s1[++t1] = i; editA(i, i, a[i]);
		while (t2 && b[s2[t2]] < b[i]) editB(s2[t2 - 1] + 1, s2[t2], b[i] - b[s2[t2]]), t2--; s2[++t2] = i; editB(i, i, b[i]);
		int R = p[i];
		for (int j = 0; j <= R; j++) SS[j] += sab[j];
		for (int e : Ask[i])
		{
//			cerr << "e: " << e << endl;
			int L = p[ql[e]] + 1;
			for (int j = L; j <= R; j++) Ans[e] += SS[j];
			nr[e] = min(qr[e], pr[L - 1]);
		}
		Ask[i].clear();
	}
//	cerr << "Ans: "; for (int i = 1; i <= Q; i++) cerr << Ans[i] << ' '; cerr << endl;
//	cerr << "?";
//	cerr << "nr: "; for (int i = 1; i <= Q; i++) cerr << nr[i] << ' '; cerr << endl;
//	for (int i = 1; i <= n; i++) assert(pAB[i] == 0);
	for (int i = 1; i <= Q; i++) Ask[nr[i]].push_back(i);
	for (int i = 1; i <= n; i++) A[i] = B[i] = AB[i] = 0;
	for (int i = 0; i <= p[n]; i++) sab[i] = sa[i] = sb[i] = da[i] = db[i] = SS[i] = 0;
	s1[t1 = 0] = s2[t2 = 0] = n + 1;
	for (int i = n; i; i--)
	{
//		cerr << "[";
		while (t1 && a[s1[t1]] < a[i]) editA(s1[t1], s1[t1 - 1] - 1, a[i] - a[s1[t1]], 1), t1--; s1[++t1] = i; editA(i, i, a[i], 1);
		while (t2 && b[s2[t2]] < b[i]) editB(s2[t2], s2[t2 - 1] - 1, b[i] - b[s2[t2]], 1), t2--; s2[++t2] = i; editB(i, i, b[i], 1);
		SS[0] = sab[0];
		for (int j = 1; j <= p[n]; j++) SS[j] = SS[j - 1] + sab[j];
//		cerr << "sab: " << sab[0] << endl;
		for (int e : Ask[i])
		{
			q[cur][++*q[cur]] = e;
		}
		*q[cur ^ 1] = 0;
		for (int j = 1; j <= *q[cur]; j++)
		{
			int e = q[cur][j], r = qr[e];
			Ans[e] += query(i, qr[e]);
			assert((ql[e] <= i));
			if (ql[e] < i) q[cur ^ 1][++*q[cur ^ 1]] = e;
		}
		cur ^= 1;
	}
	for (int i = 1; i <= Q; i++) printf("%llu\n", Ans[i]);
	return 0;
}


