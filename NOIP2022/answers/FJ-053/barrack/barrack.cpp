#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll Mod=1e9+7;
void read(int &x) {
	x=0;
	int w=1;
	char ch;
	while(ch<'0'||ch>'9') {
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=x*10+(ch-48);
		ch=getchar();
	}
	x*=w;
}
int n,m;
int head[1000001],ver[199991],nxt[100001],tot;
int x[100001],y[100001];
void add(int x,int y) {
	nxt[++tot]=head[x];
	head[x]=tot;
	ver[tot]=y;
}
int dfn[100001],low[1000001],vis[1000001],stac[199991],top,cnt;
int ccnt,c[1000001],siz[1000001];
void tarjan(int x,int fa) {
//	cout<<x<<" "<<"\n";
	dfn[x]=low[x]=++cnt;
	vis[x]=1;
	stac[++top]=x;
	for(int i=head[x]; i; i=nxt[i]) {
		int y=ver[i];
		if(y==fa)continue;
		if(!dfn[y]) {
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		} else if(vis[y])low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x]) {
		++ccnt;
		int z;
		do {
			z=stac[top--];
//			cout<<z<<" ";
			c[z]=ccnt;
			siz[ccnt]++;
			vis[z]=0;
			if(z==x)break;
		} while(1);
//		cout<<"\n";
	}

}
int ht2[1000001],ht[1000001];
int sume[1000001],q[1000001];
ll ans;
bool b[100001];
int dfs(int x,int fa) {
	if(q[x]==1&&fa!=0)
		return 1;
	
	for(int i=head[x]; i; i=nxt[i]) {
		if(ver[i]==fa||b[i])continue;
		if(dfs(ver[i],x))
			b[i]=1;

	}
	return 0;
}
void check() {

	memset(b,0,sizeof(b));
//	for(int i=1;i<=ccnt;++i)
//	cout<<q[i]<<" ";
//	cout<<"\n";
	bool dd=0;
	for(int i=1; i<=ccnt; ++i)
		if(q[i]==1)dd=1;
	if(dd==0)return ;
	ll sum=1,cnt=0;
	for(int i=1; i<=ccnt; ++i)
		if(q[i])dfs(i,0);
	for(int i=1; i<=ccnt; ++i)
		if(siz[i]>1) {
			if(q[i])sum=sum*ht[siz[i]]%Mod*(ht[siz[i]]+1)%Mod;
			else  sum=sum*(ht[siz[i]]+1)%Mod;
		}
	for(int i=1; i<=tot; i+=2)
		if(!b[i])++cnt;
//		cout<<ht2[cnt]<<" "<<sum<<" "<<ht2[cnt]*sum<<"\n";
//	cout<<sum<<"\n";
	ans=(ans+ht2[cnt]*sum%Mod)%Mod;

}
void dfs(int x) {
	if(x==ccnt+1) {
		check();
		return ;
	}
	q[x]=0;
	dfs(x+1);
	q[x]=1;
	dfs(x+1);
	q[x]=0;
}
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	read(n);
	read(m);
	ht2[0]=1;
	ht2[1]=2;
	for(int i=2; i<=n; ++i)
		ht2[i]=ht2[i-1]*2%Mod;
	ht[1]=1;
	for(int i=2; i<=n; ++i)
		ht[i]=(ht[i-1]*2+1)%Mod;
	for(int i=1; i<=m; ++i) {
		read(x[i]);
		read(y[i]);
		add(x[i],y[i]);
		add(y[i],x[i]);
	}
	for(int i=1; i<=n; ++i)
		if(!dfn[i])tarjan(i,0);
	memset(head,0,sizeof(head));
	tot=0;
	for(int i=1; i<=m; ++i) {
		if(c[x[i]]!=c[y[i]]) {
			add(c[x[i]],c[y[i]]);
			add(c[y[i]],c[x[i]]);
		}
	}
	dfs(1);
	cout<<ans<<"\n";
}
/*
1 4
3 3
1 2
2 3
3 1
*/
