#include <bits/stdc++.h>
using namespace std;
const int N=1005;
char c[N][N];
int T,id,n,m;
long long sum[N][N],sum1[N][N],sum2[N][N],f[N][N];
long long cc,ff,ansc,ansf,mod=998244353;
int main()
{
	freopen("plant.in","r",stdin);
	freopen("plant.out","w",stdout);
	cin>>T>>id;
	while(T--){
		ansc=0,ansf=0;
		cin>>n>>m>>cc>>ff; 
		for(int i=1;i<=n;i++){
			scanf("%s",c[i]+1);
			sum[i][m+1]=-1;
			for(int j=m;j>=1;j--){
				if(c[i][j]=='1') sum[i][j]=-1;
				else sum[i][j]=sum[i][j+1]+1;
			}
		}
		for(int j=1;j<=m;j++){
			sum2[n+1][j]=-1;
			for(int i=n;i>=1;i--){
				if(c[i][j]=='1') {
					sum1[i][j]=0,sum2[i][j]=-1,f[i][j]=0;	
				}
				else {
					sum1[i][j]=sum1[i+1][j]+sum[i][j],sum2[i][j]=sum2[i+1][j]+1;
					f[i][j]=(f[i+1][j]+sum[i][j]*sum2[i][j]%mod)%mod;
				}
			}
		}
		for(int i=1;i<=n-2;i++){
			for(int j=1;j<m;j++){
				if(c[i][j]=='0'&&c[i+1][j]=='0'){
//					cout<<"i: "<<i<<"   j: "<<j<<"  "<<sum[i][j]<<" "<<sum1[i+2][j]<<endl;
					ansc=(ansc+sum[i][j]*sum1[i+2][j]%mod)%mod;
					ansf=(ansf+sum[i][j]*f[i+2][j]%mod)%mod;
				}
			}
		}
		for(int i=1;i<=n+1;i++)
			for(int j=1;j<=m+1;j++)
				sum[i][j]=sum1[i][j]=sum2[i][j]=f[i][j]=0;
		ansc=ansc*cc%mod,ansf=ansf*ff%mod;
		printf("%lld %lld\n",ansc,ansf);
	}
	return 0;
}
/*
2 0
4 4 1 1
0000
0000
0010
1100
4 4 1 1
0000
0000
0000
0000
*/
