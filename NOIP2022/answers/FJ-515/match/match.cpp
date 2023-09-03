#include<bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;
ll t,n,a[50],b[50],maxb;
ll the_test,l,r,maxa,ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	scanf("%d",&the_test);
	while(the_test--){
		scanf("%d%d",&l,&r);
		for(int i=l;i<=r;i++){
			maxa=maxb=0;
			for(int j=i;j<=r;j++){
				maxa=max(maxa,a[j]);
				maxb=max(maxb,b[j]);
				ans=(ans+(maxa*maxb));
			}
		}
		printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

