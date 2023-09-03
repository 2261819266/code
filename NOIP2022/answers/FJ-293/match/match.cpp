#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define MAXN (250010)
int id, n, q;
int log_2[MAXN];
ull f[2][MAXN][18];

#define ask_ log_2[r - l + 1]
inline ull ask(int op, int l, int r)
	{return max(f[op][l][ask_],
				f[op][r - (1 << ask_) + 1][ask_]);}
// ASK is similar to AKs, isn't it?

void init(int op)
{
	for (int i = 1; i <= n; i++)
		scanf("%llu", &f[op][i][0]);
	for (int i = 1, len; i <= log_2[n]; i++)
	{
		len = (1 << i);
		for (int j = 1; j + len - 1 <= n; j++)
			f[op][j][i] = max(f[op][j][i - 1], f[op][j + len / 2][i - 1]);
	}
}

// Stupid segment_tree.

//struct node{ull s;}t[MAXN << 2];
//
//#define left (u << 1)
//#define right (u << 1 | 1)
//void build(int u, int ul, int ur)
//{
//	t[u].s = ask(0, ul, ur) * ask(1, ul, ur);
//	if (ul == ur) {return;}
//	int mid = (ul + ur) >> 1;
//	build(left, ul, mid), build(right, mid + 1, ur);
//	t[u].s += t[left].s + t[right].s;
//}
//
//ull ask2(int u, int l, int r, int ul, int ur)
//{
//	if (l <= ul && ur <= r) return t[u].s;
//	int mid = (ul + ur) >> 1;
//	ull res = 0;
//	if (l <= mid) res += ask2(left, l, r, ul, mid);
//	if (r > mid) res += ask2(right, l, r, mid + 1, ur);
//	return res;
//}

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	
	scanf("%d%d", &id, &n);
	log_2[1] = 0;
	for (int i = 2, i1 = 0, i2 = 2; i <= n; i++)
	{
		if (i >= i2) i2 <<= 1, i1++;
		log_2[i] = i1;
	}
	
	init(0), init(1);
	
//	build(1, 1, n);
	
	scanf("%d", &q);
	int l, r; ull ans;
	while (q--)
	{
		scanf("%d%d", &l, &r);
//		printf("%llu\n", ask2(1, l, r, 1, n));
		ans = 0;
		for (int i = l; i <= r; i++)
		{
			for (int j = i; j <= r; j++)
				ans += ask(0, i, j) * ask(1, i, j);
		}
		printf("%llu\n", ans);
	}
	
	return 0;
}

/*
0 2
2 1
1 2
1
1 2

8

10:30
11:00
11:30
12:00
12:30
13:00
*/
