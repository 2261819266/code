#include <bits/stdc++.h>
const int M = 2e6, N = 300;
int n, m, k, a[M + 10];
std::deque<int> sta[N + 10];
void work() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; i++) scanf("%d", &a[i]), a[i]--;
	if (k == 2 * n - 2) {
		for (int i = 1; i <= m; i++) {
			if (sta[a[i] >> 1].empty() or sta[a[i] >> 1].back() != a[i]) {
				if (sta[a[i] >> 1].front() == a[i]) sta[a[i] >> 1].pop_front();
				else sta[a[i] >> 1].push_front(a[i]);
				printf("1 %d\n", (a[i] >> 1) + 1);
			}
			else printf("1 %d\n2 %d %d\n", n, (a[i] >> 1) + 1, n), sta[a[i] >> 1].pop_back();
		}
	}
}
int main(int _, char **ch) {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	for (scanf("%d", &_); _--;) work();
	return 0;
}

