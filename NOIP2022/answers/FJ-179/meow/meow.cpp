#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,k;
deque<int>original;

typedef struct method {
	int op;
	int a;
	int b;
}method;

typedef struct Stat {
	deque<int>heap;
	deque<int>sta[302];
	int step = 0;
	int remain;
	deque<method>path;
}Stat;

char isFinished = 0;

void dfs(Stat st) {
	if(isFinished == 1) {
		return;
	}
	
	////Debug
	/*
	printf("----------------\nremain:%d step:%d\n",st.remain,st.step);
	for(int i = 1;i <= n;++i) {
		deque<int>t = st.sta[i];
		printf("Stack %d:",i);
		while(t.size()) {
			printf("%d ",t.front());
			t.pop_front();
		}
		puts("");
	}
	puts("-----------------");
	*/
	
	if(st.remain <= 0) {
		//printf("RES:\nTOTAL STEP:%d\n",st.step);
		printf("%d\n",st.step);
		while(st.path.size() != 0) {
			if(st.path.front().op == 1) {
				printf("%d %d\n",st.path.front().op,st.path.front().a);
			}
			else {
				printf("%d %d %d\n",st.path.front().op,st.path.front().a,st.path.front().b);
			}
			st.path.pop_front();
		}
		isFinished = 1;
		return;
	}
	for(int i = 1;i <= n;++i) {
		for(int j = i + 1;j <= n;++j) {
			if(st.sta[i].size() && st.sta[j].size()) {
				if(st.sta[i].front() == st.sta[j].front()) {
					Stat status;
					status.heap = st.heap;
					for(int k = 1;k <= n + 1;++k) {
						status.sta[k] = st.sta[k];
					}
					status.path = st.path;
					//Copy------------------------
					status.sta[i].pop_front();
					status.sta[j].pop_front();
					method m;
					m.op = 2;
					m.a = i;
					m.b = j;
					status.path.push_back(m);
					status.remain = st.remain - 2;
					status.step   = st.step + 1;
					dfs(status);
				}
			}
		}
		if(st.heap.size()) {
			if(st.sta[i].size() > 0 && st.sta[i].back() == st.heap.front()) {
				Stat status;
				status.heap = st.heap;
				for(int k = 1;k <= n + 1;++k) {
					status.sta[k] = st.sta[k];
				}
				status.path = st.path;
				//Copy------------------------
				status.sta[i].pop_back();
				status.heap.pop_front();
				method m;
				m.op = 1;
				m.a = i;
				status.path.push_back(m);
				status.remain = st.remain - 2;
				status.step   = st.step + 1;
				dfs(status);
			}
			else {
				Stat status;
				status.heap = st.heap;
				for(int k = 1;k <= n + 1;++k) {
					status.sta[k] = st.sta[k];
				}
				status.path = st.path;
				//Copy------------------------
				status.sta[i].push_back(st.heap.front());
				status.heap.pop_front();
				method m;
				m.op = 1;
				m.a = i;
				status.path.push_back(m);
				status.step   = st.step + 1;
				status.remain = st.remain;
				dfs(status);
			}
		}
	}
}

int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int t = 0,a = 0;
	scanf("%d",&t);
	while(t--) {
		isFinished = 0;
		scanf("%d %d %d",&n,&m,&k);
		for(int i = 1;i <= m;++i) {
			scanf("%d",&a);
			original.push_back(a);
		}
		Stat st;
		st.heap = original;
		st.remain = m;
		dfs(st);
	}
	return 0;
}
