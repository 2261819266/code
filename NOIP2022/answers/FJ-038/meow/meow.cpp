#include<bits/stdc++.h>
#define reg register
#define maxn 310
#define maxm 2000010
int read() {
	reg int s=0,f=1; reg char ch;
	for(;(ch=getchar())<'0'||ch>'9';ch=='-'?f=-f:0);
	for(;ch>='0'&&ch<='9';s=s*10+ch-'0',ch=getchar());
	return s*f;
}
int n,m,K,tt,a[maxm],s1[maxn],s2[maxn],ans0[maxm<<1],ans1[maxm<<1],ans2[maxm<<1];
void op1(reg int x) {ans0[++tt]=1,ans1[tt]=x;}
void op2(reg int x1,reg int x2) {ans0[++tt]=2,ans1[tt]=x1,ans2[tt]=x2;}
void Main() {
	n=read(),m=read(),K=read(),tt=0;
	for(reg int i=1;i<=m;++i) a[i]=read();
	if(K==n-1<<1) {
		memset(s1,0,(n+1)*sizeof(int)),memset(s2,0,(n+1)*sizeof(int));
		for(reg int i=1,k;i<=m;++i)
			if(k=a[i]+1>>1,s1[k]==a[i]) op1(n),op2(k,n),s1[k]=s2[k],s2[k]=0;
			else if(s2[k]==a[i]) op1(k),s2[k]=0;
			else op1(k),(s1[k]?s2[k]:s1[k])=a[i];
	}
	else {

	}
	printf("%d\n",tt);
	for(reg int i=1;i<=tt;++i)
		if(ans0[i]==1) printf("1 %d\n",ans1[i]);
		else printf("2 %d %d\n",ans1[i],ans2[i]);
}
int main() {
	freopen("meow.in","r",stdin);
	freopen("meow.out","w",stdout);
	for(reg int T=read();T--;Main());
	return 0;
}