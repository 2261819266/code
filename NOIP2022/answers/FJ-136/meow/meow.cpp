#include <cstdio>
#include <list>
#include <queue>
using namespace std;
constexpr int N = 305, M = 2e6 + 5;
int n, m, k;
int a[M];
struct node
{
	int opt, x, y;
	node(int _opt = 0, int _x = 0, int _y = 0) : opt(_opt), x(_x), y(_y) {}
} p[M * 2];
int tot;
namespace subtask1
{
	int b[M], c[M][3];
	inline void main()
	{
		queue <int> q;
		for (int i = 1; i <= n - 1; ++i)
			q.push(i);
		for (int i = 1; i <= m; ++i)
		{
			if (b[a[i]])
			{
				int where = b[a[i]];
				if (c[where][c[where][0]] == a[i])
				{
					p[++tot] = node(1, where);
					--c[where][0];
					if (c[where][0] == 1)
						q.push(where);
				}
				else
				{
					p[++tot] = node(1, n);
					p[++tot] = node(2, where, n);
					c[where][c[where][0] = 1] = c[where][2];
					q.push(where);
				}
				continue;
			}
			int u = q.front();
			q.pop();
			c[u][++c[u][0]] = a[i];
			b[a[i]] = u;
			p[++tot] = node(1, u);
			if (c[u][0] < 2)
				q.push(u);
		}
	}
}
namespace subtask2
{
	bool mp[N];
	int b[N], c[N];
	list<int> que;
	inline void main()
	{
		for (int i = 1; i <= m; ++i)
		{
			int u = a[i];
			if (!que.empty() && u == que.back()){
				p[++tot] = node(1, 1);
				que.pop_back();
			}
			else
				if (!que.empty() && u == que.front())
				{
					p[++tot] = node(1, 2);
					p[++tot] = node(2, 1, 2);
					que.pop_front();
				}
			else
				que.push_back(u);
		}
	}
}
inline void work()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
		scanf("%d", &a[i]);
	if (k == 2 * n - 2)
		subtask1::main();
	else
		subtask2::main();
	printf("%d\n", tot);
	for (int i = 1; i <= tot; ++i)
	{
		printf("%d %d", p[i].opt, p[i].x);
		if (p[i].opt == 2)
			printf(" %d", p[i].y);
		putchar('\n');
	}
	tot = 0;
}
signed main()
{
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T = 1;
	scanf("%d", &T);
	while (T--)
		work();
	return 0;
}
