#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,nu,a[250005],b[250005],dpa[250005][20],dpb[250005][20],lo[250005];
int aska(int li,int ri){
	int sum=lo[ri-li+1];
	return max(dpa[li][sum],dpa[ri-(1<<sum)+1][sum]); 
}
int askb(int li,int ri){
	int sum=lo[ri-li+1];
	return max(dpb[li][sum],dpb[ri-(1<<sum)+1][sum]);
}
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&nu,&n);
	lo[1]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		dpa[i][0]=a[i];
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		dpb[i][0]=b[i];
	}
	for(int j=1;j<=lo[n];j++){
		for(int i=1;i<=n-(1<<j)+1;i++){
			dpa[i][j]=max(dpa[i][j-1],dpa[i+(1<<(j-1))][j-1]);
			dpb[i][j]=max(dpb[i][j-1],dpb[i+(1<<(j-1))][j-1]);
		}
	}
	scanf("%d",&q);
	while(q--){
		int l,r;
		unsigned long long ans=0;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++){
			for(int j=i;j<=r;j++){
				ans+=(unsigned long long)(aska(i,j)*askb(i,j));
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}
