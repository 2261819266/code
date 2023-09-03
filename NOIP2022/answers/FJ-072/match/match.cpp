#include <bits/stdc++.h>
#define ull unsigned long long
const int N = 2.5e5 + 10;
int T, n, Q, siz;
int a[N], b[N];
ull ans[N];
struct Query {
	int l, r, id;
} q[N];
ull cur;
bool cmp(Query A, Query B) {
	if (A.l / siz != B.l / siz) return A.l < B.l;
	else {
		if ((A.l / siz) & 1) return A.r < B.r;
		return A.r > B.r;
	}
}
int pre[N], nxt[N];
void add(int l, int r, int pos) {
	if (pos > r) {
		int mx1 = 0, mx2 = 0;
		for (int i = pos; i >= l; i--) {
			mx1 = std::max(mx1, a[i]);
			mx2 = std::max(mx2, b[i]);
			cur += mx1 * mx2;
		}
	}
	else {
		int mx1 = 0, mx2 = 0;
		for (int i = pos; i <= r; i++) {
			mx1 = std::max(mx1, a[i]);
			mx2 = std::max(mx2, b[i]);
			cur += mx1 * mx2;
		}
	}
}
void del(int l, int r, int pos) {
	if (pos == r) {
		int mx1 = 0, mx2 = 0;
		for (int i = pos; i >= l; i--) {
			mx1 = std::max(mx1, a[i]);
			mx2 = std::max(mx2, b[i]);
			cur -= mx1 * mx2;
		}
	}
	else {
		int mx1 = 0, mx2 = 0;
		for (int i = pos; i <= r; i++) {
			mx1 = std::max(mx1, a[i]);
			mx2 = std::max(mx2, b[i]);
			cur -= mx1 * mx2;
		}
	}
}
int st[N], top;
int main() {
  freopen("match.in", "r", stdin);
  freopen("match.out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  std::cin >> T >> n;
  siz = std::sqrt(n);
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1; i <= n; i++) std::cin >> b[i];
  st[0] = 0;
  for (int i = 1; i <= n; i++) {
  	while (top and a[i] > a[st[top]]) {
  		top--;
		}
		pre[i] = st[top] + 1;
		st[++top] = i;
	}
	top = 0;
	st[0] = n + 1;
	for (int i = n; i >= 1; i--) {
		while (top and a[i] > a[st[top]]) {
			top--;
		}
		nxt[i] = st[top] - 1;
		st[++top] = i;
	}
  std::cin >> Q;
  for (int i = 1; i <= Q; i++) {
  	std::cin >> q[i].l >> q[i].r;
  	q[i].id = i;
	}
	std::sort(q + 1, q + Q + 1, cmp);
	cur = 0;
	int l = 1, r = 0;
	for (int i = 1; i <= Q; i++) {
		while (r < q[i].r) {
			add(l, r, r + 1);
			r++;
		}
		while (l > q[i].l) {
			add(l, r, l - 1);
			l--;
		}
		while (r > q[i].r) {
			del(l, r, r);
			r--;
		}
		while (l < q[i].l) {
			del(l, r, l);
			l++;
		}
		ans[q[i].id] = cur;
	}
	for (int i = 1; i <= Q; i++) std::cout << ans[i] << "\n";
  return 0;
}

