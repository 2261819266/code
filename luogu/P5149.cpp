#include <cstdio>
// #include <algorithm>
#include <map>
#include <cstring>
#define ll long long

struct string {
	static const int maxn = 10;
	char *data;
	string() { data = new char[maxn]; }

	char &operator[](int x) {
		return data[x];
	}

	string operator=(const char *str) {
		strncpy(data, str, maxn);
		return *this;
	}

	bool operator<(const string &x) const {
		return strcmp(data, x.data) < 0;
	}
};

std::map<string, int> m;

const int maxn = 1e5 + 8;
int a[maxn];


int merge(int *first, int *last) {
	int *mid = first + ((last - first) >> 1);
	ll ans;
	if (first == mid) return 0;
	ans = merge(first, mid) + merge(mid, last);
	int *k = new int[last - first];
	for (int *i = first, *j = mid; i != mid || j != last; k++) {
		if (*i <= *j && i != mid || j == last)
			*k = *i, i++;
		else
			*k = *j, j++, ans+= mid - i;
	}
	k -= (last - first);
	for (int *i = first; i != last; i++, k++) {
		*i = *k;
	}
	return ans;
}

int main(int argc, char const *argv[]) {
#ifdef LOCAL
	LOCALfo
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string c;
		char s[10];
		scanf("%s", s);
		c = s;
		m[c] = i;
	}
	for (int i = 0; i < n; i++) {
		string c;
		char s[10];
		scanf("%s", s);
		c = s;
		a[i] = m[c];
	}
	printf("%lld", merge(a, a + n));
	return 0;
}

// #include <cstdio>

// int main() {
// 	freopen("E:\\code\\in.in", "w", stdout);
// 	printf("100000\n");
// 	for (int i = 100000; i > 0; i--)
// 		printf("%d ", i);
// 	for (int i = 1; i <= 100000; i++)
// 		printf("%d ", i);
// }