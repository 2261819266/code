#include<cstdio>
using namespace std;
int T,n,a[3005],b[3005],q;
unsigned long long f[3005][3005],t[3005][3005];
int max(int x,int y){return x>y?x:y;}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i){
		unsigned long long Maxa=a[i],Maxb=b[i];
		for(int j=i;j<=n;++j)Maxa=max(Maxa,a[j]),Maxb=max(Maxb,b[j]),t[i][j]=t[i][j-1]+Maxa*Maxb;
	}
	for(int i=n;i>=1;--i)for(int j=i;j<=n;++j)f[i][j]=f[i+1][j]+t[i][j];
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		printf("%llu\n",f[l][r]);
	}
	return 0;
}/*
0 2
2 1
1 2
1
1 2
*/