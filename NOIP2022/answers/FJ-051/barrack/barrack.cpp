#include<stdio.h>
#include<string.h>
const int mod=1000000007;
int n,m,ans;
int u[1000005],v[1000005];
int tot,head[500005],to[2000005],nxt[2000005];
void add(int x,int y){
	nxt[++tot]=head[x],to[tot]=y,head[x]=tot;
}
int s[500005],top,bl[500005];
void color(int x,int fa){
	bl[x]=1;
	for(int i=head[x];i;i=nxt[i])if(!bl[to[i]])color(to[i],x);
}
bool check(){
	if(!top)return 0;
	memset(bl,0,sizeof bl);
	color(s[1],0);
	for(int i=1;i<=top;++i)if(!bl[s[i]])return 0;
	return 1;
}
void dfs1(int i){
	if(i==m+1){
		if(check())ans++;
		return;
	}
	int x=head[u[i]],y=head[v[i]];
	add(u[i],v[i]),add(v[i],u[i]);
	dfs1(i+1);
	tot-=2,head[u[i]]=x,head[v[i]]=y;
	dfs1(i+1);
}
void dfs2(int x){
	if(x==n+1){
		dfs1(1);
		return;
	}
	s[++top]=x;
	dfs2(x+1);
	top--;
	dfs2(x+1);
}
int main(){
	freopen("barrack.in","r",stdin),freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	int flag=m==n-1;
	for(int i=1;i<=m;++i)scanf("%d%d",&u[i],&v[i]),flag&=(u[i]==i&&v[i]==i+1)||(u[i]==i+1||v[i]==i);
	dfs2(1);
	printf("%d",ans);
}
