#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3010;
int n,q;
LL maxa[N][N],maxb[N][N],wonder[N][N],ans[N][N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",&maxa[i][i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			maxa[i][j]=max(maxa[i][j-1],maxa[j][j]);
	for(int j=1;j<=n;++j)
		scanf("%lld",&maxb[j][j]);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
			maxb[i][j]=max(maxb[i][j-1],maxb[j][j]),
			wonder[i][j]=maxa[i][j]*maxb[i][j];
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			ans[i][j]=ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1]+wonder[i][j];
//	for(int i=1;i<=n;++i)
//		for(int j=1;j<=n;++j)
//			printf("%lld\n",ans[i][j]);
	scanf("%d",&q);
	for(int i=1,l,r;i<=q;++i){
		scanf("%d%d",&l,&r);
		printf("%lld\n",ans[r][r]-ans[l-1][r]-ans[r][l-1]+ans[l-1][l-1]);
	}
	return 0;
}
