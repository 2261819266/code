#include<bits/stdc++.h>
using namespace std;
const int N=2.5*1e5;
long long ans=0;
int a[N],b[N];
int main(){
	freopen("match.in","r",stdin);
	freopen("match.out","w",stdout);
	int t,n;
	scanf("%d%d",&t,&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	int qa;
	scanf("%d",&qa);
	while(qa--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int p=l;p<=r;p++){
			for(int q=p;q<=r;q++){
				int m1=a[p],m2=b[p];
				for(int i=p+1;i<=q;i++){
					m1=max(m1,a[i]);
					m2=max(m2,b[i]);
				}
				ans+=m1*m2;
			}
		} 
	}
	printf("%lld",ans);
	return 0;
}
