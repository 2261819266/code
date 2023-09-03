#include <bits/stdc++.h>
#define ull unsigned long long

using namespace std;
const int N = 2.5e5 + 10;
int a[N], b[N];
int ra[N], rb[N];
int stk[N], tt;

inline int read()
{
	int x = 0, y = 1; char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') y = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * y;
}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	int t = read(), n = read();
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int i = 1; i <= n; i++) b[i] = read();
	for (int i = n; i; i--)
	{
		while (tt && a[stk[tt]] <= a[i]) tt--;
		ra[i] = !tt ? n + 1 : stk[tt];
		stk[++tt] = i;
	}
	tt = 0;
	for (int i = n; i; i--)
	{
		while (tt && b[stk[tt]] <= b[i]) tt--;
		rb[i] = !tt ? n + 1 : stk[tt];
		stk[++tt] = i;
	}
	int m = read();
	while (m--)
	{
		int l = read(), r = read();
		int nowa = 0, nowb = 0;
		ull res = 0;
		for (int k = l; k <= r; k++)
		{
			nowa = a[k], nowb = b[k];
			for (int i = k, j; i <= r; i = j + 1)
			{
				nowa = max(nowa, a[i]), nowb = max(nowb, b[i]);
				j = min(min(ra[i] - 1, rb[i] - 1), r);
				res += (ull)nowa * nowb * (j - i + 1);
			}
		}
		cout << res << endl;
	}
	return 0;
}