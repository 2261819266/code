#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 3009;
 long long maxa[N][N],maxb[N][N],sum[N][N],ans,mod=100000009;
int a[N],b[N];
long long max( long long a, long long b){
	return a>b?a:b;
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int Q,T,n,i,j,l,r;
//	mod=1;
//	for(i=1;i<=64;i++)
//	mod*=2;
	scanf("%d%d",&T,&n);
		memset(sum,0,sizeof(sum));
		memset(maxa,0,sizeof(maxa));
		memset(maxb,0,sizeof(maxb));
		for(i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(i=1;i<=n;i++)	
			scanf("%d",&b[i]);
		for(i=1;i<=n;i++){
			maxa[i][i]=a[i];
			for(j=i+1;j<=n;j++)
				maxa[i][j]=max(maxa[i][j-1],a[j]);
		}
		for(i=1;i<=n;i++){
			maxb[i][i]=b[i];
			for(j=i+1;j<=n;j++)
				maxb[i][j]=max(maxb[i][j-1],b[j]);
		}
		for(i=1;i<=n;i++){
			sum[i][i]=(maxa[i][i]*maxb[i][i]);
			for(j=i+1;j<=n;j++){
				sum[i][j]=(sum[i][j-1]+maxa[i][j]*maxb[i][j]);
			}
		} 
		scanf("%d",&Q);
		while(Q--){
			scanf("%d%d",&l,&r);
			ans=0;
			for(i=l;i<=r;i++)
				ans=(ans+sum[i][r]);
			printf("%lld\n",ans);
		}
	
	return 0;
}
