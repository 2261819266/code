#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
const int N=1e3+10;
int n,m,k;
int vis[N],val[N*2];
void work(){
	queue<int> q;
	int a;
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=(n-1)*2;i++) q.push(i);
	for (int i=1;i<=m;i++) {
		scanf("%d",&a);
		if (!vis[a]) {
			vis[a]=q.front(),val[q.front()]=a;
			q.pop();
			printf("1 %d\n",(vis[a]+1)/2);
			continue;
		}
		if (vis[a]&1) {
			printf("1 %d\n",n);
			printf("2 %d %d\n",(vis[a]+1)/2,n);
			vis[val[vis[a]+1]]=vis[a];		
			val[vis[a]]=val[vis[a+1]];
			q.push(vis[a]+1);
			vis[a]=0;
		}
		else {
			printf("1 %d\n",(vis[a]+1)/2);
			q.push(vis[a]);
		}
	}
}
int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	while (T--) work();
	return 0;
}
