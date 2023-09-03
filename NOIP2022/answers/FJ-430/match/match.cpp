#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int t,n,m,a[250001],b[250001];
long long ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;++i)
	    scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	    scanf("%d",&b[i]);
	scanf("%d",&m);
	while(m--){
		ans=0;
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;++i)
		    for(int j=i;j<=r;++j){
		    	int maxx=-1,maxn=-1;
		    	for(int k=i;k<=j;++k){
		    		maxx=max(a[k],maxx);
		    		maxn=max(b[k],maxn);
				}
				ans+=(long long)maxx*maxn;
			}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
