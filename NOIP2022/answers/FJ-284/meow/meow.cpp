#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define U(i,b,e) for(int i(b),END##i(e);i<=END##i;++i)
#define D(i,e,b) for(int i(e),END##i(b);i>=END##i;--i)

const int M = 2000006;
int n, m, k, a[M];
deque<int> s[305];
struct Op { int t, x, y; };
vector<Op> op;
mt19937 RNG(19260817);

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	
	int T; scanf("%d", &T);
	while (T--) {
		op.clear();
		scanf("%d%d%d", &n, &m, &k);
		U (g, 1, m) { int x; scanf("%d", &x);
			bool flag = 0;
			U (i, 1, n) if (s[i].size() && s[i].back() == x) {
				flag = 1;
				s[i].pop_back();
				op.push_back({1, i, -1});
				break;
			}
			if (flag) continue;
			flag = 0;
			U (i, 1, n) if (s[i].empty()) {
				s[i].push_back(x);
				op.push_back({1, i, -1});
				U (j, 1, n) if (i != j && s[j].front() == x) {
//					clog << g << ' ' << x << "$" << s[i].front() << ' ' << s[j].front() << endl;
					s[j].pop_front();
					s[i].pop_front();
					op.push_back({2, i, j});
					break;
				}
				flag = 1;
				break;
			}
			if (flag) continue;
			int pos = RNG() % n + 1;
			s[pos].push_back(x);
			op.push_back({1, pos, -1});
		}
		printf("%llu\n", op.size());
		for (auto &o : op)
			if (o.t == 1)
				printf("1 %d\n", o.x);
			else
				printf("2 %d %d\n", o.x, o.y);
	}
	return 0;
}