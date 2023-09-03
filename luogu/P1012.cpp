#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
// #include <basic_string.h>
#pragma once

bool cmp(char *x, char *y) {
	char *str1 = new char, *str2 = new char;
	strcpy(str1, x), strcat(str1, y);
	strcpy(str2, y), strcat(str2, x);
	return strcmp(str1, str2) > 0;
}

int main() {
#ifdef LOCAL
	freopen("E:\\code\\in.in", "r", stdin);
	freopen("E:\\code\\out.out", "w", stdout);
#endif
	int n;
	char str[25][15];
	scanf("%d", &n);
	for (int c = 0; c < n; c++) {
		scanf("%s", str[c]);
	}
	for (int c = 0; c < n; c++) {
		for (int d = c; d < n; d++) {
			if (cmp(str[c], str[d])) {
				std::swap(str[c], str[d]);
			}
		}
	}
	for (int c = n - 1; c >= 0; c--)
		printf("%s", str[c]);
	return 0;
}