#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,m,c,f,t,idd,ansc,ansf;
string s[1005];
bool isk[1005][1005];
int hang[1005][1005],lie[1005][1005],L[1005][1005];
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%lld%lld",&t,&idd);
	while(t--){
		ansc=0,ansf=0;
		memset(isk,0,sizeof(isk));memset(hang,0,sizeof(hang));
		memset(lie,0,sizeof(lie));memset(L,0,sizeof(L));
		scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
		for(int i=1;i<=n;i++) cin>>s[i];
		for(int i=1;i<=n;i++) for(int j=0;j<=m-1;j++){
			if(s[i][j]=='1') isk[i][j+1]=1; else isk[i][j+1]=0; }
		for(int i=1;i<=n;i++) for(int j=m;j>=1;j--){
			if(isk[i][j]) continue;
			hang[i][j]=hang[i][j+1]+1;}
		for(int i=n;i>=1;i--) for(int j=1;j<=m;j++){
			if(isk[i][j]) continue;
			lie[i][j]=lie[i+1][j]+1;}
		for(int i=2;i<=n;i++){
			for(int j=m-1;j>=1;j--){
				if(isk[i][j]||isk[i-1][j]) continue;
				L[i][j]=L[i-1][j]+hang[i-1][j]-1;
			}}
		for(int i=3;i<=n;i++){
			for(int j=1;j<=m-1;j++){
				if(hang[i][j]<2) continue;
				int tsum=1ll*L[i-1][j]*(hang[i][j]-1);
				ansc=(ansc+tsum)%mod;
				ansf=(ansf+tsum*(lie[i][j]-1))%mod;
			}
		}
		printf("%lld %lld\n",c*ansc,f*ansf);
	}
	return 0;
}
