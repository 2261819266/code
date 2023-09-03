#include<bits/stdc++.h>
using namespace std;

const int N=1e3+3;
list<int>q[N];
int n,m,a[N],cnt;

struct node{
	int opt,x,y;
}qwq[N];

void dfs(int x){
	if(x==m+1){
		bool flag=1;
		for(int i=1;i<=n;i++) if(!q[i].empty()){flag=0; break;}
		if(flag){
			printf("%d\n",cnt);
			for(int i=1;i<=cnt;i++){
				printf("%d %d",qwq[i].opt,qwq[i].x);
				if(qwq[i].opt==2) printf(" %d\n",qwq[i].y);
				else puts("");
			}
			exit(0);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		qwq[++cnt].opt=1; qwq[cnt].x=i;
		if(q[i].empty()){q[i].push_front(a[x]);
			bool f=1;
			for(int j=1;j<=n;j++)
				if(i!=j&&q[j].size()&&q[j].back()==a[x]){
					qwq[++cnt].opt=2; qwq[cnt].x=i; qwq[cnt].y=j;
					if(qwq[cnt].x>qwq[cnt].y) swap(qwq[cnt].x,qwq[cnt].y);
					q[i].pop_back(); q[j].pop_back();
					break;
				}
		}
		else{
			if(q[i].front()==a[x]) q[i].pop_front();
			else q[i].push_front(a[x]);
		}
		dfs(x+1); cnt--;
	}
}

void real_main(){
	int k; scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++) scanf("%d",&a[i]);
	dfs(1);
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--) real_main();
}
