#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int MAX_N = 305;
int n, m, k;
deque<int> st;
deque<int> s[MAX_N];
vector<pii> op;
bool isdone;
inline ll read() {
	ll ret = 0, w = 1; char c = getchar();
	while(!isdigit(c))	{if(c == '-')	w = -1; c = getchar();}
	while(isdigit(c))	{ret = (ret << 1) + (ret << 3) + (c ^ 48); c = getchar();}
	return ret * w;
}
char buf[100];
inline void write(ll x) {
	if(x < 0)	putchar('-'), x = -x;
	int tp = 0;
	do {buf[++tp] = x % 10 + 48; x /= 10;} while(x);
	while(tp) putchar(buf[tp--]);
}

void dfs(int p) {
	if(p > 2 * m || isdone)	return;
	if(p >= m && p <= 2 * m && st.empty()) {
		bool flag = 1;
		for(int i = 1; i <= n; i++)
			if(!s[i].empty()) {
				flag = 0;
				break;
			}
		if(flag) {
			write(op.size()), putchar('\n');
			for(pii x : op) {
				if(x.second == -1)
					printf("1 %d\n", x.first);
				else
					printf("2 %d %d\n", x.first, x.second);
			}
			isdone = 1;
			return;
		}
	}
	if(!st.empty()) {
		int tp = st.front(), tmp = -1;
		st.pop_front();
		for(int i = 1; i <= n; i++) {
			op.push_back({i, -1});
			if(!s[i].empty())	tmp = s[i].back();
			else	tmp = -1;
			if(tp != tmp)	s[i].push_back(tp);
			else	s[i].pop_back();
			dfs(p + 1);
			op.pop_back();
			if(tp != tmp)	s[i].pop_back();
			else	s[i].push_back(tmp);
		}
		st.push_front(tp);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			if(!s[i].empty() && !s[j].empty()) {
				int t1 = s[i].front(), t2 = s[j].front();
				if(t1 == t2) {
					op.push_back({i, j});
					s[i].pop_front(), s[j].pop_front();
					dfs(p + 1);
					s[i].push_front(t1), s[j].push_front(t2);
					op.pop_back();
				}
			}
		}
	}
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T = read();
	while(T--) {
		isdone = 0;
		n = read(), m = read(), k = read();
		while(!st.empty())
			st.pop_back();
		for(int i = 1; i <= n; i++)
			while(!s[i].empty())
				s[i].pop_back();
		for(int i = 1; i <= m; i++) {
			int v = read();
			st.push_back(v);
		}		
		dfs(0);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
