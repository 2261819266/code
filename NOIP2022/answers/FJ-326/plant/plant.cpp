#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<bitset>
#include<cstring>
#define int long long
using namespace std;
const int Mod=99824435,N=1e3+10;
bitset<N> a[N];
int sum[N][N],cnt[N][N],tot[N];
int inv[N];
int ansC,ansF;
int n,m,c,f;
char b;
void init(){
	ansC=ansF=0;
	memset(sum,0,sizeof(sum));
	memset(cnt,0,sizeof(cnt));
	memset(tot,0,sizeof(tot));
}
void work(){
	init();
	scanf("%lld%lld%lld%lld",&n,&m,&c,&f);
	for (int i=1;i<=n;i++) 
		for (int j=1;j<=m;j++) 
			cin>>b,a[i][j]=(b=='1');
	int las=0;
	for (int i=1;i<=n;i++) {
		las=0;
		for (int j=m;j>=1;j--){
			if (a[i][j]) {
				las=0;
				continue;
			}
			sum[i][j]=las+1;
			sum[i][j]%=Mod;
			las=sum[i][j];
		}
	}
	for (int j=1;j<=m;j++) {
		las=0;
		for (int i=n;i>=1;i--){
			if (a[i][j]) {
				las=0;
				continue;
			}
			cnt[i][j]=las+1;
			cnt[i][j]%=Mod;
			las=cnt[i][j];
		}
	}

	for (int j=1;j<=m;j++){
		las=0;
		for (int i=n;i>=1;i--){
			if (a[i][j]) {
				las=0;
				continue;
			}
			tot[i]=Mod+sum[i][j]-1+las;
			tot[i]%=Mod;
			las=tot[i];
			if (!a[i+1][j]) ansC+=((sum[i][j]-1)*tot[i+2])%Mod;
			ansC%=Mod;
		}
	}
	printf("%lld ",(ansC*c)%Mod);
	//workC
	
	for (int j=1;j<=m;j++) {
		las=0;
		for (int i=n;i>=1;i--) {
			if (a[i][j]) {
				las=0;
				continue;
			}
			tot[i]=las+(cnt[i][j]-1)*(sum[i][j]-1);
			tot[i]%=Mod;
			las=tot[i];
			if (!a[i+1][j]) ansF+=(tot[i+2]*(sum[i][j]-1))%Mod;
			ansF%=Mod;
		}
	}
	printf("%lld\n",(ansF*f)%Mod);
	//workF
	return;
}
signed main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,id;
	
//	inv[1]=1;
//	for (int i=2;i<=n;i++)
//		inv[2]=(Mod-(inv[Mod%i]*(Mod/i))%Mod)%Mod;

	scanf("%lld%lld",&T,&id);
	while (T--) work();
	return 0;
}

