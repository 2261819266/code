#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;

deque<int>q[5],p[5];

struct node{
	int a,b,c;
}ans[N<<1];

int a[N],n,m,k,now;

bool findans;

void dfs(int i){
//	printf("%d %d\n",i,now);
	if(findans)return;
	if(i==m+1){
		int opp=now;
		for(int j=1;j<=n;j++)p[j]=q[j];
		for(int j=1;j<=n;j++)
			for(int jj=1;jj<=n;jj++){
				if(j==jj)continue;
				while(p[j].size()&&p[jj].size()&&p[j].back()==p[jj].back()){
					ans[++now]={2,j,jj};
					p[j].pop_back();
					p[jj].pop_back();
				}
			}
		bool op=1;
		for(int j=1;j<=n;j++)
			if(q[j].size()){
				op=0;
				break;
			}
		if(op){
			findans=1;
		}
		else now=opp;
		return;
	}
	for(int j=1;j<=n;j++){
		if(q[j].front()==a[i]){
			q[j].pop_front();
			ans[++now]={0,1,j};
			dfs(i+1);
			if(findans)return;
			--now;
			q[j].push_front(a[i]);
		}
		else{
			q[j].push_front(a[i]);
			ans[++now]={0,1,j};
			dfs(i+1);
			if(findans)return;
			--now;
			q[j].pop_front();
		}
	}
}

void solve1(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d",&a[i]);
	findans=0;now=0;
	dfs(1);
	printf("%d\n",now);
	for(int i=1;i<=now;i++){
		node x=ans[i];
		if(x.a)printf("%d %d %d\n",x.a,x.b,x.c);
		else printf("%d %d\n",x.b,x.c);
	}
	for(int i=1;i<=n;i++)
		while(q[i].size())q[i].pop_front();
}

int main(){
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		solve1();
	}
	return 0;
}
