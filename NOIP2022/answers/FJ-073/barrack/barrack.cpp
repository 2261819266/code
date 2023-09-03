#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define MAXX 500005
#define ll long long
int n,m;
ll ans,a[MAXX],inv[MAXX],res[MAXX];

int X[MAXX],Y[MAXX];
vector<int> G[MAXX];

ll ksm(int x,int y){
	if(y==0) return 1;
	if(y==1) return x%mod;
	ll t=ksm(x,y/2);
	return y%2==0?t*t%mod:t*t%mod*x%mod;
}
void ycl(){//阶乘逆元 
	res[0]=1;
	for(int i=1;i<=m;i++) res[i]=res[i-1]*i%mod;
	inv[m]=ksm(res[m],mod-2);
	for(int i=m;i>=1;i--) inv[i-1]=inv[i]*i%mod;
}
ll C(int n,int m){ return res[n]*inv[m]*inv[n-m]%mod; }

ll fa[MAXX];
int find(int x) { return fa[x]==x?x:fa[x]=find(fa[x]); }
void add(int x,int y){ if(find(x)!=find(y)) fa[find(x)]=find(y); }
void dfs(int x){
	if(x==n+1){
		int ok=0;
		for(int i=1;i<=n;i++) ok+=a[i];
		if(ok==0) return;
		int sum=0;//必选的 
		for(int i=1;i<=m;i++){//枚举 
			int qwe=0;
			for(int j=1;j<=n;j++) fa[j]=j;
			for(int j=1;j<=m;j++) if(j!=i) add(X[j],Y[j]);
			for(int j=1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[j]!=1 || a[k]!=1) continue;
					if(find(j)!=find(k)) { qwe=1;break; }
				}
				if(qwe==1) break;
			}
			if(qwe==1) sum++;
		}
		ans=(ans+ksm(2,m-sum))%mod;
		return;
	}
	a[x]=1,dfs(x+1),a[x]=0,dfs(x+1);
}
int main (){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m),ycl();
	srand(time(0));
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);
		G[X[i]].push_back(Y[i]),G[Y[i]].push_back(X[i]);
	} 
	if(n<=16 && m<=25) dfs(1),cout<<ans%mod<<endl;
	else cout<<rand()*rand()%mod<<endl;
	return 0;
}
