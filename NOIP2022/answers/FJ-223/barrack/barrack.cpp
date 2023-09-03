#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 1009,mod=1e9+7;
struct E{
	int u,v;
}e[N];
int n,m,cnt;
long long ans=0,tot;
int fa[N],num[N],poww[N];
bool iu[N],safe[N],bb[N],fl;
int find(int x){if(fa[x]==x) return x;return fa[x]=find(fa[x]);}
void match(int u,int v){
	u=find(fa[u]);v=find(fa[v]);
	if(u!=v){
		fa[u]=v;
		num[v]+=num[u];
	}
}
void work(){
	int i;
	for(i=1;i<=n;i++){
		fa[i]=i;num[i]=bb[i];
	}
	for(i=1;i<=m;i++){
		if(!iu[i]){
			match(e[i].u,e[i].v);
		}
	}
//	for(i=1;i<=n;i++) cout<<fa[i]<<" ";cout<<endl; 
//	for(i=1;i<=n;i++) cout<<num[i]<<" ";cout<<endl;
	for(i=1;i<=n;i++) if(num[i]==tot) {
		fl=1;
		return;
	}
}
void dfs(int k){
	if(k==m+1){
		for(int i=1;i<=m;i++){
			if(safe[i]) continue; iu[i]=1;
	//		if(!safe[i]) iu[i]=1;
			fl=0;
			work();
			iu[i]=0;
			if(!fl){ 
				return;
			}
		}
		ans++;
		return ;
	}
	safe[k]=1;
	dfs(k+1);
	safe[k]=0;
	dfs(k+1);
}
void bul(int k,int nn){
	if(k==n+1){
		if(!nn) return;
		if(nn==1){
			ans+=poww[m];return;
		}
		tot=nn;
		dfs(1);
		return;
	}
	bb[k]=0;
	bul(k+1,nn);
	bb[k]=1;
	bul(k+1,nn+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	int i;
	scanf("%d%d",&n,&m);
	poww[0]=1;
	for(i=1;i<=m+1;i++)
		poww[i]=(2*poww[i-1])%mod;
	for(i=1;i<=m;i++){
		scanf("%d%d",&e[i].u,&e[i].v);
	}
	bul(1,0);
	printf("%lld",ans);
	return 0;
} 
