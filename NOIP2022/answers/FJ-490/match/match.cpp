#include<cstdio>
#include<algorithm>
using namespace std;
int T,Q,n,l,r;
long long a[250001],b[250001];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d %d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int j=1;j<=n;j++)scanf("%lld",&b[j]);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&l,&r);
		long long Na=0,Ba=0;
		long long ans=0;
		for(int len=1;len<=n;len++){
			for(int l=1;l<=n-len+1;l++){
				int r=l+len-1;
				for(int i=l;i<=r;i++){
					Na=max(Na,a[i]);
				}
				for(int i=l;i<=r;i++){
					Ba=max(Ba,b[i]);
				}
				ans+=Na*Ba;
				Na=0;
				Ba=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}