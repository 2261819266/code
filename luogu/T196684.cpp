#include <algorithm>
#include <cstdio>
#include <cstring>

char name;

const int maxn = 60005;
const int inf = 0x7fffffff;
struct expression {
	int number;
	int oper;
	//	\
	-2 => >= \
	-1 => >  \
	1  => <  \
	2  => <=
} a[maxn], begin = {-inf, 4}, end = {inf, 2};
char oper[5][3] = {">=", ">", "\0", "<", "<="};

int main(int argc, const char *argv[]) {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	scanf("%d %c", &n, &name);
	for (int c = 1; c <= n; c++) {
		char s[20];
		scanf("%s", s);
		int x = 0, d = 2;
		bool k = false;
		a[c].oper = (s[1] == '<') ? 1 : -1;
		if (s[2] == '=')
			(a[c].oper += a[c].oper > 0 ? 1 : -1), d++;
		for (; d < (int)strlen(s); d++) {
			if (s[d] == '-')
				k = true, d++;
			x = x * 10 + s[d] - 48;
		}
		k ? x = -x : 0;
		a[c].number = x;
	}
	for (int c = 1; c <= n; c++) {
		if (a[c].oper > 0) {
			if (a[c].number == end.number)
				end.oper = std::min(a[c].oper, end.oper);
			if (a[c].number < end.number)
				end = a[c];
		} else {
			if (a[c].number == begin.number)
				begin.oper = std::max(a[c].oper, begin.oper);
			if (a[c].number > begin.number)
				begin = a[c];
		}
	}
	if (end.number == inf) {
		printf("%c%s%d", name, oper[begin.oper + 2], begin.number);
		return 0;
	}
	if (begin.number == -inf) {
		printf("%c%s%d", name, oper[end.oper + 2], end.number);
		return 0;
	}
	if (begin.number == end.number && begin.oper == -2 && end.oper == 2) {
		printf("%c=%d", name, begin.number);
		return 0;
	}
	if (begin.number >= end.number) {
		printf("No Answer!");
		return 0;
	}
	printf("%d%s%c%s%d", begin.number, oper[abs(begin.oper) + 2], name, oper[end.oper + 2],
		   end.number);
}
