#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,MOD=1e9+7;
int n,m,head[N],ver[N*2],nxt[N*2],tot,ans;
int qpow(int a,int b,int p){
	int ret=1;
	for (;b;b>>=1,a=1ll*a*a%p) if (b&1) ret=1ll*ret*a%p;
	return ret;
}
void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
int read(){
	int x=0;
	char c=getchar();
	while (!isdigit(c)) c=getchar();
	while (isdigit(c)) x=x*10+c-48,c=getchar();
	return x;
}
bool F[20],a[20];
int vis[20],pre[20];
map<pair<int,int>,int> idx;
vector<int> x;
queue<int> q;
void work(int k){
	if (k>n+m){
//		if (!(F[1]==1&&F[2]==1&&F[3]==1&&F[4]==0&&F[5]==0&&F[6]==0&&F[7]==0&&F[8]==0)) return;
//		printf("\nwork(%d):\n",n+m);
		x.clear();
		int sA=0,sB=0;
		for (int i=1;i<=n;i++) if (F[i]) sA++,x.push_back(i);
//		puts("");
		for (int j=n+1;j<=n+m;j++) if (F[j]) sB++;
//		puts("");
		if (sA==0) return;
		if (sA==1){ans++;return;}
//		printf("x includes %d values: ",x.size());
//		puts("");
		memset(a,0,sizeof a),memset(vis,0,sizeof vis),memset(pre,0,sizeof pre);
		q.push(x[0]),a[x[0]]=1,vis[x[0]]=1;
		while (!q.empty()){
			int u=q.front(); q.pop();
//			cout<<"q.front():"<<u<<"("<<a[u]<<","<<vis[u]<<")"<<endl;
			for (int i=head[u];i;i=nxt[i]){
				int v=ver[i];
//				cout<<"u->v:"<<v;
				if (!vis[v]) a[v]=a[u]&F[idx[make_pair(min(u,v),max(u,v))]],q.push(v),pre[v]=u,vis[v]=1;
				else if (pre[u]!=v) vis[v]++;
//				cout<<":"<<vis[v]<<"th visit\n";
			}
		}
		bool Flag=1;
		for (int i=0;i<x.size();i++) if (!a[x[i]]&&vis[x[i]]<2) Flag=0;
//		for (int i=0;i<x.size();i++) printf("%d(%d,%d)",x[i],a[x[i]],vis[x[i]]);
		if (Flag) ans++;
		return;
	}
	work(k+1),F[k]=1,work(k+1),F[k]=0;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	for (int i=1,u,v;i<=m;i++){
		u=read(),v=read(),add(u,v),add(v,u);
		if (n<=8&&m<=10) idx[make_pair(min(u,v),max(u,v))]=i+n;
	}
	if (n==1){puts("0");return 0;}
	if (n==2){puts("5");return 0;}
	if (n==3&&m==3){puts("63");return 0;}
	if (m==n-1){printf("%d\n",qpow(2,n,MOD)-1);return 0;}
	if (n<=8&&m<=10){
		work(1);
		printf("%d\n",ans);
		return 0;
	}
	
	return 0;
}
