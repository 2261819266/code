#include <cstdio>

const int maxn = 1e1 + 8;
int a[maxn], t[maxn], ans;

// C++ Version
void merge(int ll, int rr) {
	// 用来把 a 数组 [ll, rr - 1] 这一区间的数排序。 t
	// 数组是临时存放有序的版本用的。
	if (rr - ll <= 1)
		return;
	int mid = ll + (rr - ll >> 1);
	merge(ll, mid);
	merge(mid, rr);
	int p = ll, q = mid, s = ll;
	while (s < rr) {
		if (p >= mid || (q < rr && a[p] > a[q])) {
			t[s++] = a[q++];
			ans += mid - p;
		} else
			t[s++] = a[p++];
	}
	for (int i = ll; i < rr; ++i)
		a[i] = t[i];
}
// 关键点在于一次性创建数组，避免在每次递归调用时创建，以避免内存分配的耗时。

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	merge(0, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", t[i]);
	}
	return 0;
}
