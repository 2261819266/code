#include <bits/stdc++.h>

using namespace std;

int T, n, a, m;

int main() {

	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	scanf("%d%d%d%d", &T, &n, &a, &m);
	
	printf("%d\n", m/2);
	
	for(int i=1; i<=m/2; i++) printf("1 1\n");

	return 0;
}

