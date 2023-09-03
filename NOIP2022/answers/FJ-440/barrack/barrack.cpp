#include<bits/stdc++.h>
using namespace std;

int read(){
	int w=0,ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')w=w*10+ch-48,ch=getchar();
	return w;
}

#define MAXN 500003
#define MAXM 1000003
int n,m,ans;
const int mod=1000000007;

struct edge{
	int v,nxt;
}e[MAXM<<1];
int head[MAXN],ecnt;
void build(int u,int v){
	e[++ecnt].v=v;
	e[ecnt].nxt=head[u],head[u]=ecnt;
}

//int s[MAXN],scnt;
//int ban;
//
//void dfs(int u){
//	s[u]=scnt;
//	for(int i=head[u];i;i=e[i].nxt){
//		if(i==ban||i==ban+1)continue;
//		if(!s[e[i].v])dfs(e[i].v);
//	}
//}
//
//void solve1(){
//	for(int i=1;i<=m*2;i+=2){
//		for(int i=1;i<=n;i++)s[i]=0;
//		scnt=0;
//		for(int j=1;j<=n;j++)if(!s[j]){
//			ban=i,scnt++;
//			dfs(j);
//		}	
//		for(int i=1;i<=n;i++)cout<<s[i]<<' ';
//		cout<<endl;
//	}
//}
//
//int vis[MAXN];
//
//bool dfs(int u,int fath){
//	cout<<u<<endl;
//	bool flag=0;
//	for(int i=head[u];i;i=e[i].nxt){
//		int v=e[i].v;
//		if(v==fath)continue;
//		cout<<u<<' '<<v<<endl;
//		if(vis[v]==vis[u]){
//			flag=1;
//			continue;
//		}
//		vis[v]=vis[u];
//		cout<<"dd "<<vis[u]<<' '<<vis[v]<<endl;
//		if(vis[v]==vis[u])if(dfs(v,u))flag=1;
//	}
//	cout<<"d "<<u<<' '<<fath<<' '<<flag<<endl;
//	return flag;
//}
//
//void solve1(){
//	vis[1]=1,dfs(1,0);
//	for(int i=1;i<=n;i++)cout<<vis[i]<<' ';
//}

long long p2[MAXM<<1];

void init(int x){
	p2[0]=1;
	for(int i=1;i<=x;i++)p2[i]=(p2[i-1]<<1)%mod;
}

int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	init(m<<1);
	for(int i=1;i<=m;i++){
		int u=read(),v=read();
		build(u,v),build(v,u);
	}
//	solve1();
	if(m==n){
		printf("%lld\n",p2[m<<1]);
	}else printf("0\n");
	return 0;
}
/*

4 4
1 2
2 3
3 1
1 4
*/
// 1 11:09 m==n
