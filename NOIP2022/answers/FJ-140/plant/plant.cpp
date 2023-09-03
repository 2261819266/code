#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll T,id,n,m,c,f,ac,af;
int a[1001][1001];
char s[1001];
inline ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
inline ll right(ll sx,ll sy){
	ll tot=0;
	for(ll i=sy+1;i<=m;i++){
		if(!a[sx][i]) tot++;
		else return tot; 
	}
	return tot;
}
inline ll down(ll sx,ll sy){
	ll tot=0;
	for(ll i=sx+1;i<=n;i++){
		if(!a[i][sy]) tot++;
		else return tot; 
	}
	return tot;
}
inline void bfs(ll sx,ll sy){
	if(sx>=n+2) return;
	while(a[sx][sy]) sx++;
	ll dow=down(sx,sy),bj[1001];
	if(dow>=2){
		for(int i=sx;i<=sx+dow;i++){
			bj[i]=right(i,sy)%mod;
		}
		for(int i=sx;i<=sx+dow;i++){
			if(bj[i])
				for(int j=i+2;j<=sx+dow;j++){
					ac+=bj[i]*bj[j];
					ac%=mod;
					af+=bj[i]*bj[j]*(sx+dow-j);
					af%=mod;
			}
		}
	}
	bfs(sx+dow+2,sy);
	return;
}
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--){
		ac=0,af=0;
		n=read(),m=read(),c=read(),f=read();
		if(c==0&&f==0){
			printf("0 0\n");
			continue;
		}
		for(ll i=1;i<=n;i++){
			scanf("%s",s+1);
			for(ll j=1;j<=m;j++){
				a[i][j]=(s[j]^48);
			} 
		}
		for(ll j=1;j<=m;j++){
			bfs(1,j);
		}
		printf("%lld %lld\n",(c*ac)%mod,(f*af)%mod);
	}
	return 0;
} 
