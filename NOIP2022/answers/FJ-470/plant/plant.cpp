#include<bits/stdc++.h>
using namespace std;
#define N 1010
#define int long long
#define mod 998244353
char ch[N][N];
int t,id,n,m,c,f,cnt,ans,pos,a[N][N];
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&id);
	while(t--){cnt=0,pos=0,ans=0;
	scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	for(int i=1;i<=n;i++)scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++,cnt=0)
		for(int j=m;j;j--)
			if(ch[i][j]=='0')a[i][j]=cnt,cnt++;
			else a[i][j]=0,cnt=0;
	for(int j=1;j<=m;j++,cnt=0)
		for(int i=n;i;i--){
			if(ch[i][j]=='0'){
				ans=(ans+a[i][j]*(cnt-a[i+1][j]+mod)%mod)%mod;
				cnt=(cnt+a[i][j])%mod;
			}
			else cnt=0;
		}
	printf("%lld ",c*ans%mod);ans=0;
	for(int j=1;j<=m;j++,cnt=0,pos=0)
		for(int i=n;i;i--){
			if(ch[i][j]=='0'){
				if(pos!=0){
					if(i<pos-1)ans=(ans+a[i][j]*(cnt-a[i+1][j]*(pos-i-1)%mod+mod)%mod)%mod;
					cnt=(cnt+a[i][j]*(pos-i)%mod)%mod;
				}else pos=i;
			}else cnt=0,pos=0;
		}
	printf("%lld\n",f*ans%mod);}
	return 0;
}