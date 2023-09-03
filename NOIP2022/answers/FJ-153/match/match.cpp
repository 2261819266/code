#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
const int N=250005;
int a[N],b[N];
typedef unsigned long long ull;
int main()
{
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int T,n;scanf("%d%d",&T,&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	int q;scanf("%d",&q);
	for(int i=1;i<=q;i++){
		int l,r;scanf("%d%d",&l,&r);
		ull ans=0;
		for(int j=l;j<=r;j++){
			int mx1=0,mx2=0;
			for(int k=j;k<=r;k++){
				mx1=std::max(mx1,a[k]);mx2=std::max(mx2,b[k]);
				ans+=(ull)mx1*mx2;
			} 
		}
		std::cout<<ans<<std::endl;
	} 
}
