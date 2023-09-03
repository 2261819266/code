#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3010;
int n,q,a[N],b[N],ax[N][N],bx[N][N];
ll sum[N][N],ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,l,r;
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;++i) scanf("%d",a+i),ax[i][i]=a[i];
	for(int i=1;i<=n;++i) scanf("%d",b+i),bx[i][i]=b[i];
	for(int i=1;i<=n;++i){
		sum[i][i]=(ll)a[i]*b[i];
		for(int j=i+1;j<=n;++j){
			ax[i][j]=max(a[j],ax[i][j-1]);
			bx[i][j]=max(b[j],bx[i][j-1]);
			sum[i][j]=sum[i][j-1]+(ll)ax[i][j]*bx[i][j];
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d%d",&l,&r);ans=0;
		for(int i=l;i<=r;++i) ans+=sum[i][r];
		printf("%lld\n",ans);
	}
	return 0;
}
