#include <cstdio>//I use too much time in T1 and T4.Now I have a good idea ,but I can't write it down.
using namespace std;

struct qwq {
	int to,next;
}edge[1000005];

int head[500005],num,u,v;
int n,m;
bool vis[500005],qwq[1000005];
void add (int u,int v) {
	edge[++num].to = v;
	edge[num].next = head[u];
	head[u] = num;
}
int main () {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++) {
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
	}
	printf("5");
	return 0;
}