#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int N=250000;

ll a[N],b[N],dp[3010][3010];

int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int _T,n;
	scanf("%d%d",&_T,&n);
	for(int i=1;i<=n;i++)
		scanf("%llu",&a[i]);
	for(int j=1;j<=n;j++)
		scanf("%llu",&b[j]);
	for(int l=1;l<=n;l++){
		ll maxa=0,maxb=0;
		for(int r=l;r<=n;r++){
			maxa=max(maxa,a[r]);
			maxb=max(maxb,b[r]);
			dp[l][r]=maxa*maxb;
		}		
	}
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			dp[i][j]=dp[i][j-1]+dp[i][j];
	int q;
	scanf("%d",&q);
	ll ans=0;
	for(int i=1,l,r;i<=q;i++){
		ans=0;
		scanf("%d%d",&l,&r);
		for(int j=l;j<=r;j++)
			ans+=dp[j][r]-dp[j][j-1];
		printf("%llu\n",ans);
	}
	return 0;
}
