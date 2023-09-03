#include<bits/stdc++.h>
using namespace std;
int T,id,n,m,c,f;
long long C,F;
char s[1005][1005];
int tot[1005];
bool chec[1005][1005];
int maxn[1005];
#define Mod 998244353
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		cin>>n>>m>>c>>f;C=F=0;
		for(int i=1;i<=n;i++) cin>>(s[i]+1);
		for(int k=1;k<=m;k++){
			memset(chec,0,sizeof chec);
			memset(maxn,0,sizeof maxn);
			memset(tot,0,sizeof tot);
			for(int i=1;i<=n;i++){
				bool ff=1;
				for(int j=k;j<=m;j++) if(s[i][j]=='1'&&ff) tot[i]=max(j-1-k,0),ff=0;
				if(ff) tot[i]=m-k;
			}
			for(int i=1;i<n;i++){
				bool t=1;
				for(int j=i;j<=n;j++){
					if(s[j][k]=='1'&&t) t=0,chec[i][j]=t,maxn[i]=max(0,j-i-1);
					else chec[i][j]=t;
				}
				if(t) maxn[i]=n-i;
			}maxn[n]=0;
			if(c!=0){
				for(int i=1;i<=n;i++) for(int j=i+2;j<=n;j++) if(chec[i][j]) C=(C+1ll*tot[i]*tot[j])%Mod;
			}
			if(f!=0){
				for(int i=1;i<=n;i++) for(int j=i+2;j<=n;j++) if(chec[i][j]) F=(F+1ll*tot[i]*tot[j]*maxn[j])%Mod;
	 		}
		}
 		printf("%lld %lld\n",C,F);
	}
	return 0;
}

