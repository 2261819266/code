#include <bits/stdc++.h>
using namespace std;
#define MAXX 300005
#define ll unsigned long long
int T,Q,n,a[MAXX],b[MAXX],l,r;
int maxa[MAXX][20],maxb[MAXX][20];
int fina[3005][3005],finb[3005][3005];
ll ans=0;
void ycl(){
	for(int i=1;i<=n;i++) maxa[i][0]=a[i],maxb[i][0]=b[i];
	for(int t=1;t<20;t++){
		for(int i=1;i<=n;i++){
			maxa[i][t]=max(maxa[i][t-1],maxa[i+(1<<(t-1))][t-1]);
			maxb[i][t]=max(maxb[i][t-1],maxb[i+(1<<(t-1))][t-1]);
		}
	}
}
int finda(int x,int y){
	int t=log2(y-x+1);
	return max(maxa[x][t],maxa[y-(1<<t)+1][t]);
}
int findb(int x,int y){
	int t=log2(y-x+1);
	return max(maxb[x][t],maxb[y-(1<<t)+1][t]);
}
int main (){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	ycl(),scanf("%d",&Q);
	if(n<=3000){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				fina[i][j]=finda(i,j),finb[i][j]=findb(i,j);
	}
	while(Q--){
		scanf("%d%d",&l,&r),ans=0;
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				if(n>3000)ans+=finda(i,j)*findb(i,j);
				else ans+=fina[i][j]*finb[i][j];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
