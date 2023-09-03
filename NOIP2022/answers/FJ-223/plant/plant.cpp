#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int N = 1009;
bool mapp[N][N];
char s[N];
long long sum[N][N],sum2[N][N],sum3[N][N],sum4[N][N],mod=998244353;
int main(){
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	int T,n,m,c,f,i,j,id;
	long long ansc=0,ansf=0;
	scanf("%d%d",&T,&id);
	while(T--){
		ansc=ansf=0;
		memset(sum,0,sizeof(sum));
		memset(sum2,0,sizeof(sum2));
		memset(sum3,0,sizeof(sum3));
		memset(sum4,0,sizeof(sum4));
		scanf("%d%d%d%d",&n,&m,&c,&f);
		for(i=1;i<=n;i++){
			scanf("%s",s);
			for(j=1;j<=m;j++)
				mapp[i][j]=s[j-1]-'0';
		}
		for(i=1;i<=n;i++){
			for(j=m;j>=1;j--){
				if(mapp[i][j]==0)
					sum[i][j]=sum[i][j+1]+1;
				else 
					sum[i][j]=0; 
			}
		}
		for(j=1;j<=m;j++){
			for(i=n;i>=1;i--)
				if(mapp[i][j]==0)
					sum2[i][j]=(sum[i][j]-1+sum2[i+1][j])%mod;
				else 	
					sum2[i][j]=0;
		}
		for(j=1;j<=m;j++)
			for(i=n;i>=1;i--)
				if(mapp[i][j]==0)	
					sum3[i][j]=sum3[i+1][j]+1;
				else
					sum3[i][j]=0;
		for(j=1;j<=m;j++)
			for(i=n;i>=1;i--){
				if(mapp[i][j]==0)
					sum4[i][j]=((sum[i][j]-1)*sum3[i+1][j]%mod+sum4[i+1][j])%mod;
				else
					sum4[i][j]=0;
			}
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				if(sum[i][j]) sum[i][j]--;
		for(i=2;i<=n;i++){
			for(j=1;j<=m;j++){
				if(mapp[i][j]==0)
					ansc=(ansc+sum[i-1][j]*sum2[i+1][j])%mod;
			}
		}
		for(i=2;i<=n;i++)
			for(j=1;j<=m;j++){
				if(mapp[i][j]==0)
					ansf=(ansf+sum[i-1][j]*sum4[i+1][j])%mod;
			} 
		printf("%lld %lld\n",ansc*c,ansf*f);
	}
	return 0;
} 
