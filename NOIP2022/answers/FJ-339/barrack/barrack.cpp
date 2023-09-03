#include<bits/stdc++.h>
#define mod 100000007
#define N 500004
using namespace std;
int n,m,ans;
int mi[N];

inline int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x;
}
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		u=read(),v=read();
	}
	mi[0]=1;
	for(int i=1;i<n;i++)
		mi[i]=(mi[i-1]<<1)%mod;
	printf("%d",(1ll*n*(n-1)>>1)%mod*mi[n-2]%mod+1ll*n*mi[n-1]%mod);
}
//µ±Á´Ê±: ans=(n*(n-1)>>1)*(1<<(n-2))+n*(1<<(n-1))
