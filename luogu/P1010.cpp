#include <cstdio>
#include <stack>
#define stack std::stack<bool>

stack From10To2(int x) {
	stack a;
	while (x > 0) {
		a.push(x % 2);
		x /= 2;
	}
	return a;
}

void solve(int x) {
	if (x == 1) {
		printf("2(0)");
		return;
	}
	if (x == 2) {
		printf("2");
		return;
	}
	stack a = From10To2(x);
	bool k = false;
	while (!a.empty()) {
		int y = a.top();
		a.pop();
		if (!y)
			continue;
		if (k)
			printf("+");
		k = true;
		printf("2");
		if (a.size() + 1 == 2)
			continue;
		if (a.empty()) {
			printf("(0)");
			continue;
		}
		printf("(");
		solve(a.size() * y);
		printf(")");
	}
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	// freopen("E:\\code\\out.out", "w", stdout);
#endif
	int x;
	scanf("%d", &x);
	solve(x);
}
