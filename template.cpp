#include <cstdio>
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(0));
	int n;
	scanf("%d", &n);
	while (n--) {
		printf("%d\n", rand());
	}
}