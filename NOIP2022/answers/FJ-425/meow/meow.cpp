#include<bits/stdc++.h>
using namespace std;

const int N = 30000;
typedef pair<int, int> PII;
int T;
int n, m, k, a[N];
struct opt {
	int s, l, r;
} ops[N << 2];
int op = 0;

void check(deque<int> q[], int like) {

	while(1){
		int flag = 0;
		bool flag2 = 0;
		for(int i = 1; i <= n; i ++)
			if(!q[i].empty()) flag ++;
		if(flag <= 1) break;
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++)
			if(i == j) continue;
			else if(!q[i].empty() && !q[j].empty() && q[i].back() == q[j].back()){
				q[i].pop_back();
				q[j].pop_back();
				ops[++ op] = {2, i, j};	
				flag2 = 1;
			}
		if(!flag2) break;
	}
	for(int i = 1; i <= n; i ++){
		if(!q[i].empty() && q[i].front() == like){
			q[i].pop_front();
			ops[++ op] = {1, i};
			return ;
		}
	}
	for(int i = 1; i <= n; i ++)
		if(q[i].empty()){
			ops[++ op] = {1, i};
			q[i].push_front(like);
			return ;
		}
	q[1].push_front(like);
	ops[++ op] = {1, 1};
	return ;
	
}

int main() {
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	cin >> T;
	while(T--) {
		deque<int> q[310];
//		memset(q, 0, sizeof(q));
		op = 0;
		scanf("%d%d%d", &n, &m, &k);
		for(int i = 1; i <= m; i ++) {
			scanf("%d", &a[i]);
			check(q, a[i]);
		}
		printf("%d\n", op);
		for(int i = 1; i <= op; i ++) {
			if(ops[i].s == 1) {
				printf("%d %d\n", 1, ops[i].l);
			} else {
				printf("%d %d %d\n", 2, ops[i].l, ops[i].r);
			}
		}
	}

	return 0;
}