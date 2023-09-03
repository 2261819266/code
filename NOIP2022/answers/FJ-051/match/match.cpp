#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
int n,q,t;
int a[250001],b[250001];
int main(){
	freopen("match.in","r",stdin),freopen("match.out","w",stdout);
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;++i)scanf("%d",a+i);
	for(int i=1;i<=n;++i)scanf("%d",b+i);
	scanf("%d",&q);
	while(q--){
		int l,r;
		scanf("%d%d",&l,&r);
		ull ans=0;
		for(int x=r;x>=l;x--){
			int ma=0,mb=0;
			for(int y=x;y<=r;++y){
				ma=max(ma,a[y]),mb=max(mb,b[y]);
				ans+=ma*(ull)mb;
			}
		}
		printf("%llu\n",ans);
	}
}
