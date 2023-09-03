#include<cstdio>
#include<iostream>
const int maxn=3e5+10;
typedef unsigned long long ull;
int read(){
	int sum=0,sg=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')sg=-1; ch=getchar();}
	while(ch>='0'&&ch<='9')sum=(sum<<1)+(sum<<3)+ch-'0',ch=getchar();
	return sum*sg;
}
int T,n,Q,a[maxn],b[maxn];
ull sum[3010][3010];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	T=read(),n=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int r=1;r<=n;++r){
		int ma=a[r],mb=b[r];
		for(int l=r;l;--l){
			ma=std::max(ma,a[l]);
			mb=std::max(mb,b[l]);
			sum[l][r]=sum[l+1][r]+(ull)ma*mb;
		}
	}
	Q=read();
	while(Q--){
		int l=read(),r=read();
		ull ans=0;
		for(int i=l;i<=r;++i)ans+=sum[l][i];
		printf("%llu\n",ans);
	}
	return 0;
}
