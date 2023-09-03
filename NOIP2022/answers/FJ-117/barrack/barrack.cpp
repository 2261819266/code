#include<bits/stdc++.h>
#define N 1100000
#define mod 1000000007
using namespace std;
int n,m,x,y,cnt,frm[N],to[2*N],nxt[2*N],vis[2*N],ta[N],v[N],d[N];
long long ans;
void add(int x,int y){to[++cnt]=y,nxt[cnt]=frm[x],frm[x]=cnt,d[cnt]=cnt+1;to[++cnt]=x,nxt[cnt]=frm[y],frm[y]=cnt,d[cnt]=cnt-1;}
long long ksm(long long x,long long k){
	long long now=1;
	while(k){
		if(k&1)now=now*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return now;
}
void search(int now){
	v[now]=1;
	for(int i=frm[now];i;i=nxt[i])if(!vis[i] && !v[to[i]])search(to[i]);
}
bool jud(){
	for(int i=1;i<=n;i++)v[i]=0;
	for(int i=1;i<=n;i++)if(ta[i]){
		search(i);
		break;
	}
	for(int i=1;i<=n;i++)if(ta[i] && !v[i])return 1;
	return 0;
}
void DFS(int now){
	if(now>n){
		int s=0,cant=0;
		for(int i=1;i<=n;i++)s+=ta[i];
		if(!s)return;
		for(int i=1;i<=m;i++){
			vis[2*i-1]=1,vis[2*i]=1;
			if(jud())cant++;
			vis[2*i-1]=0,vis[2*i]=0;
		}
		ans=(ans+ksm(1ll*2,1ll*(m-cant)))%mod;
		return;
	}
	ta[now]=0,DFS(now+1);
	ta[now]=1,DFS(now+1);
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d",&x,&y),add(x,y);
	if(n<=16 && m<=25)DFS(1);
	else ans=((n*(n-1)/2)%mod*ksm(1ll*2,1ll*(m-1))%mod+n*ksm(1ll*2,1ll*m)%mod)%mod;
	printf("%lld",ans);
	return 0;
}
