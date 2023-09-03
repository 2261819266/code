#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 15, M = 2e6 + 15;
int T, n, m, k;
int a[M];

struct Stak{
	deque<int> Q;
}stak[N];

struct Step{
	int opt, x, y;
}step[M];

int check(){
	int ans = 0;
	for(int i = 1; i <= n; i ++) if(stak[i].Q.empty()) ans ++;
	return ans;
}

int mark[M], ok, anstot;
void dfs(int pos, int tot){
	if(ok) return ;
	for(int i = 1; i <= n; i ++){
		int pp = 0;
		int sta[N];
		memset(sta, 0, sizeof(sta));
		while(!stak[i].Q.empty()){
			sta[++ pp] = stak[i].Q.front();
			stak[i].Q.pop_front();
		}
		for(int s = 1; s <= pp; s ++) stak[i].Q.push_front(sta[s]);
		int u = stak[i].Q.front();
		if(a[pos] == u) stak[i].Q.pop_front();
		else stak[i].Q.push_front(a[pos]);
		int num = tot;
		step[++ num].opt = 1, step[num].x = i;
		for(int s = 1; s <= n; s ++) 
			for(int t = s + 1; t <= n; t ++){
				if(stak[s].Q.empty() || stak[t].Q.empty()) continue;
				int x = stak[s].Q.back(), y = stak[t].Q.back();
				if(x == y){
					stak[s].Q.pop_back(), stak[t].Q.pop_back();
					step[++ num].opt = 2, step[num].x = s, step[num].y = t;
				} 
			}
		if(pos == m){
			if(check() == n) ok = true, anstot = num;
			return ;
		}
		dfs(pos + 1, num);
		while(!stak[i].Q.empty()) stak[i].Q.pop_front();
		for(int s = 1; s <= pp; s ++) stak[i].Q.push_front(sta[s]);
	}
}

void print(){
	for(int i = 1; i <= anstot; i ++){
		if(step[i].opt == 1) printf("%d %d\n", 1, step[i].x);
		else printf("%d %d %d\n", 2, step[i].x, step[i].y);
	}
}

int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	scanf("%d", &T);
	while(T --){
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1; i <= m; i ++) scanf("%d", &a[i]);
		memset(step, 0, sizeof(step));
		ok = false;
		dfs(1, 0);
		printf("%d\n", anstot);
		print();
	}
	return 0;
}
