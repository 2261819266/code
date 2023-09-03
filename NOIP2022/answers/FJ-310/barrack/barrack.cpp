#include<bits/stdc++.h>
#define reg register
#define IL inline
using namespace std;
const int N=5e5+7,mod=1e9+7;
int n,m,u[N],v[N],sz[N],f[N],Ans;
int F(reg int x){return f[x]^x?f[x]=F(f[x]):x;}
int main(){
	freopen("barrack.in","r",stdin),freopen("barrack.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(reg int i=0;i<m;++i)scanf("%d%d",&u[i],&v[i]);
	for(reg int S=1;S<(1<<n);++S)
		for(reg int T=0;T<(1<<m);++T){
			reg bool Res=1;
			for(reg int i=0,k;i<m&&Res;++i)
				if(!(T&(1<<i))){
					for(reg int j=1;j<=n;++j)f[j]=j;
					for(reg int j=0;j<m;++j)if(i^j)f[F(u[j])]=F(v[j]);
					k=0;
					for(reg int j=0;j<n&&!k;++j)if(S&(1<<j-1))k=j;
					reg bool res=1;
					for(reg int j=1;j<=n&&res;++j)if((S&(1<<j-1))&&F(j)!=F(k))res=0;
					Res&=res;
				}
			Ans+=Res;
		}
	return !printf("%d",Ans+(1<<m)-1);
}
