#include<bits/stdc++.h>
using namespace std;
#define mod 18446744073709551615
const int N=250005;
int T,n,q;
unsigned long long a[N],b[N],ans;
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++)scanf("%llu",&a[i]);
	for(int i=1;i<=n;i++)scanf("%llu",&b[i]);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;p++)
			for(int q=p;q<=r;q++){
				if(p>q)continue;
				ans=(ans+a[p]*b[q]);
				if(ans>mod){
					ans=ans-mod-1;
				}
			}
		printf("%llu\n",ans);
	}
}
