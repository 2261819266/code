#include<bits/stdc++.h>
using namespace std;
int t,dat,mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	scanf("%d%d",&t,&dat);
	for(int i=1;i<=t;i++){
		int n,m,C,F,sc=0,sf=0;
		char c;
		int a[1010][1010]={0},f[1010][1010][2]={0};
		scanf("%d%d%d%d",&n,&m,&C,&F);
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				cin>>c;
				a[j][k]=c-'0';
			}
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=m;k++){
				if(!a[j][k]){
					int p=k,q=j;
					while(!a[j][p]&&p<=m){
						f[j][k][0]++;
						p++;
					}
					while(!a[q][k]&&q<=n){
						f[j][k][1]++;
						q++;
					}
				}
			}
		}
		for(int j=1;j<=n-2;j++){
			for(int k=1;k<=m-1;k++){
				if(f[j][k][0]>=2&&f[j][k][1]>=3){
					for(int l=2;l<=f[j][k][1];l++){
						if(f[j+l][k][0]>=2)
							sc+=(f[j+l][k][0]-1)*(f[j][k][0]-1);
					}
				}
				if(f[j][k][0]>=2&&f[j][k][1]>=4){
					for(int l=2;l<=f[j][k][1]-1;l++){
						if(f[j+l][k][0]>=2)
							sf+=(f[j+l][k][0]-1)*(f[j][k][0]-1)*(f[j][k][1]-l-1);
					}
				}
			}
		}
		sc%=mod;	sf%=mod;
		sc=(C*sc)%mod;    sf=(F*sf)%mod;
		printf("%d %d\n",sc,sf);
	}
	return 0;
}
