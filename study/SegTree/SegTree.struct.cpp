#include <iostream>
#define int long long
using namespace std;
#ifdef LOCAL
const int maxn = 1e1 + 3;
#else
const int maxn = 1e5 + 9;
#endif
int n, m, mod;
int a[maxn];
// struct TreeNode
// {
// 	int sum, mul, add;
// } tree[4 * maxn];
int sum[maxn << 2], mul[maxn << 2], add[maxn << 2];
void mulop(int p, int c)
{
	sum[p] = (sum[p] * c) % mod;
	mul[p] = (mul[p] * c) % mod;
	add[p] = (add[p] * c) % mod;
}
void addop(int p, int l, int r, int c)
{
	add[p] = (add[p] + c) % mod;
	sum[p] = (sum[p] + (r - l + 1) * c) % mod;
}
void pushdown(int p, int l, int r)
{
	int mid = (l + r) / 2;
	int lc  = p << 1;
	int rc  = p << 1 | 1;
	if (mul[p] != 1)
	{
		mulop(lc, mul[p]);
		mulop(rc, mul[p]);
		mul[p] = 1;
	}
	if (add[p] != 0)
	{
		addop(lc, l, mid, add[p]);
		addop(rc, mid + 1, r, add[p]);
		add[p] = 0;
	}
}
void pushup(int p)
{
	sum[p] = (sum[p << 1] + sum[p << 1 | 1]) % mod;
}
int query(int p, int l, int r, int x, int y)
{
	if (x > r || y < l)
		return 0;
	if (x <= l && r <= y)
		return sum[p];
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	return (query(p << 1, l, mid, x, y) + query(p << 1 | 1, mid + 1, r, x, y)) % mod;
}

void modify(int p, int l, int r, int x, int y, int op, int c)
{
	if (x > r || y < l)
		return;
//	cout << 1;
	if (x <= l && r <= y)
	{
		if (op == 1)
		{
			mulop(p, c);
		}
		else
		{
			addop(p, l, r, c);
		}
		return;
	}
	pushdown(p, l, r);
	int mid = (l + r) / 2;
	modify(p << 1, l, mid, x, y, op, c);
	modify(p << 1 | 1, mid + 1, r, x, y, op, c);
	pushup(p);
	return;
}
void build(int p, int l, int r)
{
	mul[p] = 1;
	add[p] = 0;
	if (l == r)
	{
		sum[p] = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
	pushup(p);
}
signed main()
{
#ifdef LOCAL
	LOCALfo
#endif
	cin >> n;
	cin >> m;
	cin >> mod;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
	}
	build(1, 1, n);
	while (m--)
	{
		int op, l, r, c;
		cin >> op >> l >> r;
		if (op == 1 || op == 2)
		{
			cin >> c;
			modify(1, 1, n, l, r, op, c);
		}
		else
		{
			cout << query(1, 1, n, l, r) << endl;
		}
	}
	return 0;
}