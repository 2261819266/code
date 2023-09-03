#include <bits/stdc++.h>
using namespace std;
const int mxn = 305, mxm = 2e6 + 10;

int _, n, m, k, a[mxm];

struct node {
	int val, t;
	node (int val = 0, int t = 0) : val(val), t(t) {}
};

struct stack2 {
	int siz;
	node up, dn;
	stack2() : siz(0) {}
	void push(node x) {
		++siz, up = x;
		if (siz == 1) dn = x;
	}
	void pop() {
		assert(siz), --siz;
		if (siz) up = dn;
		else up = dn = node();
	}
	void pb() {
		assert(siz), --siz;
		if (siz) dn = up;
		else up = dn = node();
	}
	void ib(node x) {
		dn = x, ++siz;
		if (siz == 1) up = x;
	}
};

void solve() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) scanf("%d", a + i);
	vector<tuple<int, int, int>> ops;
	auto op1 = [&](int x) { ops.emplace_back(1, x, x); };
	auto op2 = [&](int x, int y) { ops.emplace_back(2, x, y); };
	if (k == 2 * n - 2) {
		static int tp[mxn], bt[mxn];
		for (int i = 1; i <= n; ++i) tp[i] = bt[i] = 0;
		for (int i = 1; i <= m; ++i) {
			int p = (a[i] + 1) >> 1;
			if (bt[p] == a[i]) {
				op1(n), op2(p, n);
				if (tp[p] == bt[p]) tp[p] = bt[p] = 0;
				else bt[p] = tp[p];
			} else if (tp[p] == a[i]) {
				op1(p);
				if (tp[p] == bt[p]) tp[p] = bt[p] = 0;
				else tp[p] = bt[p];
			} else {
				op1(p), tp[p] = a[i];
				if (!bt[p]) bt[p] = a[i];
			} 
		}
	} else {
		static stack2 stk[mxn];
		static int tar[mxm], cur[mxn * 2];
		set<int> s[3];
		vector<tuple<int, int, int>> opv2;
		for (int i = 1; i <= 2 * n; ++i) cur[i] = 0;
		for (int i = 1; i <= n; ++i) s[0].emplace(i);
//		int tot = 0;
		for (int i = 1; i <= m; ++i) {
			// printf("i = %d\n", i);
			if (a[i] == a[i + 1]) {
				tar[i] = tar[i + 1] = 1, ++i;
				continue;
			}
			if (cur[a[i]]) {
				int p = cur[a[i]];
				// printf("cur[%d] = %d\n", a[i], cur[a[i]]);
				if (stk[p].up.val == a[i]) s[stk[p].siz].erase(p), stk[p].pop(), tar[i] = p, s[stk[p].siz].emplace(p); // go to same place
				else {
					assert(stk[p].siz == 2);
					auto &up = stk[p].up, &dn = stk[p].dn;
					assert(dn.t < up.t && a[i] == dn.val);
					if (s[0].size()) {
						int q = *begin(s[0]);
						s[stk[p].siz].erase(p);
						tar[i] = q, opv2.emplace_back(i, p, q), stk[p].pb();
						s[stk[p].siz].emplace(p);
					} else {
						assert(s[1].size());
						int q = *begin(s[1]);
						for (int x : s[1])
							if (stk[x].up.t > stk[q].up.t) q = x;
						node &rhs = stk[q].up;
						if (up.t < rhs.t) {
							tar[rhs.t] = p, tar[i] = q;
							opv2.emplace_back(i, p, q);
							stk[p].pb(), stk[p].push(rhs), cur[rhs.val] = p, stk[q].pop();
							s[1].erase(q), s[0].emplace(q);
						} else {
							tar[up.t] = q, tar[i] = p;
							// printf("%d & %d -- %d\n", up.val, dn.val, rhs.val);
							cur[up.val] = q, stk[q].push(up), stk[p].pb(), stk[p].pop();
							s[2].erase(p), s[1].erase(q);
							s[0].emplace(p), s[2].emplace(q);
						}
					}
				}
				cur[a[i]] = 0;
//				tot -= 2;
			} else {
				int iz = 0;
				for (; iz < 2; ++iz)
					if (s[iz].size()) {
						auto p = begin(s[iz]);
						stk[*p].push(node(a[i], i));
						cur[a[i]] = tar[i] = *p;
						s[iz + 1].emplace(*p);
						s[iz].erase(p);
						break;
					}
				if (iz >= 2) puts("No position to set"), assert(0);
			}
//			int sum = 0;
//			for (int siz = 0; siz < 3; ++siz) {
//				printf("siz = %d\n", siz);
//				for (int v : s[siz])
//					printf("in [%d]\n", v);
//				sum += siz * s[siz].size();
//			}
//			printf("tot = %d\n", ++tot);
//			assert(sum == tot);
//			for (int i = 1; i <= n; ++i)
//			printf("stk[%d]: %d & %d\n", i, stk[i].up.val, stk[i].dn.val);
		}
		for (int i = 1, j = 0; i <= m; ++i) {
			op1(tar[i]);
			while (j < (int)opv2.size() && get<0>(opv2[j]) == i) op2(get<1>(opv2[j]), get<2>(opv2[j])), ++j;
		}
	}
	printf("%d\n", (int)ops.size());
	for (auto tp: ops) {
		int op = get<0>(tp), x = get<1>(tp), y = get<2>(tp);
		if (op == 1) printf("1 %d\n", x);
		else printf("2 %d %d\n", x, y);
	}
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	for (scanf("%d", &_); _--;) solve();
	return 0;
}
