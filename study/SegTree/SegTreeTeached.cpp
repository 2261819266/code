#include <cstdio>
#include <algorithm>
#define ll long long

const int maxn = 1e5 + 8;

ll a[maxn << 2], b[maxn << 2];
#define ls (k << 1)
#define rs (ls | 1)
#define Def int mid = (l + r) / 2;
#define Ls ls, l, mid
#define Rs rs, mid + 1, r
#define num (r - l + 1)
#define lm (mid - l + 1)
#define rm (num - lm)
#define updata a[k] = a[ls] + a[rs];
#define pushd pushdown(k, l, r);

/**
 * @brief build a tree
 * 
 * @param k current node's subscript
 * @param l left value of current node's interval
 * @param r right value of current node's interval
 * @param data an array that requires a tree
 * @param n data scale
 * @return the value of the root of the tree after build
 */
ll buildTree(int k, int l, int r, ll data[], int n) {
	if (l == r) return a[k] = data[l];
	Def
	buildTree(Ls, data, n);
	buildTree(Rs, data, n);
	return updata
}

/**
 * @brief modify data[i](actual) to x
 * 
 * @param i the address of the data
 * @param x value to be change
 * @return the value of the root of the tree after modify
 */
ll modify(int k, int l, int r, int i, ll x) {
	if (l == r) return a[k] = x;
	Def
	i <= mid ? modify(Ls, i, x) : modify(Rs, i, x);
	return updata
}

/**
 * @brief pass the lazy
 */
void pushdown(int k, int l, int r) {
	Def
	a[ls] += b[k] * lm;
	a[rs] += b[k] * rm;
	b[ls] += b[k];
	b[rs] += b[k];
	b[k] = 0;
}

/**
 * @brief query the sum of interval
 * 
 * @param L the left value of interval to query
 * @param R the right value of interval to query
 * @return the answer of the query
 */
ll query(int k, int l, int r, int L, int R) {
	if (l >= L && r <= R) return a[k];
	if (l > R || L > r) return 0;
	Def pushd
	return query(Ls, L, R) + query(Rs, L, R);
}

/**
 * @brief add x to every number in the interval
 * 
 * @param L the left value of interval to add
 * @param R the right value of interval to add
 * @param x the value to add 
 * @return he value of the root of the tree after modify
 */
ll add(int k, int l, int r, int L, int R, ll x) {
	if (l >= L && r <= R) return a[k] += x * num, b[k] += x;
	if (l > R || L > r) return 0;
	Def pushd
	add(Ls, L, R, x), add(Rs, L, R, x);
	return updata
}

int main(int argc, char const *argv[]) {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		modify(1, 1, n, i, x);
	}
}

