#include <cstdio>
#include <stack>
using std::stack;

int main() {
	int n;
	scanf("%d", &n);
	if (n % 2) {
		printf("-1");
		return 0;
	}
	stack<int> a;
	while (n > 0) {
		a.push(n % 2);
		n /= 2;
	}
	while (a.size()) {
		a.top() ? printf("%d ", a.top() << (a.size() - 1)) : 0;
		a.pop();
	}
}