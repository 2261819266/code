#include<bits/stdc++.h>
using namespace std;
#define N 250010
#define int unsigned long long
int t,n,q,logg,cnt,ans,st1[N][22],st2[N][22],sum[3010][3010];
int ask1(int l,int r){
	logg=log2(r-l+1);
	return max(st1[l][logg],st1[r-(1<<logg)+1][logg]);
}
int ask2(int l,int r){
	logg=log2(r-l+1);
	return max(st2[l][logg],st2[r-(1<<logg)+1][logg]);
}
signed main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)scanf("%d",&st1[i][0]);
	for(int i=1;i<=n;i++)scanf("%d",&st2[i][0]);
	for(int j=1;j<=21;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
	for(int j=1;j<=21;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st2[i][j]=max(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
	if(t>5&&t<=13){
		scanf("%d",&q);
		for(int i=1,l,r;i<=q;i++){
			scanf("%d%d",&l,&r);
			for(int a=l;a<=r;a++)
				for(int b=a;b<=r;b++)
					ans+=ask1(a,b)*ask2(a,b);
			printf("%llu\n",ans);
		}
	}else{
		for(int i=1;i<=n;i++){
			sum[i][i]=st1[i][0]*st2[i][0];
			for(int j=i+1;j<=n;j++){
				sum[i][j]=sum[i][j-1]+ask1(i,j)*ask2(i,j);
			}
		}scanf("%d",&q);
		for(int i=1,l,r;i<=q;i++){
			scanf("%d%d",&l,&r);
			for(int j=l;j<=r;j++)
				ans+=sum[j][r];
			printf("%llu\n",ans);
		}
	}
	return 0;
}