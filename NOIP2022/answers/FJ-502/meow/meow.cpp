#include <bits/stdc++.h>
using namespace std;

//Remember freopen!!!!!!!!!!!
//for zjy.

const int MAXN = 607;
const int MAXM = 2e6 + 7;

int t;
int n, k, m, op;
int a[MAXM];
int abo[MAXN], st[MAXN], bk[MAXN];
queue<int> q, q2;

struct node
{
	int a, s1, s2;
} wk[2 * MAXM];

void addwork(int a, int s1, int s2)
{
	wk[++ op].a = a;
	wk[op].s1 = s1;
	wk[op].s2 = s2;
}

void output()
{
	printf("%d\n", op);
	for (int i = 1; i <= op; i ++)
	{
		if (wk[i].a == 1)
			printf("1 %d\n", wk[i].s1);
		else
			printf("2 %d %d\n", wk[i].s1, wk[i].s2);
	}
}


void solve1()
{
	while (t --)
	{
		cin >> n >> m >> k;
		memset(abo, 0, sizeof(abo));
		memset(st, 0, sizeof(st));
		memset(bk, 0, sizeof(bk));
		op = 0;

		while (!q.empty())
			q.pop();
		while (!q2.empty())
			q2.pop();

		for (int i = 1; i <= n - 1; i ++)
			q.push(i);

		int x;
		for (int i = 1; i <= m; i ++)
		{
			cin >> x;
			a[i] = x;
			if (!st[x])
			{
				if (q.empty())
				{
					st[x] = q2.front();
					abo[bk[st[x]]] = x;
					q2.pop();
					addwork(1, st[x], 0);
				}
				else
				{
					st[x] = q.front();
					bk[st[x]] = x;
					q2.push(q.front());
					q.pop();
					addwork(1, st[x], 0);
				}
			}
			else if (!abo[x])
			{
				addwork(1, st[x], 0);
				if (bk[st[x]] == x)
				{
					bk[st[x]] = 0;
					q.push(st[x]);
				}
				else
				{
					abo[bk[st[x]]] = 0;
					q2.push(st[x]);
				}
				st[x] = abo[x] = 0;
			}
			else
			{
				addwork(1, n, 0);
				addwork(2, st[x], n);
				q2.push(st[x]);
				bk[st[x]] = abo[x];
				st[x] = abo[x] = 0;
			}
		}
		
		output();
	}
}

int main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);

	cin >> t;

	solve1();

	return 0;
}

/*
1
2 4 2
1 2 1 2


*/