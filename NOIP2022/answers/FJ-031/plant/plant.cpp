#include<bits/stdc++.h>
#define N 1010
#define mod 998244353
using namespace std;
int read() {
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)) f=ch=='-'?-1:1,ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int T,id,n,m,c,f,r[N][N],d[N][N],sumC,sumF;
char s[N][N];
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	T=read(),id=read();
	while(T--) {
		n=read(),m=read(),c=read(),f=read(),sumC=sumF=0;
		memset(r,0,sizeof(r));memset(d,0,sizeof(d));
		for(int i=1; i<=n; i++) scanf("%s",s[i]+1);
		for(int i=1; i<=n; i++) {
			r[i][m]=s[i][m]=='1'?-1:0;
			for(int j=m-1; j; j--) if(s[i][j]=='1') r[i][j]=-1; else r[i][j]=r[i][j+1]+1;
		}
		for(int j=1; j<=m; j++) {
			d[n][j]=s[n][j]=='1'?-1:0;
			for(int i=n-1; i; i--) if(s[i][j]=='1') d[i][j]=-1; else d[i][j]=d[i+1][j]+1;
		}
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=m; j++) printf("%d ",r[i][j]);
//			puts("");
//		}
		for(int j=1; j<=m; j++) {
			int pre=-1;
			for(int i=1; i<=n; i++) {
				if(r[i][j]==-1) pre=-1;
				else {
					if(pre==-1) {
						if(s[i][j]=='0'&&s[i-1][j]=='0') pre=r[i-1][j];
						continue;
					}
					sumC=(sumC+1ll*r[i][j]*pre%mod)%mod;
					sumF=(sumF+1ll*r[i][j]*d[i][j]%mod*pre%mod)%mod;
					pre=(pre+r[i-1][j])%mod;
				}
			}
		}
		printf("%d %d\n",c*sumC,f*sumF);
	}
} 
