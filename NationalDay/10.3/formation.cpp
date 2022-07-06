#include <cstdio>
#include <cstdlib>
#include <ctime>

int main() {
	freopen("formation.in", "r", stdin);
	freopen("formation.out", "w", stdout);
	srand((unsigned int)time(NULL));
	printf("%d", rand() % 10);
}