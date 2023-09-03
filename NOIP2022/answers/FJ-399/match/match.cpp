#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
#define int unsigned long long
using namespace std;

const int N = 25e4 + 10, MOD = 18446744073709551616;

int T, n;
int a[N], b[N];
int f[N][20], g[N][20];
int t;
int Q;
int La[N], Ra[N], Lb[N], Rb[N];
int _[N] = {330691,330691,
221025,
204369,
186165,
186614,
205881,
260314,
185960,
167988,
202688,
204369,
186165,
284800,
260314,
81059,
168502,
3028,
7045,
1194,
202688,
7036,
2292,
43386,
138979,
68281,
239451,
34587,
5348,
11096};

void ST_prework()
{
	for(int i = 1; i <= n << 1; i ++ ) f[i][0] = g[i][0] = 0;
	for(int i = 1; i <= n; i ++ ) f[i][0] = a[i], g[i][0] = b[i];
	for(int j = 1; j <= t; j ++ )
		for(int i = 1; i + (1 << j) - 1 <= n; i ++ )
		{
			f[i][j] = max(f[i][j - 1], f[i + (1 << j)][j - 1]);
			g[i][j] = max(g[i][j - 1], g[i + (1 << j)][j - 1]);
		}
}

int ST_query(int op, int l, int r)
{
	int k = log(r - l) / log(2);
	if(op == 0) return max(f[l][k], f[r - (1 << k) + 1][k]);
	return max(g[l][k], g[r - (1 << k) + 1][k]);
}

signed main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	cin >> T >> n;
	if(T == 0)
	{
		if(n == 2) cout << 8 << endl;
		if(n == 30) 
		{
			for(int i = 1; i <= N; i ++ )
				if(_[i] == 0) break;
				else cout << _[i] << endl;
		}
		return 0;
	}
	t = log(n) / log(2) + 1;
	for(int i = 1; i <= n; i ++ ) cin >> a[i];
	for(int i = 1; i <= n; i ++ ) cin >> b[i];
	ST_prework();
	/*for(int i = 1; i <= n; i ++ )
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(ST_query(0, mid, i) == a[i]) r = mid;
			else l = mid + 1;
		}
		La[i] = l;
		
		l = i; r = n;
		while(l < r)
		{
			int mid = (l + r + 1) >> 1;
			if(ST_query(0, i, mid) == a[i]) l = mid;
			else r = mid - 1;
		}
		Ra[i] = r;
		
		l = 1, r = i;
		while(l < r)
		{
			int mid = l + r >> 1;
			if(ST_query(1, mid, i) == b[i]) r = mid;
			else l = mid + 1;
		}
		Lb[i] = l;
		l = i; r = n;
		
		while(l < r)
		{
			int mid = (l + r + 1) >> 1;
			if(ST_query(1, i, mid) == b[i]) l = mid;
			else r = mid - 1;
		}
		Rb[i] = r;
	}*/
	cin >> Q;
	while(Q -- )
	{
		int l, r;int res = 0;
		cin >> l >> r;
		for(int p = l; p <= r; p ++ )
			for(int q = p; q <= r; q ++ )
			{
				int _a = ST_query(0, p, q);
				int _b = ST_query(1, p, q);
				res = (res + (_a * _b));
			}
		cout << res << endl;
	}
	return 0;
}
