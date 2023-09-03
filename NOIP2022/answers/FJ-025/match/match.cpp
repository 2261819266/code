#include<cstdio>
#define reg register
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
const int MAXN=3050;
unsigned long long G[MAXN][MAXN],S[MAXN][MAXN];
int A[MAXN][MAXN],B[MAXN][MAXN],a[MAXN],b[MAXN],n,Q;
int read(){
	reg int s=0,f=1;
	reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=(s<<3)+(s<<1)+ch-'0',ch=getchar());
	return s*f;
}
void kotori(){
	n=read();
	for(reg int i=1;i<=n;i++){
		a[i]=read();
	}
	for(reg int i=1;i<=n;i++){
		b[i]=read();
	}
	for(reg int i=1;i<=n;i++){
		A[i][i]=a[i];
		B[i][i]=b[i];
		G[i][i]=a[i]*b[i];
		for(reg int j=i+1;j<=n;j++){
			A[i][j]=max(a[j],A[i][j-1]);
			B[i][j]=max(b[j],B[i][j-1]);
			G[i][j]=A[i][j]*B[i][j];
		}
	}
	for(reg int i=1;i<=n;i++){
		for(reg int j=1;j<=n;j++){
			S[i][j]=S[i][j-1]+G[i][j];
		}
	}
	for(reg int i=1;i<=n;i++){
		for(reg int j=1;j<=n;j++){
			S[i][j]+=S[i-1][j];
		}
	}
	Q=read();
	int l,r;
	while(Q--){
		l=read(),r=read();
		printf("%llu\n",S[r][r]+S[l-1][l-1]-S[l-1][r]-S[r][l-1]);
	}
	return;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int _=1,__;__=read();
	while(_--)kotori();
}
