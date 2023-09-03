#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int a,b;
}e[1000005];
long long n,m;
int a,b;long long answers;
bool flag,check;
vector <int>ed[500005];
bool points[100000],edges[100000],arrive[100000];
void dfs(int now){
	for(int i=0;i<ed[now].size();i++){
		if(!arrive[ed[now][i]]){
			arrive[ed[now][i]]=1;
			dfs(ed[now][i]);
		}
	}
}
bool cutedge(int cuts){
		memset(arrive,0,sizeof arrive);
	for(int i=1;i<=m;i++){
		if(i==cuts)continue;
		ed[e[i].a].push_back(e[i].b);
		ed[e[i].b].push_back(e[i].a);
	}
	for(int i=1;i<=n;i++){
		if(points[i]){dfs(i);break;}
	}
	for(int i=1;i<=n;i++)cout<<arrive[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++){
		if(points[i]&&!arrive[i]){return 0;}
	};return 1;
}
void solve(int now){
	if(now>n){
		int cnt=1;
		if(!check)return;
		for(int i=1;i<=m;i++){if(cutedge(i))cnt*=2;
		}for(int i=1;i<=n;i++)ed[i].clear();
		answers=(answers+cnt)%1000000007;
		return;
	}
	solve(now+1);
	points[now]=1;
	check=1;
	solve(now+1);
	points[now]=0;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&e[i].a,&e[i].b);
		if(e[i].a-e[i].b!=1&&e[i].a-e[i].b!=-1)flag=1;
	}
	if(m==n-1&&!flag){
		long long ans=((n*n-n)/2)%1000000007,ans2=n;
		for(int i=1;i<=n-2;i++){
			ans=(ans*2)%1000000007;
			ans2=(ans2*2)%1000000007;
		}ans2*=2;
		cout<<(ans+ans2)%1000000007;
	}
	else{
		solve(1);
		cout<<answers;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
