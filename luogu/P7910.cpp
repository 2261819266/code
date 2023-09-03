#include <cstdio>
#include <type_traits>
#include <vector>
#include <algorithm>

struct Node {
	int x, i, to;
	bool operator<(const Node &b) const {
		return (x < b.x) || !(b.x < x) && i < b.i;
	}

	void operator++(int) {
		to++;
	}

	void operator--(int) {
		to--;
	}
};

std::vector<Node> a;

void P7910() {
	int n, q;
	scanf("%d%d", &n, &q);
	a.push_back({});
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back({x, i});
	}
	for (int i = 1; i <= n; i++) {
		a[i].to = 1;
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (a[j] < a[i])
					a[i].to++;
			}
		}
	}
	while (q--) {
		int k, x, y;
		scanf("%d%d", &k, &x);
		if (k == 1) {
			scanf("%d", &y);
			for (int i = 1; i <= n; i++) {
				if (i != x) {
					Node X = a[x];
					X.x = y;
					if (a[i] < a[x] && X < a[i]) {
						a[i]++, a[x]--;
					}
					if (a[x] < a[i] && a[i] < X) {
						a[i]--, a[x]++;
					}
				}
			}
			a[x].x = y;
		} else {
			printf("%d\n", a[x].to);
		}
	}
}

int main() {
	P7910();
	return 0;
}

