#include <bits/stdc++.h>
#define ls (u << 1)
#define rs (u << 1 | 1)
#define mid ((l + r) >> 1)

using namespace std;

const int maxn = 3e2 + 10;
const int maxm = 2e6 + 10;

int t;
int n, m, k;
int a[maxm];
int c[maxn << 2];
int siz[maxn << 2];

struct node {
	int fs = -1;
};

node tr[maxn << 2];

void pushup(int u) {
	if (tr[ls].fs == -1 && tr[rs].fs == -1) {
		tr[u].fs = -1;
	} else if (tr[ls].fs == -1) {
		tr[u].fs = tr[rs].fs;
	} else if (tr[rs].fs == -1) {
		tr[u].fs = tr[ls].fs;		
	} else {
		tr[u].fs = min(tr[ls].fs, tr[rs].fs);
	}
}

void build(int u, int l, int r) {
	if (l == r) {
		tr[u].fs = l;
		return;
	}
	build(ls, l, mid);
	build(rs, mid + 1, r);
	pushup(u);
}

void output(int u, int l, int r) {
	if (l == r) {
		cout << tr[u].fs << " ";
		return;
	}
	output(ls, l, mid);
	output(rs, mid + 1, r);
}

void modify(int u, int l, int r, int pos, int k) {
	if (l == r) {
		tr[u].fs = (k == 0 ? pos : -1);
		return;
	}
	if (pos <= mid) {
		modify(ls, l, mid, pos, k);
	} else {
		modify(rs, mid + 1, r, pos, k);
	}
	pushup(u);
}

int query(int u, int l, int r, int ql, int qr) {
	if (ql <= l && r <= qr) {
		return tr[u].fs;
	}
	int lans = -1, rans = -1;
	if (ql <= mid) {
		lans = query(ls, l, mid, ql, qr);
	}
	if (qr > mid) {
		rans = query(rs, mid + 1, r, ql, qr);
	}
	if (lans == -1 && rans == -1) {
		return -1;
	} else if (lans == -1) {
		return rans;
	} else if (rans == -1) {
		return lans;
	} else {
		return min(lans, rans);
	}
}

int st[maxn << 2][3];
int sta[maxn << 2];

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	cin >> t;
	while (t--) {
		memset(c, 0, sizeof(c));
		memset(st, 0, sizeof(st));
		memset(sta, 0, sizeof(sta));
		cin >> n >> m >> k;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		build(1, 1, n);
		if (k % 2 == 0) {
			for (int i = 1; i <= m; i++) {
				if (!c[a[i]]) {
					int s = query(1, 1, n, 1, n);
					c[a[i]] = s;
					st[s][++st[s][0]] = a[i];
					sta[a[i]] = st[s][0];
					if (st[s][0] == 2) {
						modify(1, 1, n, s, 1);
					}
					printf("1 %d\n", s);
				} else {
					if (sta[a[i]] == 2) {
						printf("1 %d\n", c[a[i]]);
						modify(1, 1, n, c[a[i]], 0);
						st[c[a[i]]][st[c[a[i]]][0]--] = 0;
						c[a[i]] = sta[a[i]] = 0;
					} else {
						printf("1 %d\n", n);
						printf("2 %d %d\n", c[a[i]], n);
						modify(1, 1, n, c[a[i]], 0);
						swap(st[c[a[i]]][1], st[c[a[i]]][2]);
						st[c[a[i]]][st[c[a[i]]][0]--] = 0;
						c[a[i]] = sta[a[i]] = 0;
					}
				}
			}
		} else {
		}
	}
	return 0;
}

