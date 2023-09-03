#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 998244353
#define div2 499122177
int T,id,n,m;
ll ansc,ansf,rt[1010][1010],dt[1010][1010],inc,inf;
char s[1010][1010];
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&T,&id);
	while(T--){
		ansc=ansf=0;
		scanf("%d%d%lld%lld",&n,&m,&inc,&inf);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
		}
		for(int i=n;i>=1;i--){
			for(int j=m;j>=1;j--){
				if(i==n) dt[i][j]=0;
				else{
					if(s[i+1][j-1]=='1') dt[i][j]=0;
					else dt[i][j]=dt[i+1][j]+1;
				}
				if(j==m) rt[i][j]=0;
				else{
					if(s[i][j+1-1]=='1') rt[i][j]=0;
					else rt[i][j]=rt[i][j+1]+1;
				}
			}
		}
		for(int j=1;j<=m-1;j++){
			ll suma=0;
			for(int i=1;i<=n+1;i++){
				if(i==n+1||s[i][j-1]=='1'){
					suma=0;
				}
				else{
					if(suma!=0){
						ansc+=(suma%mod-rt[i-1][j]%mod+mod)%mod *rt[i][j]%mod;ansc%=mod;
						ansf+=(suma%mod-rt[i-1][j]%mod+mod)%mod *rt[i][j]%mod*dt[i][j]%mod;ansf%=mod;
					}
					suma+=rt[i][j],suma%=mod;
//					cout<<i<<" "<<j<<":"<<ansc<<" "<<ansf<<endl;
				}
			}
		}
		printf("%lld %lld\n",inc*ansc,inf*ansf);
	}
	
	
	return 0;
}
/*
1 0
4 3 1 1
001
010
000
000
*/
