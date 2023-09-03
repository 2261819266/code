#include<bits/stdc++.h>
#define ULL unsigned long long
using namespace std;
const int MAX=2*1e6+5,MOD=1e9+7;
ULL n,m,ans,tot,ver[MAX],head[MAX],nxt[MAX],u[MAX],v[MAX];
bool jy[MAX],mark[MAX];
void add(int x,int y){
	ver[++tot]=y;
	nxt[tot]=head[x];
	head[x]=tot;
}
void check(int d,int x,int y){
	mark[d]=1;
	for(int i=head[d];i;i=nxt[i]){
		int k=ver[i];
		if((d==x&&k==y)||(d==y&&k==x)||mark[k])continue;
		mark[k]=1;
		check(k,x,y);
	}
}
void dfs(int x,bool op,int d){
	if(x==n+1){
		if(op){
			int sum=0;
			for(int i=1;i<=m;i++){
				memset(mark,0,sizeof(mark));
				check(d,u[i],v[i]);
				bool p=0;
				for(int j=1;j<=n;j++){
					if(jy[j]&&mark[j]==0)p=1;
				}
				sum+=p;
			}
			ans=(ans+(1<<(m-sum)))%MOD;
			
		}
		return ;
	}
	jy[x]=1;
	dfs(x+1,1,x);
	jy[x]=0;
	dfs(x+1,op,d);
}
ULL sum(ULL k){
	ULL cnt=2,p=1;
	while(k){
		if(k%2)p=p*cnt%MOD;
		k/=2;
		cnt=cnt*cnt%MOD;
	}
	return p;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i];
		add(u[i],v[i]); add(v[i],u[i]);
	}
	if(n<=16){
		dfs(1,0,0);
		cout<<ans;
	}
	else {
		for(ULL i=2;i<=n;i++){
			ULL k=sum(n-i);
			k=(k*sum(i-2))%MOD;
			k=(k*(n-i+1))%MOD;
			ans=(ans+k)%MOD;
		}
		cout<<(ans+(n*sum(m)%MOD))%MOD;
	}
	return 0;
}
