#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<deque>
#include<queue>

using namespace std;

const int N = 2e6 + 10;

int t;
int n, m, k;
int a[N], sol[N][4];
bool flag = false;

deque<int> q1, q2, q3;

void dfs(int now, int op) {
	if (flag) return;
	
	if (now == m + 1) {
		if (q1.empty() && q2.empty() && q3.empty()) {
			flag = true;
			for (int i = 1; i < op; i++) {
				if (sol[i][1] == 1) cout << 1 << " " << sol[i][2] << endl;
				else cout << 2 << " " << sol[i][2] << " " << sol[i][3] << endl;
			}
		}
		return;
	}
	
	if (!q1.empty() && !q2.empty() && q1.front() == q2.front()) {
		int front1 = q1.front(), front2 = q2.front();
		q1.pop_front();
		q2.pop_front();
		sol[op][1] = 2, sol[op][2] = 1, sol[op][3] = 2;
		dfs(now, op + 1);
		q1.push_front(front1), q2.push_front(front2);
	}
	if (!q2.empty() && !q3.empty() && q2.front() == q3.front()) {
		int front2 = q2.front(), front3 = q3.front();
		q2.pop_front();
		q3.pop_front();
		sol[op][1] = 2, sol[op][2] = 2, sol[op][3] = 3;
		dfs(now, op + 1);
		q2.push_front(front2), q3.push_front(front3);
	}
	if (!q1.empty() && !q3.empty() && q1.front() == q3.front()) {
		int front1 = q1.front(), front3 = q3.front();
		q1.pop_front();
		q3.pop_front();
		sol[op][1] = 2, sol[op][2] = 1, sol[op][3] = 3;
		dfs(now, op + 1);
		q1.push_front(front1), q3.push_front(front3);
	}
	
	sol[op][1] = 1;
	int q = a[now];
	
	sol[op][2] = 1;
	if (!q1.empty() && q == q1.back()) {
		q1.pop_back();
		dfs(now + 1, op + 1);
		q1.push_back(q);
	} else {
		q1.push_back(q);
		dfs(now + 1, op + 1);
		q1.pop_back();
	}
	
	sol[op][2] = 2;
	if (!q2.empty() && q == q2.back()) {
		q2.pop_back();
		dfs(now + 1, op + 1);
		q2.push_back(q);
	} else {
		q2.push_back(q);
		dfs(now + 1, op + 1);
		q2.pop_back();
	}
	
	sol[op][2] = 3;
	if (!q3.empty() && q == q3.back()) {
		q3.pop_back();
		dfs(now + 1, op + 1);
		q3.push_back(q);
	} else {
		q3.push_back(q);
		dfs(now + 1, op + 1);
		q3.pop_back();
	}
}

int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= m; i++) scanf("%d", &a[i]);
		
		flag = false;
		dfs(1, 1);
	}
	return 0;
}
