#include<bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
using namespace std;
const int mod=998244353;
int T,id,n,m,c,f,s1[1005][1005],s2[1005][1005];
long long ans1,ans2;
char a[1005][1005];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		scanf("%d%d%d%d",&n,&m,&c,&f);
		rep(i,0,n-1) rep(j,0,m-1){
			cin>>a[i][j];
			if(a[i][j]=='0'){
				s1[i+1][j+1]=1;
				s2[i+1][j+1]=1;
			} 
		}
		per(i,n,1) per(j,m,1){
				if(a[i-1][j-1]=='1') s1[i][j]=s2[i][j]=0;
				else{
					s1[i][j]=(s1[i][j]+s1[i][j+1])%mod;
					s2[i][j]=(s2[i][j]+s2[i+1][j])%mod;
				} 
			}
		rep(i,1,n) rep(j,1,m){
			if(s1[i][j]>=2&&s2[i][j]>=2){
				rep(k,i+2,i+s2[i][j]-1){
					if(s1[k][j]>=2&&s2[k][j]>=2){
						ans1=(ans1+(s1[i][j]-1)*(s1[k][j]-1)%mod)%mod;
						ans2=(ans2+(s1[i][j]-1)*(s1[k][j]-1)*(s2[k][j]-1)%mod)%mod;
					}
					else if(s1[k][j]>=2) ans1=(ans1+(s1[i][j]-1)*(s1[k][j]-1)%mod)%mod;
				}
			}
		}
		if(c==0) ans1=0;
		if(f==0) ans2=0;
		printf("%lld %lld\n",ans1%mod,ans2%mod);
	}
	return 0;
}
