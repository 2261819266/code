#include<bits/stdc++.h>
#define reg register
#define maxn 1010
#define mod 998244353
#define _A(x,y) (x)=((x)+(y))%mod
int read() {
	reg int s=0,f=1; reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=s*10+ch-'0',ch=getchar());
	return s*f;
}
int n,m,c,f,ans0,ans1,nxt[maxn][maxn];
char s[maxn][maxn];
void Main() {
	n=read(),m=read(),c=read(),f=read(),ans0=ans1=0;
	for(reg int i=1;i<=n;++i) {
		scanf("%s",s[i]+1),nxt[i][m+1]=m+1;
		for(reg int j=m;j;--j) nxt[i][j]=nxt[i][j+1],s[i][j]=='1'?nxt[i][j]=j:0;
	}
	for(reg int j=1;j<=m;++j)
		for(reg int i=n-2,k=n,S=0;i>0;--i,--k) {
			if(s[k][j]=='1') S=0; else S+=nxt[k][j+1]-j-1;
			if(s[i+1][j]=='0'&&s[i][j]=='0') _A(ans0,(nxt[i][j+1]-j-1)*S);
		}
	for(reg int j=1;j<=m;++j)
		for(reg int i=n-2,k=n,S=0,lst=n+1;i>0;--i,--k) {
			if(s[k][j]=='1') S=0,lst=k; else S+=(nxt[k][j+1]-j-1)*(lst-k-1);
			if(s[i+1][j]=='0'&&s[i][j]=='0') _A(ans1,1llu*(nxt[i][j+1]-j-1)*S);
		}
	printf("%d %d\n",c*ans0,f*ans1);
}
int main() {
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	reg int T=read(); read();
	for(;T--;Main());
	return 0;
}