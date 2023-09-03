#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#define N 250005
//#define int unsigned long long
int T,n,t,Q,l,r;
int a[N],b[N];
int f[7005][7005];
int stA[N][20],stB[N][20];
unsigned long long ans;
int read(){
	int x=0,f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+(ch xor 48);
	return x*f;
}
inline int max(int a,int b){return a>b?a:b;}
void pre(){
	for(int i=1;i<=n;++i) stA[i][0]=a[i],stB[i][0]=b[i];
	for(int k=1;k<=t;++k){
		for(int i=1;i<=n;++i) stA[i][k]=max(stA[i][k-1],stA[i+(1<<(k-1))][k-1]),stB[i][k]=max(stB[i][k-1],stB[i+(1<<(k-1))][k-1]);
	}
}
int queryA(int l,int r){
	int k=log2(r-l+1);
	return max(stA[l][k],stA[r-(1<<k)+1][k]);
}
int queryB(int l,int r){
	int k=log2(r-l+1);
	return max(stB[l][k],stB[r-(1<<k)+1][k]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read(),t=log2(n);
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<=n;++i) b[i]=read();
	pre();
	Q=read();
	while(Q--){
		ans=0;
		l=read(),r=read();
		for(int i=l;i<=r;++i) for(int j=i;j<=r;++j) ans+=queryA(i,j)*queryB(i,j);
		std::cout<<ans<<'\n';
	}
	return 0;
}

