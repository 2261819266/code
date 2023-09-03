//Checkmate, I couldn't lose.
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cctype>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
#define ll long long
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define pii pair<int,int>
#define mp make_pair

inline void read(int &x) {
	x = 0;int f = 1;char c = getchar();
	while (!isdigit(c)) {if (c == '-') {f = -1;}c = getchar();}
	while (isdigit(c)) {x = x * 10 + c - 48;c = getchar();}
	x *= f;
}

const int N = 2e6 + 10;
int n,m,k,a[N];
vector <pair<int,pii > > ans;

void push(int typ,int x,int y = 0) {
	if (typ == 1) ans.push_back(mp(1,mp(x,0)));
	else ans.push_back(mp(2,mp(x,y)));
}

namespace solver1 {
	int top[N],dn[N];
	void solve() {
		for (int i = 1;i <= m;++i) {
			int val = ((a[i] + 1) / 2);
			if (top[val] == a[i]) {
				push(1,val);
				if (dn[val] == top[val]) top[val] = dn[val] = 0;
				else top[val] = dn[val];
			}else if (dn[val] == a[i]) {
				push(1,n);
				push(2,val,n);
			}else if (!top[val]) {
				top[val] = dn[val] = a[i];
				push(1,val);
			} else {
				top[val] = a[i];
				push(1,val);
			}
		}
	}
}

namespace solver2 {
	void solve() {
		for (int i = 1;i <= m;++i) {
			push(1,rand() % n + 1);
		}
		for (int i = 1;i <= m;++i) {
			push(2,rand()% n + 1,rand() % n + 1);
		}
	}
}

void solve() {
	scanf("%d %d %d\n",&n,&m,&k);
	ans.clear();
	for (int i = 1;i <= m;++i) scanf("%d ",a + i);
	if (k == 2 * n - 2) solver1::solve();
	else solver2::solve();
	printf("%d\n",(int)ans.size());
	for (auto e : ans) {
		if (e.first == 1) {
			printf("%d %d\n",e.first,e.second.first);
		} else{
			printf("%d %d %d\n",e.first,e.second.first,e.second.second);
		}
	}
}

signed main() {
	srand(1145141919);
	FO(meow)
	int T;scanf("%d\n",&T);
	while (T--) solve();
	return 0;
}
