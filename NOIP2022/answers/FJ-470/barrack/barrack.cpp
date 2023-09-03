#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
int n,ans=1;
int main(){
	freopen("barrack.in","r",stdin);
	freopen("barrack.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)ans=(ans<<1)%mod;
	printf("%d",ans);
	return 0;
}