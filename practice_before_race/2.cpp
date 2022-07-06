#include<bits/stdc++.h>

char name;

const int maxn = 60005;
struct expression {
	int number;
	int oper;
//	1 => <   \
	2 => <=  \
	3 => >   \
	4 => >=
} a[maxn], begin, end;

int main() {
	int n;
	scanf("%d", &n);
	for (int c = 1; c <= n; c++) {
		char s[20];
		scanf("%s", s);
		name = *s;
		int x = 0, d = 2;
		bool k = false;
		a[c].oper = (s[1] == '<') ? 1 : 3;
		if (s[2] == '=')
			a[c].oper++, d++;
		for ( ; d <= (int)strlen(s); d++) {
			if(s[c])
			
		}
	}
}
