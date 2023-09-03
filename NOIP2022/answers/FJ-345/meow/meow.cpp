#include <bits/stdc++.h>
using namespace std;
int n, m, k, t;
int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out","w",stdout);
	scanf("%d", &t);
	while (t -- ) {
		cin >> n >> m >> k;
		cout << m << endl;
		while (m -- ) cin >> k, cout << "1 " << (k % n ? k % n : n) << endl;
		puts("");
	}
	return 0;
}
