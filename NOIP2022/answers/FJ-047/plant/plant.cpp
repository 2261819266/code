#include <cstdio>
#include <cstring>
#include <iostream>
#define N 1005
#define mod 998244353
#define int long long
int T,id,n,m,c,f,ans_C,ans_F;
char mp[N][N];
struct node{
	int a,b;
}q[N][N];
int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch xor 48);
	return x*f;
}
void solve(){
	memset(q,0,sizeof(q));
	memset(mp,0,sizeof(mp)); // 不加见祖宗.
	n=read(),m=read(),c=read(),f=read(),ans_C=0,ans_F=0;
	if(c==0 and f==0){
		puts("0 0");
		return;
	}
	for(int i=1;i<=n;++i) for(int j=1;j<=m;++j) std::cin>>mp[i][j];
	q[n][m].a=q[n][m].b=(mp[n][m]=='0');
	for(int i=n;i>=1;--i){
		for(int j=m;j>=1;--j){
			if(i==n and j==m) continue;
			q[i][j].a=mp[i][j]=='0'?q[i][j+1].a+1:0;
			q[i][j].b=mp[i][j]=='0'?q[i+1][j].b+1:0;
		}
	}
	for(int i=1;i<n-1;++i){
		for(int j=1;j<m;++j){
			if(q[i][j].a<2 or q[i][j].b<3) continue;
			for(int k=i+2;k<=i+q[i][j].b-1;++k){
				if(q[k][j].a<2) continue;
				if(mp[k][j]=='1') break;
				ans_C+=(q[i][j].a-1)*(q[k][j].a-1);
				ans_F+=(q[i][j].a-1)*(q[k][j].a-1)*(q[k][j].b-1);
				if(ans_C>mod) ans_C%=mod;
				if(ans_F>mod) ans_F%=mod; // 卡常 
			}
		}
	}
	printf("%lld %lld\n",(c*ans_C)%mod,(f*ans_F)%mod);
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--) solve();
	return 0;
}
