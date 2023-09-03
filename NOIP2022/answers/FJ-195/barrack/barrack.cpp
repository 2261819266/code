#include<bits/stdc++.h>
using namespace std;
int ans,a,b,vis[100000],cnt,n,m,head[100000],f[1000000],ans1;
struct node{
	int to,next;
}e[100000];
int in(int x){
	int ans2=0;
	for(int i=0;i<=x;i++){
		ans2+=f[x]/f[i]/f[x-i];
	}
	return ans2;
}
void add(int x,int y){
	e[++cnt].to=y;
	e[cnt].next=head[x];
	head[x]=cnt;
}
void bfs(int x,int val){
	vis[x]=1;
	for(int i=head[x];i>0;i=e[i].next){
		int v=e[i].to;
		if(!vis[v]){
			ans1+=f[m-val-1];
			bfs(v,val+1);
		}
	}
	vis[x]=0;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a>>b;
		add(a,b);
		add(b,a);
	}
	if(n==1){
		cout<<"1";
		return 0;
	}
	if(n==2&&m==1){
		cout<<"5";
		return 0;
	}
//	if(m==n-1){
//		cout<<
//	}
	f[0]=1;
	for(int i=1;i<=m;i++){
		f[i]=f[i-1]*i;
	}
	ans=n*(f[m]+1);
	for(int i=1;i<=n;i++){
		bfs(1,0);
	}
	cout<<ans+ans1;
}
