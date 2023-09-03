#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5, K = 605;

deque <int> q[K];
int st[K];
int a[N];
struct xx{
	int op, s1, s2;
}ans[N * 2];

int main(){
	freopen("meow.in", "r", stdin);
	freopen("meow.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t ++){
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		
		for(int i = 1; i <= m; i ++){
			scanf("%d", &a[i]);
		}
		
		if(T % 10 == 1){
			int cnt = 0;
			for(int i = 1; i <= m; i ++){
				int x = a[i];
				int u = (a[i] - 1) / 2 + 1;
				if(q[u].size() && q[u].front() == x){
					cnt ++;
					ans[cnt].op = 1, ans[cnt].s1 = n;
					cnt ++;
					ans[cnt].op = 2, ans[cnt].s1 = u, ans[cnt].s2 = n;
					q[u].pop_front();
				}
				else{
					cnt ++;
					ans[cnt].op = 1, ans[cnt].s1 = u;
					if(q[u].size() && q[u].back() == x)q[u].pop_back();
					else q[u].push_back(x);
				}
			}
			
			printf("%d\n", cnt);
			for(int i = 1; i <= cnt; i ++){
				if(ans[i].op == 1)printf("1 %d\n", ans[i].s1);
				else printf("2 %d %d\n", ans[i].s1, ans[i].s2);
			}
		}
		else {
			int cnt = 0;
			for(int i = 1; i <= m; i ++){
				int x = a[i];
				bool s = 1;
				for(int j = 1; j < n; j ++){
					if(q[j].size() && q[j].front() == x){
						cnt ++;
						ans[cnt].op = 1, ans[cnt].s1 = n;
						cnt ++;
						ans[cnt].op = 2, ans[cnt].s1 = j, ans[cnt].s2 = n;
						q[j].pop_front();
						s = 0;
						break;
					}
					else if(q[j].size() && q[j].back() == x){
						cnt ++;
						ans[cnt].op = 1, ans[cnt].s1 = j;
						q[j].pop_back();
						s = 0;
						break;
					}
				}
				if(s){
					for(int j = 1; j < n; j ++){
						if(q[j].size() < 2){
							cnt ++;
							ans[cnt].op = 1, ans[cnt].s1 = j;
							q[j].push_back(x);
							break;
						}
					}
				}
			}
			printf("%d\n", cnt);
			for(int i = 1; i <= cnt; i ++){
				if(ans[i].op == 1)printf("1 %d\n", ans[i].s1);
				else printf("2 %d %d\n", ans[i].s1, ans[i].s2);
			}
		}
	}
	
	return 0;
}
