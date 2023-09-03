#include <cstdio>
#include <cstring>
#include <iostream>
#define N 50005
#define M 100006
int n,m,tot,root,ans;
int d[3005][3005],f[3005][3005];
int ver[M<<1],nxt[M<<1],head[N];
int a[3005],b[3005];
bool useN[N],useE[M];
int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch xor 48);
	return x*f;
}
void add(int x,int y){
	ver[++tot]=y,nxt[tot]=head[x],head[x]=tot;
}
bool check_(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				f[i][j]|=f[i][k]&f[k][j];
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(i==j) continue;
			if(useN[i] and useN[j] and !f[i][j] and !f[j][i]) return false;
		}
	}
	return true;
}
bool check(){
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=d[i][j];
	for(int i=1;i<=m;++i){
		if(useE[i]) continue;
		f[a[i]][b[i]]=f[b[i]][a[i]]=0;
		if(!check_()) return false;
		f[a[i]][b[i]]=f[b[i]][a[i]]=1;
	}
	return true;
}
void dfs(int num){
	if(num==m+1){ans+=check();return;}
	useE[num]=1;
	dfs(num+1);
	useE[num]=0;
}
void dfs_(int num){
	if(num==n+1){
		dfs(1);
		return;
	}
	useN[num]=1;
	dfs_(num+1);
	useN[num]=0;
}
signed main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	if(n>=16 or m>=25){
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;++i){
		a[i]=read(),b[i]=read();
		add(a[i],b[i]);add(b[i],a[i]);
		d[a[i]][a[i]]=d[a[i]][b[i]]=1;
	}
	dfs_(1);
	printf("%d\n",ans);
	return 0;
}

