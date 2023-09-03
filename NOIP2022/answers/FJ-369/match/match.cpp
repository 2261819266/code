#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

struct SegmentTree
{
	struct Node
	{
		int l, r;
		ull maxa;
	};
	
	Node tree[500010];
	ull a[500010];
	ull ans;
	
	void build(int idx, int l, int r)
	{
//		printf("build(%d, %d, %d)\n", idx, l, r);
		if (l == r)
		{
			tree[idx].maxa = a[l];
			tree[idx].l = l;
			tree[idx].r = r;
		}
		else
		{
			tree[idx].l = l;
			tree[idx].r = r;
			int mid = (l + r) / 2;
			build(idx * 2, l, mid);
			build(idx * 2 + 1, mid + 1, r);
			tree[idx].maxa = max(tree[idx * 2].maxa, tree[idx * 2 + 1].maxa);
		}
	}
	
	void search(int idx, int l, int r)
	{
//		printf("search(%d, %d, %d)\n", idx, l, r);
		if (tree[idx].l >= l && tree[idx].r <= r)
			ans = max(ans, tree[idx].maxa);
		else
		{
			int mid = (tree[idx].l + tree[idx].r) / 2;
			if (l <= mid)
				search(idx * 2, l, min(mid, r)); 
			if (mid < r)
				search(idx * 2 + 1, max(mid + 1, l), r);
		}
	}
};

SegmentTree streeN, streeO;
int T, n, Q;

int main()
{
	freopen("match.in", "r", stdin);
	freopen("match.out", "w", stdout);
	scanf("%d %d", &T, &n);
	for (register int i = 1; i <= n; i++)
		scanf("%lld", &streeN.a[i]);
	for (register int i = 1; i <= n; i++)
		scanf("%lld", &streeO.a[i]);
	streeN.build(1, 1, n);
	streeO.build(1, 1, n);
	scanf("%d", &Q);
	int l, r;
	ull sum;
	for (register int i = 1; i <= Q; i++)
	{
		scanf("%d %d", &l, &r);
		sum = 0;
		for (register int p = l; p <= r; p++)
			for (register int q = p; q <= r; q++)
			{
				streeN.ans = 0;
				streeO.ans = 0;
				streeN.search(1, p, q);
				streeO.search(1, p, q);
				sum += streeN.ans * streeO.ans;
			} 
		printf("%lld\n", sum);
	}
	return 0;
}
