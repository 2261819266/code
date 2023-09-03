#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int qpow(int a1,int a2) {
	int res=1;
	while(a2) {
		if(a2&1) res=1ll*res*a1%mod;
		a1=1ll*a1*a1%mod;
		a2>>=1;
	} return res;
}
int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int ans,n,m,flag=1;
int main() {
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	n=read(),m=read();
	if(m!=n-1) flag=0;
	for(int i=1; i<=m; i++) {
		int u=read(),v=read();
		if(u!=i||v!=i+1) flag=0;
	}
	if(flag) {
		ans=1ll*qpow(2,m)%mod*2%mod;
		for(int i=1; i<n; i++) 
			ans=(ans+1ll*(n-i)*qpow(2,m-i)%mod*qpow(2,n-2)%mod)%mod;
		printf("%d",ans);
		return 0;
	}
}
